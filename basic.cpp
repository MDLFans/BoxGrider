/*----------------------------------------------------------------------+
|									|
|   Function -								|
|									|
|	MDL example to show creation & use of basic dialog box		|
|									|
|	- - - - - - - - - - - - - - - - - - - - - - - - - - - - -	|
|									|
|   Public Routine Summary -						|
|									|
|	main -                    Main entry point and initialization logic		|
|	basic_dialogHook -        Dialog box hook function			|
|	basic_toggleButtonHook -  Toggle button item hook function	|
|	basic_openModal -         Application command function to open modal dialog box	|
|	    							|
|	basic_errorPrint -        Function to display an error message in messages dialog box	|
|	    						|
|									|
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|									|
|   Include Files   							|
|									|
+----------------------------------------------------------------------*/
#include    <mdl.h>	        /* MDL Library funcs structures & constants */
#include    <dlogitem.h>    /* Dialog Box Manager structures & constants */
#include    <cexpr.h>	    /* C Expression structures & constants */
#include    <cmdlist.h>	    /* MicroStation command numbers */

#include    <dlogman.fdf>   /* dialog box manager function prototypes */
#include    <msrsrc.fdf>
#include    <mssystem.fdf>
#include    <mscexpr.fdf>
#include    <msparse.fdf>

#include    "basic.h"	    /* basic dialog box example constants & structs */
#include    <basiccmd.h>    /* basic dialog box command numbers */

/*----------------------------------------------------------------------+
|									|
|   Utility routines							|
|									|
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|                                                                       |
| name          basic_errorPrint -- print an error message into Dialog	|
|			      Box Manager Messages dialog box		|
|                                                                       |
| author        BSI                                     12/90           |
|                                                                       |
+----------------------------------------------------------------------*/
Private void basic_errorPrint
(
int errorNumber		    /* => number of error to print */
)
{
    char    errorMsg[80];

    if (mdlResource_loadFromStringList (errorMsg, NULL,
		MESSAGELISTID_BasicErrors, errorNumber))
	return;	/* unable to find message with number "errorNumber" */

    mdlDialog_dmsgsPrint (errorMsg);
}


/*----------------------------------------------------------------------+
|									|
|   Private Global variables						|
|									|
+----------------------------------------------------------------------*/
/* The following variable is referenced in C expression strings used by
   the text, option button, and toggle button items defined in basic.r.
   The initial external state of the text item and the option button
   (they are both looking at the same application variable) is 1.  The
   initial external state of the toggle button in the modal dialog box is
   0 (the toggle is "out" or OFF) */
Private BasicGlobals	basicGlobals = {1, 0};

/*----------------------------------------------------------------------+
|                                                                       |
|   Hook Functions							|
|                                                                       |
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|									|
| name		basic_dialogHook					|
|									|
| author	BSI     				12/90		|
|									|
+----------------------------------------------------------------------*/
Private void	basic_dialogHook
(
DialogMessage	*dmP	    /* => a ptr to a dialog message */
)
    {
    /* ignore any messages being sent to modal dialog hook */
    if (dmP->dialogId != DIALOGID_Basic)
	return;

    dmP->msgUnderstood = TRUE;
    switch (dmP->messageType)
	{
	case DIALOG_MESSAGE_DESTROY:
	    {
	    /* unload this mdl task when the Basic Dialog is closed */
	    mdlDialog_cmdNumberQueue (FALSE, CMD_MDL_UNLOAD,
				      mdlSystem_getCurrTaskID(), TRUE);
	    /*  mdlSystem_getCurrTaskID was erroneously omitted from the
		MDL documentation. It returns a character pointer that
		points to the current task's task ID.	*/
	    break;
	    };

	default:
	    dmP->msgUnderstood = FALSE;
	    break;
	}
    }

/*----------------------------------------------------------------------+
|									|
| name		basic_toggleButtonHook					|
|									|
| author	BSI     				12/90		|
|									|
+----------------------------------------------------------------------*/
Private void basic_toggleButtonHook
(
DialogItemMessage   *dimP	/* => a ptr to a dialog item message */
)
    {
    dimP->msgUnderstood = TRUE;

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_CREATE:
	    {
	    basicGlobals.parameter2 = 0;
	    break;
	    }

	default:
	    dimP->msgUnderstood = FALSE;
	    break;
        }
    }

/*----------------------------------------------------------------------+
|                                                                       |
|       Command Handling routines                                       |
|                                                                       |
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|                                                                       |
| name          basic_openModal                                         |
|                                                                       |
| author        BSI                                     12/90           |
|                                                                       |
+----------------------------------------------------------------------*/
Public  void basic_openModal
(
char	*unparsedP	/* => unparsed part of command */
)
//cmdNumber   CMD_OPENMODAL
{
    int	lastAction;

    /* open child modal dialog box */
    if (mdlDialog_openModal (&lastAction, NULL, DIALOGID_BasicModal))
	{
	basic_errorPrint (ERRID_ModalDialog);
	return;
	}

    /* if the user clicked in OK push button, and the toggle button is
       currently "in", then increment parameter1 and update the appearance
       of both the text item and the option button item in the Basic dialog
       box */
    if (lastAction == ACTIONBUTTON_OK && basicGlobals.parameter2)
	{
	basicGlobals.parameter1++;
	if (basicGlobals.parameter1 > 3)
	    basicGlobals.parameter1 = 1;
		mdlDialog_synonymsSynch (NULL, SYNONYMID_Basic, NULL);
	}
}

/*----------------------------------------------------------------------+
|									|
| name		main							|
|									|
| author	BSI     				12/90		|
|									|
+----------------------------------------------------------------------*/
Private DialogHookInfo uHooks[] =
    {
    {HOOKITEMID_ToggleButton_Basic,	(PFDialogHook)basic_toggleButtonHook},
    {HOOKDIALOGID_Basic,		(PFDialogHook)basic_dialogHook},
    };

extern "C" DLLEXPORT  int MdlMain
(
int   argc,		/* => number of args in next array */
char *argv[]		/* => array of cmd line arguments */
)
    {
    SymbolSet	    *setP;	/* a ptr to a "C expression symbol set" */
    RscFileHandle   rscFileH;	/* a resource file handle */
    DialogBox	    *dbP;	/* a ptr to a dialog box */

    /* open the resource file that we came out of */
    mdlResource_openFile (&rscFileH, NULL, 0);

    MdlCommandNumber commandNumbers [] =
        {
        {basic_openModal,CMD_OPENMODAL },
        0
        };
    
    mdlSystem_registerCommandNumbers (commandNumbers);

    /* load the command table */
    if (mdlParse_loadCommandTable (NULL) == NULL)
	basic_errorPrint (ERRID_CommandTable);

    /* set up variables that will be evaluated within C expression strings */
    setP = mdlCExpression_initializeSet (VISIBILITY_DIALOG_BOX, 0, FALSE);
    mdlDialog_publishComplexVariable (setP, "basicglobals",
					    "basicGlobals", &basicGlobals);

    /* publish our hook functions */
    mdlDialog_hookPublish (sizeof(uHooks)/sizeof(DialogHookInfo), uHooks);

    /* open the "Basic" dialog box */
    if ( (dbP = mdlDialog_open (NULL, DIALOGID_Basic)) == NULL)
	basic_errorPrint (ERRID_BasicDialog);

    return SUCCESS;
    }


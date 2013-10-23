/*----------------------------------------------------------------------+
|									|
|   Function -								|
|									|
|	Basic Dialog Example Resources					|
|									|
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|									|
|   Include Files   							|
|									|
+----------------------------------------------------------------------*/
#include <dlogbox.h>	 /* dlog box manager resource constants & structs */
#include <dlogids.h>	 /* MicroStation resource IDs */

#include "basic.h"	     /* basic dialog box example constants & structs */
#include "basiccmd.h"	 /* basic dialog box command numbers */
#include "basictxt.h"	 /* basic dialog box static text defines */

/*----------------------------------------------------------------------+
|									|
|   Basic Dialog Box							|
|									|
+----------------------------------------------------------------------*/
#define X1 (14*XC)		    /* text & option button x position */
#define X2 (7*XC)		    /* push button x position */
#define XW (9*XC)		    /* text & option button width */
#define BTN_WIDTH (12*XC)	/* push button width */

DialogBoxRsc DIALOGID_Basic =
    {
    DIALOGATTR_DEFAULT | DIALOGATTR_SINKABLE,
    50*XC, 25*YC,
    NOHELP, MHELP, HOOKDIALOGID_Basic, NOPARENTID,
    TXT_BasicDialogBox,
		{
		{{X1,GENY(1),XW,0}, Text,	      TEXTID_Basic, ON, 0, "", ""},
		{{X1,GENY(2),XW,0}, OptionButton, OPTIONBUTTONID_Basic, ON, 0, "", ""},
		{{X2,GENY(4),BTN_WIDTH,0}, PushButton, PUSHBUTTONID_OModal, ON, 0,"",""},
		}
    };

#undef X1		/* undef symbols so they can be reused */
#undef X2
#undef XW
#undef BTN_WIDTH

/*----------------------------------------------------------------------+
|									|
|   Modal Sub-Dialog Box						|
|   (opened when PUSHBUTTONID_OModal is activated)			|
|									|
+----------------------------------------------------------------------*/
#define X1 (1*XC)		/* toggle button x position */
#define X2 (3*XC)		/* OK button x position */
#define X3 (14*XC)		/* Cancel button x position */

DialogBoxRsc DIALOGID_BasicModal =
    {
    DIALOGATTR_DEFAULT | DIALOGATTR_MODAL,
    25*XC, 6*YC,
    NOHELP, MHELP, HOOKDIALOGID_Basic, NOPARENTID,
    TXT_BasicModalDialogBox,
		{
		{{X1,GENY(1),0,0},		 ToggleButton, TOGGLEID_Basic, ON, 0, "", ""},
		{{X2,GENY(3),BUTTON_STDWIDTH,0}, PushButton, PUSHBUTTONID_OK,  ON, 0, "", ""},
		{{X3,GENY(3),BUTTON_STDWIDTH,0}, PushButton, PUSHBUTTONID_Cancel, ON,0,"",""},
		}
    };

#undef X1		/* undef symbols so they can be reused */
#undef X2
#undef X3

/*----------------------------------------------------------------------+
|									|
|   Item Resource Specifications					|
|									|
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|									|
|   Text Item Resources							|
|									|
+----------------------------------------------------------------------*/
DItem_TextRsc TEXTID_Basic =
    {
    NOCMD, LCMD, SYNONYMID_Basic, NOHELP, MHELP, NOHOOK, NOARG,
    4, "%ld", "%ld", "1", "3", NOMASK, NOCONCAT,
    TXT_Parameter1,
    "basicGlobals.parameter1"
    };

/*----------------------------------------------------------------------+
|									|
|   Option Button Item Resources					|
|									|
+----------------------------------------------------------------------*/
DItem_OptionButtonRsc  OPTIONBUTTONID_Basic =
    {
    SYNONYMID_Basic, NOHELP, MHELP, NOHOOK, NOARG,
    TXT_Parameter1,
    "basicGlobals.parameter1",
		{
			{NOTYPE, NOICON, NOCMD, LCMD, 1, NOMASK, ON, TXT_Value1},
			{NOTYPE, NOICON, NOCMD, LCMD, 2, NOMASK, ON, TXT_Value2},
			{NOTYPE, NOICON, NOCMD, LCMD, 3, NOMASK, ON, TXT_Value3},
		}
    };

/*----------------------------------------------------------------------+
|									|
|   PushButton Item Resources						|
|									|
+----------------------------------------------------------------------*/
DItem_PushButtonRsc PUSHBUTTONID_OModal =
    {
    NOT_DEFAULT_BUTTON, NOHELP, MHELP, NOHOOK, 0,
    0x01000000, LCMD, "",
    TXT_OpenModal
    };

/*----------------------------------------------------------------------+
|									|
|   Toggle Button Item Resources					|
|									|
+----------------------------------------------------------------------*/
DItem_ToggleButtonRsc TOGGLEID_Basic =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    HOOKITEMID_ToggleButton_Basic, NOARG, NOMASK, NOINVERT,
    TXT_IncrementParameter1,
    "basicGlobals.parameter2"
    };

/*----------------------------------------------------------------------+
|									|
|   Synonym List Resources						|
|									|
+----------------------------------------------------------------------*/
DItem_SynonymsRsc SYNONYMID_Basic =
    {
    	{
			{Text,		TEXTID_Basic},
			{OptionButton,	OPTIONBUTTONID_Basic},
		}
    };


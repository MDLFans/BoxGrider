/*----------------------------------------------------------------------+
|									|
|   Function -								|
|									|
|	Constants & types used in basic dialog example			|
|									|
+----------------------------------------------------------------------*/
#ifndef	    __basicH__
#define	    __basicH__

/*----------------------------------------------------------------------+
|									|
|   Resource ID's							|
|									|
+----------------------------------------------------------------------*/
#define	DIALOGID_Basic		1   /* dialog id for Basic Dialog */
#define DIALOGID_BasicModal	2   /* dialog id for Basic Modal Dialog */

#define OPTIONBUTTONID_Basic	1   /* id for "parameter 1" option button */
#define PUSHBUTTONID_OModal	1   /* id for "Open Modal" push button */
#define	TEXTID_Basic		1   /* id for "parameter 1" text item */
#define TOGGLEID_Basic		1   /* id for "Inc parameter 1?" toggle */

#define SYNONYMID_Basic		1   /* id for synonym resource */

#define MESSAGELISTID_BasicErrors   1	/* id for errors message list */


#define DIALOGID_SingleBoxGriderOneHole 3;

//Controller Point IDS;
#define TOGGLEID_JO1;
#define TOGGLEID_JO2;
#define TOGGLEID_JO3;
#define TOGGLEID_JI1;
#define TOGGLEID_JI2;
#define TOGGLEID_JI3;
#define TOGGLEID_JI4;
#define TOGGLEID_JI5;


/*----------------------------------------------------------------------+
|									|
|   Error Message ID Definitions					|
|									|
+----------------------------------------------------------------------*/
#define	ERRID_CommandTable	1
#define	ERRID_BasicDialog	2
#define	ERRID_ModalDialog	3

/*----------------------------------------------------------------------+
|									|
|   Hook Function ID's							|
|									|
+----------------------------------------------------------------------*/
#define HOOKITEMID_ToggleButton_Basic	1   /* id for toggle item hook func */
#define HOOKDIALOGID_Basic		2   /* id for dialog hook func */

/*----------------------------------------------------------------------+
|									|
|   Typedefs								|
|									|
+----------------------------------------------------------------------*/
typedef struct basicglobals
    {
    int	parameter1;	    /* used by text & option button item */
    int	parameter2;	    /* used by toggle button item */
    } BasicGlobals;

	
typedef struct singleBoxGriderOneHole{
    /*
	*Outer Controll Point
	*/
	int JO1;
	int JO2;
	int JO3;
	/*
	*Inner Controll Point
	*/
	int JI1;
	int JI2;
	int JI3;
	int JI4;
	int JI5;
	/*
	*Outer Height Controll Point
	*/
	float HO1;
	float HO2;
	//JO1 Outer Controll Point
	float HO2_1;
	//JO2 Outer Controll Point
	float HO2_2;
	float HO3;
	//JO3 Outer Controll Point
	float HO3_1;
	/*
	*Inner Height Controll Point
	*/
	float HI1;
	float HI2;
	//JI1 Inner Controll Point
	float HI2_1;
	//JI2 Inner Controll Point
	float HI2_2;
	float HI3;
	//JI3 Inner Controll Point
	float HI3_1;
	float HI4;
	//JI4 Inner Controll Point
	float HI4_1;
	float HI4_2;
	float HI5;
	/*
	*Outer Width Controll Point
	*/
	float BO1;
	//JO1,JO2 Outer Controll Point
	float BO1_1;
	float BO1_2;
	float BO2;
	//JO3 Outer Controll Point
	float BO2_1;
	float BO3;
	
	/*
	*Inner Width Controll Point
	*/
	float BI1;
	//JI1,JI2 Inner Controll Point
	float BI1_1;
	float BI1_2;
	//JI3 Inner Controll Point
	float BI2_1;
	float BI3;
	//JI4,JI5 Inner Controll Point
	float BI3_1;
	float BI3_2;
} SingleBoxGriderOneHole;
#endif

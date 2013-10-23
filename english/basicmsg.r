/*----------------------------------------------------------------------+
|									|
|   Function -								|
|									|
|	Basic application message string resources			|
|									|
+----------------------------------------------------------------------*/
#include <dlogbox.h>	/* dlog box manager resource constants & structs */
#include <dlogids.h>	/* MicroStation resource IDs */

#include "basic.h"	/* basic dialog box example constants & structs */

/*----------------------------------------------------------------------+
|									|
|   Error Messages							|
|									|
+----------------------------------------------------------------------*/
MessageList MESSAGELISTID_BasicErrors =
    {
      {
      {ERRID_CommandTable,  "Unable to load command table."},
      {ERRID_BasicDialog,   "Unable to open Basic dialog box."},
      {ERRID_ModalDialog,   "Unable to open modal dialog box."},
      }
    };

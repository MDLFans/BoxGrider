/*----------------------------------------------------------------------+
|									|
|   Function -								|
|									|
|	"Basic Dialog Example" Command Table Resources			|
|                                                                       |
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|									|
|   Include Files   							|
|									|
+----------------------------------------------------------------------*/
#include <rscdefs.h>
#include <cmdclass.h>

/*----------------------------------------------------------------------+
| 
|  Register Application and DLL
| 
+----------------------------------------------------------------------*/
#define  DLLAPP_BASIC        1

DllMdlApp DLLAPP_BASIC =
    {
    "BASIC", "basic"          // taskid, dllName
    }


/*----------------------------------------------------------------------+
|									|
|  Local Defines							|
|									|
+----------------------------------------------------------------------*/
#define	CT_NONE		 0
#define CT_BASIC	 1

/*----------------------------------------------------------------------+
|                                                                       |
| 	"Basic dialog example" commands					|
|                                                                       |
+----------------------------------------------------------------------*/
Table	CT_BASIC =
{
    {  1, CT_NONE, INPUT, NONE,		"OPENMODAL" },
};
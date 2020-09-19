/*   file pioinit.c  */
  
#pragma title("pioinit.c")

/****************************************************************/
/*  sample parallel port VDD                                    */
/****************************************************************/

#include <mvdm.h>                       /* VDH services, etc.   */
#include "pio.h"                        /* PIO  data defines    */

#pragma BEGIN_INIT_DATA

#pragma END_INIT_DATA

#pragma BEGIN_SWAP_DATA
extern  SZ      szProplpt1timeout;
#pragma END_SWAP_DATA

#pragma BEGIN_INIT_CODE

/* init entry point called by system at load time */

BOOL EXPENTRY PIOInit(psz)         /* PIO VDDInit               */
PSZ psz;                           /* pointer to config string  */
{

    /* Register a VDM termination handler entry point*/

    if ((VDHInstallUserHook((ULONG)VDM_TERMINATE,
                            (PUSERHOOK)PIOTerminate)) == 0)
        return FALSE;        /* return FALSE if VDH call failed */

    /* Register a VDM creation handler entry point */

    if ((VDHInstallUserHook((ULONG)VDM_CREATE,
                            (PUSERHOOK)PIOCreate)) == 0)
        return FALSE;        /* return FALSE if VDH call failed */

    /* Get the entry point to the PDD */

    PPIOPDDProc = VDHOpenPDD(PDD_NAME, PIO_PDDProc);

    return TRUE;
}

/* entry point registered by VDHOpenPDD, called by the PDD            */

SBOOL VDDENTRY PIO_PDDProc(ulFunc,f16p1,f16p2)
ULONG ulFunc;
F16PVOID f16p1;
F16PVOID f16p2;
{
    return TRUE;
}

#pragma END_INIT_CODE

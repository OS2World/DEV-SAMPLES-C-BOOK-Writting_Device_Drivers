/*  file piouser.c */

#pragma title("piouser.c")

#include <mvdm.h>                       /* VDH services, etc.   */
#include "pio.h"                        /* PIO specific         */

#pragma BEGIN_SWAP_DATA
#pragma END_SWAP_DATA

#pragma BEGIN_SWAP_CODE

/*----------------------------------------------------------------

PIOCreate, entered when the VDM is created 

----------------------------------------------------------------*/

BOOL HOOKENTRY PIOCreate(hvdm)
HVDM hvdm;
{
    this_VDM = hvdm;

    /* install I/O hooks for our ports */

    if ((VDHInstallIOHook(hvdm,
                          DIGIO_OUTPUT,
                          1,
                          (PIOH)PIODataOut,
                          !VDH_ASM_HOOK)) == 0) {
        PIOTerminate(hvdm);
        return FALSE;             /* return FALSE               */
    } /* endif */
    if ((VDHInstallIOHook(hvdm,
                          DIGIO_INPUT,
                          1,
                          (PIOH)PIODataIn,
                          !VDH_ASM_HOOK)) == 0) {
        PIOTerminate(hvdm);
        return FALSE;             /* return FALSE               */
    } /* endif */
    if ((VDHInstallIOHook(hvdm,
                          DIGIO_CONFIG,
                          1,
                          (PIOH)PIOConfigOut,
                          !VDH_ASM_HOOK)) == 0) {
        PIOTerminate(hvdm);
        return FALSE;             /* return FALSE               */
    } /* endif */

    return TRUE;
}

/*----------------------------------------------------------------
 
PIOTerminate, called when the VDM terminates. This code is 
optional, as the User and IO hooks are removed automatically by 
the system when the VDM terminates. It is shown for example.

----------------------------------------------------------------*/

BOOL HOOKENTRY PIOTerminate(hvdm)
HVDM hvdm;
{
    VDHRemoveIOHook(hvdm,         /* remove the IO hooks        */
                    DIGIO_INPUT,
                    1,
                    (PIOH)PIODataIn);

    VDHRemoveIOHook(hvdm,
                    DIGIO_OUTPUT,
                    1,
                    (PIOH)PIODataOut);

    VDHRemoveIOHook(hvdm,
                    DIGIO_CONFIG,
                    1,
                    (PIOH)PIOConfigOut);

    return TRUE;
}

#pragma END_SWAP_CODE


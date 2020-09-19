/* piodata.c */

#pragma title("piodata.c")

#include <mvdm.h>                       /* VDH services, etc.   */
#include "pio.h"                        /* PIO specific         */

#pragma BEGIN_SWAP_INSTANCE

HVDM this_VDM;                          /*  actual VDM handle   */

#pragma END_SWAP_INSTANCE

#pragma BEGIN_SWAP_DATA

FPFNPDD PPIOPDDProc = (FPFNPDD)0;       /* addr of PDD entry pt */

#pragma END_SWAP_DATA

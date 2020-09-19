/* pioout.c	*/

#pragma title("piocout.c")

#include <mvdm.h>                       /* VDH services, etc.   */
#include "pio.h"                        /* PIO specific         */

#pragma BEGIN_SWAP_CODE

/* trap entry point for output to config port */

VOID HOOKENTRY PIOConfigOut(chartowrite, portaddr, pcrf)
BYTE chartowrite;
ULONG portaddr;
PCRF pcrf;
{

    OUTB(portaddr,chartowrite);
    return;

}

#pragma END_SWAP_CODE

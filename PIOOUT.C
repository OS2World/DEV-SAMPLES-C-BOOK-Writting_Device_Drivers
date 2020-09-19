/* pioout.c	*/

#pragma title("pioout.c")

#include <mvdm.h>                       /* VDH services, etc.   */
#include "pio.h"                        /* PIO specific         */

#pragma BEGIN_SWAP_CODE

/* this routine is the data out trap entry point */

VOID HOOKENTRY PIODataOut(chartowrite, portaddr, pcrf)
BYTE chartowrite;
ULONG portaddr;
PCRF pcrf;
{

    OUTB(portaddr,chartowrite);         /* write the char      */
    return;

}

#pragma END_SWAP_CODE

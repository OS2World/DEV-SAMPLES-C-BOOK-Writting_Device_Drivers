/*  pioin.c */

#pragma title("pioin.c")

#include <mvdm.h>                       /* VDH services, etc.   */
#include "pio.h"                        /* PIO specific         */

#pragma BEGIN_SWAP_CODE

/* entry from data input trap in VDM */

BYTE HOOKENTRY PIODataIn(portaddr, pcrf)
ULONG portaddr;
PCRF pcrf;
{

    BYTE dataread;                     /* set up byte to return */

    dataread = INB(portaddr);
    return(dataread);                  /* return data read      */
}

#pragma END_SWAP_CODE

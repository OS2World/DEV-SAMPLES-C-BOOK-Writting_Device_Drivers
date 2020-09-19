/*
 digio memory map for os/2 virtual device driver
*/

#define  DIGIO_BASE   0x2c0        /* board address                */
#define  DIGIO_OUTPUT DIGIO_BASE   /* output port                  */
#define  DIGIO_INPUT  DIGIO_BASE+1 /* input port                   */
#define  DIGIO_CONFIG DIGIO_BASE+3 /* initialization port          */

/* name of the PDD */
                                                           
#define PDD_NAME      "DIGIO$  \0"  /* string                      */

/* pioinit.c */

BOOL EXPENTRY PIOInit(PSZ);
SBOOL VDDENTRY PIO_PDDProc(ULONG,F16PVOID,F16PVOID);

/* piouser.c */

BOOL HOOKENTRY PIOCreate(HVDM);
BOOL HOOKENTRY PIOTerminate(HVDM);

/* pioin.c */

BYTE HOOKENTRY PIODataIn(ULONG, PCRF);

/* pioout.c */

VOID HOOKENTRY PIODataOut(BYTE, ULONG, PCRF);
VOID HOOKENTRY PIOConfigOut(BYTE, ULONG, PCRF);

extern ULONG MachineType;                       /* Machine Type            */
extern FPFNPDD PPIOPDDProc;                     /* addr of PDD entry point */
extern HVDM this_VDM;

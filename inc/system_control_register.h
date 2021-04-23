#include "bits.h"

typedef struct{
    int pad_arr0[80];
    int EXTINT; //External Interrupt Flag Register R/W 0 0x400F C140
    int pad0;
    int EXTMODE; //External Interrupt Mode register R/W 0 0x400F C148
    int EXTPOLAR; //External Interrupt Polarity Register R/W 0 0x400F C14C
    int pad_arr1[52];;
    int RSID; //Reset Source Identification Register R/W 0x400F C180
    int pad_arr2[32];
    int SCS //System Control and Status R/W 0 0x400F C1A0
}System_control_reg;

#define EXTINT_EINT0 BIT0
#define EXTINT_EINT1 BIT1
#define EXTINT_EINT2 BIT2
#define EXTINT_EINT3 BIT3

#define EXTMODE_EXTMODE0 BIT0
#define EXTMODE_EXTMODE1 BIT1
#define EXTMODE_EXTMODE2 BIT2
#define EXTMODE_EXTMODE3 BIT3

#define EXTPOLAR_EXTPOLAR0 BIT0
#define EXTPOLAR_EXTPOLAR1 BIT1
#define EXTPOLAR_EXTPOLAR2 BIT2
#define EXTPOLAR_EXTPOLAR3 BIT3

#define RSID_POR  BIT0
#define RSID_EXTR BIT1
#define RSID_WDTR BIT2
#define RSID_BODR BIT3
#define RSID_SYSRESET BIT4
#define RSID_LOCKUP BIT5

#define SCS_OSCRANGE BIT4
#define SCS_OSCEN BIT5
#define SCS_OSCSTAT BIT6
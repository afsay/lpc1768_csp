#include "bits.h"

typedef struct {
    unsigned int pad_arr0[80];
    volatile unsigned int EXTINT; //External Interrupt Flag Register R/W 0 0x400F C140
    volatile unsigned int pad0;
    volatile unsigned int EXTMODE; //External Interrupt Mode register R/W 0 0x400F C148
    volatile unsigned int EXTPOLAR; //External Interrupt Polarity Register R/W 0 0x400F C14C
    unsigned int pad_arr1[52];;
    volatile unsigned int RSID; //Reset Source Identification Register R/W 0x400F C180
    unsigned int pad_arr2[32];
    volatile unsigned int SCS; //System Control and Status R/W 0 0x400F C1A0
} System_control_REG;

typedef enum OSCRANGE {MHz_1_to_20 = 0, MHz_15_to_25 = 1} OSCRANGE;

#define EXTINT_EINT0_MASK BIT0
#define EXTINT_EINT1_MASK BIT1
#define EXTINT_EINT2_MASK BIT2
#define EXTINT_EINT3_MASK BIT3

#define EXTMODE_EXTMODE0_MASK BIT0
#define EXTMODE_EXTMODE1_MASK BIT1
#define EXTMODE_EXTMODE2_MASK BIT2
#define EXTMODE_EXTMODE3_MASK BIT3

#define EXTPOLAR_EXTPOLAR0_MASK BIT0
#define EXTPOLAR_EXTPOLAR1_MASK BIT1
#define EXTPOLAR_EXTPOLAR2_MASK BIT2
#define EXTPOLAR_EXTPOLAR3_MASK BIT3

#define RSID_POR_MASK  BIT0
#define RSID_EXTR_MASK BIT1
#define RSID_WDTR_MASK BIT2
#define RSID_BODR_MASK BIT3
#define RSID_SYSRESET_MASK BIT4
#define RSID_LOCKUP_MASK BIT5

#define SCS_OSCRANGE_MASK BIT4
#define SCS_OSCEN_MASK BIT5
#define SCS_OSCSTAT_MASK BIT6

#define SCS_OSCRANGE_BIT_INDEX 4
#define SCS_OSCEN_BIT_INDEX 5
#define SCS_OSCSTAT_BIT_INDEX 6
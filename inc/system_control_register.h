#include "bits.h"

typedef struct {
    volatile unsigned int FLASHCFG; //Flash Accelerator Configuration Register. Controls flash access timing. See Table 49. R/W 0x303A 0x400F C000
    unsigned int pad_arr0[15];
    volatile unsigned int MEMMAP; //Memory Mapping Control register R/W 0 0x400F C040
    unsigned int pad_arr1[15];
    volatile unsigned int PLL0CON; //PLL0 Control Register R/W 0 0x400F C080
    volatile unsigned int PLL0CFG; //PLL0 Configuration Register R/W 0 0x400F C084
    volatile unsigned int PLL0STAT; //PLL0 Status Register RO 0 0x400F C088
    volatile unsigned int PLL0FEED; //PLL0 Feed Register WO NA 0x400F C08C
    unsigned int pad_arr2[4];
    volatile unsigned int PLL1CON; //PLL1 Control Register R/W 0 0x400F C0A0
    volatile unsigned int PLL1CFG; //PLL1 Configuration Register R/W 0 0x400F C0A4
    volatile unsigned int PLL1STAT; //PLL1 Status Register RO 0 0x400F C0A8
    volatile unsigned int PLL1FEED; //PLL1 Feed Register WO NA 0x400F C0AC
    unsigned int pad_arr3[4];
    volatile unsigned int PCON; //Power Control Register R/W 0 0x400F C0C0
    volatile unsigned int PCONP; //Power Control for Peripherals Register R/W 0x03BE 0x400F C0C4
    unsigned int pad_arr4[15];
    volatile unsigned int CLKCFG; //CPU Clock Configuration Register R/W 0 0x400F C104
    volatile unsigned int USBCLKCFG; //USB Clock Configuration Register R/W 0 0x400F C108
    volatile unsigned int CLKSRCSEL; //Clock Source Select Register R/W 0 0x400F C10C
    volatile unsigned int CANSLEEPCLR; //Allows clearing the current CAN channel sleep state as well as R/W reading that state. R/W 0 0x400F C110
    volatile unsigned int CANWAKEFLAGS; //Allows reading the wake-up state of the CAN channels. R/W 0 0x400F C114
    unsigned int pad_arr5[10];
    volatile unsigned int EXTINT; //External Interrupt Flag Register R/W 0 0x400F C140
    volatile unsigned int pad0;
    volatile unsigned int EXTMODE; //External Interrupt Mode register R/W 0 0x400F C148
    volatile unsigned int EXTPOLAR; //External Interrupt Polarity Register R/W 0 0x400F C14C
    unsigned int pad_arr6[12];;
    volatile unsigned int RSID; //Reset Source Identification Register R/W 0x400F C180
    unsigned int pad_arr7[7];
    volatile unsigned int SCS; //System Control and Status R/W 0 0x400F C1A0
    unsigned int pad_1;
    volatile unsigned int PCLKSEL0; //Peripheral Clock Selection register 0. R/W 0 0x400F C1A8
    volatile unsigned int PCLKSEL1; //Peripheral Clock Selection register 1. R/W 0 0x400F C1AC
    unsigned int pad_arr8[4];
    volatile unsigned int USBIntSt; //USB Interrupt Status R/W 0x8000 0000 0x400F C1C0
    volatile unsigned int DMAREQSEL; //Selects between UART and timer DMA requests on channels 8 through 15 R/W 0 0x400F C1C4
    volatile unsigned int CLKOUTCFG;//Clock Output Configuration Register R/W 0 0x400F C1C8
} System_control_REG; //System_control_BASE	0x400FC000

typedef enum OSCRANGE {MHz_1_to_20 = 0, MHz_15_to_25 = 1} OSCRANGE;
typedef enum PLL0SOURCE {SELECT_IRC = 0x0, SELECT_MAIN_OSC = 0x1, SELECT_RTC = 0x2} PLL0SOURCE;

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

#define PLL0_ENABLE_MASK BIT0
#define PLL0_ENABLED_MASK BIT24
#define PLL0_CONNECT_MASK BIT1
#define PLL0_CONNECTED_MASK BIT25
#define PLL0_LOCKED_MASK BIT26

#define PLL0FEED_1 0x000000AA
#define PLL0FEED_2 0x00000055

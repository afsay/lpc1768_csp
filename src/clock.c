#include <stdbool.h>

#include "peripherals_address_map.h"

/*
    4-OSCRANGE
        0 The frequency range of the main oscillator is 1 MHz to 20 MHz.
        1 The frequency range of the main oscillator is 15 MHz to 25 MHz.
*/
void main_oscillator_range_select(OSCRANGE oscrange){
    if (oscrange == MHz_1_to_20) SYSCTL->SCS &= ~SCS_OSCRANGE_MASK;
    else SYSCTL->SCS |= SCS_OSCRANGE_MASK;
}

/*
    5-OSCEN
        0 The main oscillator is disabled.
        1 The main oscillator is enabled, and will start up if
            the correct external circuitry is connected to the
            XTAL1 and XTAL2 pins.
*/
void main_oscillator_enable(bool enable){
    if(enable) SYSCTL->SCS |= SCS_OSCEN_MASK;
    else SYSCTL->SCS &= ~SCS_OSCEN_MASK;
}

bool is_main_oscillator_enabled(void){
    return (SYSCTL->SCS & SCS_OSCEN_MASK)?true:false;
}

/*
    6-OCSSTAT
        0 The main oscillator is not ready to be used as a clock source.
        1 The main oscillator is ready to be used as a clock
            source. The main oscillator must be enabled via the
            OSCEN bit.
*/
bool is_main_oscillator_ready(void){
    return (SYSCTL->SCS & SCS_OSCSTAT_MASK)?true:false;
}

/*
    CLKSRC
    00 Selects the Internal RC oscillator as the PLL0 clock source (default).
    01 Selects the main oscillator as the PLL0 clock source.
    10 Selects the RTC oscillator as the PLL0 clock source.
*/
void select_PLL0_source(PLL0SOURCE pll0_source){
    SYSCTL->CLKSRCSEL = pll0_source;
}

/*
    PLL0 Enable.
    When one, and after a valid PLL0 feed, this bit will activate 0
    PLL0 and allow it to lock to the requested frequency. See PLL0STAT register
*/
void enable_PLL0(bool enable){
    if(enable) SYSCTL->PLL0CON |= PLL0_ENABLE_MASK;
    else SYSCTL->PLL0CON &= ~PLL0_ENABLE_MASK;
}

/*
    24-PLLE0_STAT
        Read-back for the PLL0 Enable bit. This bit reflects the state of the
        PLEC0 bit in PLL0CON (see Table 19) after a valid PLL0 feed.
        When one, PLL0 is currently enabled. When zero, PLL0 is turned
        off. This bit is automatically cleared when Power-down mode is
        entered.
*/
bool is_enabled_PLL0(void){
    return (SYSCTL->PLL0STAT & PLL0_ENABLED_MASK)?true:false; 
}

/*
    25-PLLC0_STAT
        Read-back for the PLL0 Connect bit. This bit reflects the state of
        the PLLC0 bit in PLL0CON (see Table 19) after a valid PLL0 feed.
        When PLLC0 and PLLE0 are both one, PLL0 is connected as the
        clock source for the CPU. When either PLLC0 or PLLE0 is zero,
        PLL0 is bypassed. This bit is automatically cleared when
        Power-down mode is entered.
*/
bool is_connected_PLL0(void){
    return (SYSCTL->PLL0STAT & PLL0_CONNECTED_MASK)?true:false; 
}

/**
    PLL0 Connect.
    Setting PLLC0 to one after PLL0 has been enabled and
    locked, then followed by a valid PLL0 feed sequence causes PLL0 to
    become the clock source for the CPU, AHB peripherals, and used to
    derive the clocks for APB peripherals. The PLL0 output may potentially
    be used to clock the USB subsystem if the frequency is 48 MHz.
    See PLL0STAT register
 */
void connect_PLL0(bool connect){
    if(connect) SYSCTL->PLL0CON |= PLL0_CONNECT_MASK;
    else SYSCTL->PLL0CON &= ~PLL0_CONNECT_MASK;
}

/*
    14:0-MSEL0
        PLL0 Multiplier value. Supplies the value "M" in PLL0 frequency
        calculations. The value stored here is M - 1. Supported values for M
        are 6 through 512

    23:16-NSEL0
        PLL0 Pre-Divider value. Supplies the value "N" in PLL0 frequency
        calculations. The value stored here is N - 1. Supported values for N are
        1 through 32.
 */
void configure_multiplier_and_predivider_PLL0(unsigned int MSEL0, unsigned int NSEL0){
    SYSCTL->PLL0CFG = (0x00007FFF & MSEL0) | ((0x000000FF & NSEL0) << 16);
}

/*
    14:0 MSEL0
            Read-back for the PLL0 Multiplier value. This is the value currently
            used by PLL0, and is one less than the actual multiplier
*/
unsigned int multipler_value_PLL0(void){
    return SYSCTL->PLL0STAT & 0x00007FFF;
}

/*
    23:16 NSEL0
        Read-back for the PLL0 Pre-Divider value. This is the value
        currently used by PLL0, and is one less than the actual divider.
*/
unsigned int predivider_value_PLL0(void){
    return ((SYSCTL->PLL0STAT)>>16) & 0x000000FF;
}

/*
    26 PLOCK0
        Reflects the PLL0 Lock status. When zero, PLL0 is not locked.
        When one, PLL0 is locked onto the requested frequency. See text
        for details.
*/
bool is_locked_PLL0(void){
    return (SYSCTL->PLL0STAT & PLL0_LOCKED_MASK)?true:false; 
}
/*
    7:0 PLL0FEED 
        The PLL0 feed sequence must be written to this register in order for
        PLL0 configuration and control register changes to take effect

        The two writes must be in the correct sequence, and there must be no other register access in the same address space (0x400F C000 to 0x400F FFFF) between them.
        Because of this, it may be necessary to disable interrupts for the duration of the PLL0 feed operation, if there is a possibility that an interrupt service routine could write to another
        register in that space. If either of the feed values is incorrect, or one of the previously mentioned conditions is not met, any changes to the PLL0CON or PLL0CFG register will
        not become effective.
*/
void feed_sequence_PLL0(void){
    SYSCTL->PLL0FEED = PLL0FEED_1;
    SYSCTL->PLL0FEED = PLL0FEED_2;
}

/*
    7:0 CCLKSEL
        Selects the divide value for creating the CPU clock (CCLK)
        from the PLL0 output.
*/
void set_clock_divide(unsigned int value){
    SYSCTL->CCLKCFG = value & 0x000000FF;
}

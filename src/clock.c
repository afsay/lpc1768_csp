#include "peripherals_address_map.h"

void main_oscillator_range_select(OSCRANGE oscrange){
    if (oscrange == MHz_1_to_20){
        SYSCTL->SCS &= ~SCS_OSCRANGE_MASK;
    }else{
        SYSCTL->SCS |= SCS_OSCRANGE_MASK; 
    }
}

void main_oscillator_enable(void){
    SYSCTL->SCS |= SCS_OSCEN_MASK;
}

void main_oscillator_disable(void){
    SYSCTL->SCS &= ~SCS_OSCEN_MASK;
}

_Bool is_main_oscillator_enabled(void){
    return (_Bool)(SYSCTL->SCS & SCS_OSCEN_MASK);
}

_Bool is_main_oscillator_ready(void){
    return (_Bool)(SYSCTL->SCS & SCS_OSCSTAT_MASK);
}
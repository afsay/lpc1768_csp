#include "clock.h"
#include <stdbool.h>
int main(void){
    if(!is_main_oscillator_enabled()){
        main_oscillator_range_select(MHz_15_to_25);
        main_oscillator_enable();
        while (!is_main_oscillator_ready())
        {
            ;;
        }
        main_oscillator_disable();        
    }

    return 0;
}

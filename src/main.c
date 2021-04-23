#include "clock.h"

int main(void){
    if(!is_main_oscillator_enabled()){
        main_oscillator_enable();
        while (!is_main_oscillator_ready())
        {
            ;;
        }
        
    }
    return 0;
}

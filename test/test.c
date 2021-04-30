#include "clock.h"
#include <stdbool.h>
extern void _stackTop(void);

void main(void);
void nmi_handler(void);
void hardfault_handler(void);
//Define the vector table
__attribute__ ((section(".vectors")))
void (* const VectorArray[])(void) = {
  &_stackTop,
  main,
  nmi_handler,
  hardfault_handler,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //if these zeros are not places, linker will add main() in interrupt vector space
};

void main(void){
    if(!is_main_oscillator_enabled()){
        main_oscillator_range_select(MHz_15_to_25);
        main_oscillator_enable(true);
        while (!is_main_oscillator_ready())
        {
            ;;
        }
        main_oscillator_enable(false);        
    }
}

//Dummy handlers
void nmi_handler(void)
{
  while(1);
  return;
}

void hardfault_handler(void)
{
  while(1);
  return;
}

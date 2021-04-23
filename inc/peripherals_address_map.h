#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "system_control_register.h"

#define Watchdog_Timer_BASE 0x40000000
#define Timer_0_BASE	0x40004000
#define Timer_1_BASE	0x40008000
#define UART0_BASE	0x4000C000
#define UART1_BASE	0x40010000
#define PWM1_BASE	0x40018000
#define I2C0_BASE	0x4001C000
#define SPI_BASE	0x40020000
#define RTC_BASE	0x40024000
#define GPIO_interrupts_BASE 0x40028000
#define Pin_Connect_Block_BASE	0x4002C000
#define SSP1_BASE	0x40030000
#define ADC_BASE	0x40034000
#define CAN_Acceptance_Filter_RAM_BASE	0x40038000
#define CAN_Acceptance_Filter_Registers_BASE	0x4003C000
#define CAN_Common_Registers_BASE	0x40040000
#define CAN_Controller_1_BASE	0x40044000
#define CAN_Controller_2_BASE	0x40048000
#define I2C1_BASE	0x4005C000
#define SSP0_BASE	0x40088000
#define DAC_BASE	0x4008C000
#define Timer_2_BASE	0x40090000
#define Timer_3_BASE	0x40094000
#define UART2_BASE	0x40098000
#define UART3_BASE	0x4009C000
#define I2C2_BASE	0x400A0000
#define I2S_BASE	0x400A8000
#define Repetitive_interrupt_timer_BASE	0x400B0000
#define Motor_control_PWM_BASE	0x400B8000
#define Quadrature_Encoder_Interface_BASE	0x400BC000
#define System_control_BASE	0x400FC000

#define SYSCTL ((System_control_REG *)System_control_BASE)

#endif

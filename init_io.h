#ifndef INIT_IO_
#define INIT_IO_
#include <stdint.h>

#define PIN 0 // LED connected to P0.0
// #define SWITCH_PIN 0 // Switch connected to P1.0
#define LOW 0
#define PRESSED LOW
// Register Definitions for Port 0
#define GPIO_PORT0_PC ((volatile uint32_t *)0x40040008) // Port 0 configuration register
#define GPIO_PORT0_DR ((volatile uint32_t *)0x40040000) // Port 0 output data register

// Register Definitions for Port 1
#define GPIO_PORT1_PC ((volatile uint32_t *)0x40040108) // Port 1 configuration register
#define GPIO_PORT1_DR ((volatile uint32_t *)0x40040100) // Port 1 output data register
#define GPIO_PORT1_PS ((volatile uint32_t *)0x40040104) // Port 1 pin status register
void init_LED_and_Switch(void);
void toggle_LED_on_SwitchPress(void);
#endif
#include "init_io.h"
void init_LED_and_Switch(void)
{
    // PC: Set P0.0 to Strong Drive mode (6)
    *GPIO_PORT0_PC &= ~(0x07 << (PIN * 3));
    *GPIO_PORT0_PC |= (0x06 << (PIN * 3)); 
    *GPIO_PORT0_DR |= (1 << PIN);// Turn off LED initially
    // PC: Set P1.0 to resistive pull up mode (2)
    *GPIO_PORT1_PC &= ~(0x07 << (PIN * 3));
    *GPIO_PORT1_PC |= (0x02 << (PIN * 3)); 
    *GPIO_PORT1_DR |= (1 << PIN); // Set P1.0 high
}
void toggle_LED_on_SwitchPress(void)
{
    if(((*GPIO_PORT1_PS) & (1 << PIN)) == PRESSED) // Check if switch is pressed (active low)
    {
        // Debounce delay
        for(volatile int i = 0; i < 10000; i++);
        
        // Toggle LED state
        *GPIO_PORT0_DR ^= (1 << PIN);
        
        // Wait until switch is released
        while(((*GPIO_PORT1_PS) & (1 << PIN)) == PRESSED);
        
        // Debounce delay
        for(volatile int i = 0; i < 10000; i++);
    }
}

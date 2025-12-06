#include "init_io.h"
int main(void)
{
    init_LED_and_Switch();
    while (1)
    {
        toggle_LED_on_SwitchPress();
    }
}

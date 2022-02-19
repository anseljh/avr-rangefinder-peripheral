/*

ATtiny4313
https://www.microchip.com/en-us/product/ATtiny4313

Pinout:

                     +-------+
                    -|1    20|- VCC -->
  (Tip) RXD <-- PD0 -|2    19|- PB7 --> SCL  TODO: Pull-up resistor?
 (Ring) TXD <-- PD1 -|3    18|- PB6
                    -|4    17|- PB5 --> SDA  TODO: Pull-up resistor?
                    -|5    16|- PB4
                    -|6    15|- PB3
                    -|7    14|- PB2 --> TRIG
                    -|8    13|- PB1 --> ECHO
                    -|9    12|- PB0 --> LED
            <-- GND -|10   11|- PD6
                     +-------+

*/

#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>

#include "pinDefines.h"
#include "macros.h"
#include "USART.h"

#define BLINK_ON_TIME   100
#define BLINK_OFF_TIME  400

// Rangefinder stuff
// Ping lasts 10 us
#define RANGE_PING_US    10


// TODO: Interrupt routine for echo


int main(void)
{
    // Init ////////////////////////////////////////

    // Zero the data-direction registers
    LED_DDR = 0;
    I2C_SDA_DDR = 0;
    I2C_SCL_DDR = 0;
    UART_DDR = 0;
    RANGE_DDR = 0;

    // Set outputs
    LED_DDR |= (1 << LED1);
    I2C_SCL_DDR |= (1 << I2C_SCL);
    I2C_SDA_DDR |= (1 << I2C_SDA);
    UART_DDR |= (1 << UART_TXD);
    UART_DDR |= (1 << UART_RXD);
    RANGE_DDR |= (1 << RANGE_TRIG);

    // Initialize USART
    initUSART();

    // Loop ////////////////////////////////////////

    _delay_ms(500);
    printString("Hello from rangefinder.c!\r\n");
    while (1)
    {
        // Blink LED
        set_bit(LED_PORT, LED1);
        _delay_ms(BLINK_ON_TIME);
        clear_bit(LED_PORT, LED1);
        _delay_ms(BLINK_OFF_TIME);

        // Send ping
        set_bit(LED_PORT, LED1);
        set_bit(RANGE_PORT, RANGE_TRIG);
        _delay_us(RANGE_PING_US);
        clear_bit(RANGE_PORT, RANGE_TRIG);
        clear_bit(LED_PORT, LED1);

        // Write to serial
        printString("Ping!\r\n");
    }
    return(0); // Never reached
}

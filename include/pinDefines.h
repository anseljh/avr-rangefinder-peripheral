// ---------------
//   Pin Defines
// ---------------

// LED

#define LED_PORT                PORTB
#define LED_PIN                 PINB
#define LED_DDR                 DDRB
#define LED1                    PB0

//  I2C serial mode defines

#define I2C_SDA                     PB5
#define I2C_SDA_PORT                PORTB
#define I2C_SDA_PIN                 PINB
#define I2C_SDA_DDR                 DDRB

#define I2C_SCL                     PB7
#define I2C_SCL_PORT                PORTB
#define I2C_SCL_PIN                 PINB
#define I2C_SCL_DDR                 DDRB

// UART

#define UART_PORT                   PORTD
#define UART_PIN                    PIND
#define UART_DDR                    DDRD
#define UART_RXD                    PD0
#define UART_TXD                    PD1

// Ultrasonic rangefinder

#define RANGE_PORT                  PORTB
#define RANGE_PIN                   PINB
#define RANGE_DDR                   DDRB
#define RANGE_ECHO                  PB1
#define RANGE_TRIG                  PB2

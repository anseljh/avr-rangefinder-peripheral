# avr-rangefinder-peripheral

Convert a [HC-SR04](https://www.adafruit.com/product/3942) or [compatible](https://www.adafruit.com/product/4007) ultrasonic rangefinder into an easy-to-use I2C perhipheral using an [ATtiny4313 microcontroller](https://www.microchip.com/en-us/product/ATtiny4313) for the I2C target[^1] device.

Also provides a serial connection via 3.5mm audio jack for debugging, via the ATtiny4313's USART.

## To Do

- [ ] Get LED blinking
- [ ] Get USART working for serial console debug output
- [ ] Get rangefinder sending pulse
- [ ] Receive echo
- [ ] Compute distance
- [ ] Output distance to serial console
- [ ] Get I2C working in target mode

[^1]: Language note on "controller" and "target": https://community.nxp.com/t5/Other-NXP-Products/Alternative-inclusive-terms-for-master-and-slave-in-I2S-I2C/td-p/1244999
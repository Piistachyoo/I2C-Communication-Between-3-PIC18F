# I2C-Communication-Between-3-PIC18F
## Description:
#### This project was done on MPLabX using the XC compiler and simulation is done on Proteus.

#### Master MCU sends an I2C message every 1 seconds.

#### First, Master MCU sends 'A' on the bus with Slave 1 address so Slave 1 MCU turns the led on.
#### Second, Master MCU sends 'B' on the bus with Slave 2 address so Slave 2 MCU turns the led on.
#### Third, Master MCU sends 'C' on the bus with Slave 1 address so Slave 1 turns the LED off.
#### Forth, Master MCU sends 'D' on the bus with Slave 2 address so Slave 2 turns the LED off.
#### Then the system loops.

#### Master MCU is sending data using polling to make sure there is no data collision happening.
#### Also, the 2 slave MCUs interrupts are on, so when a message is received, an interrupt is generated.
#### Inside the ISR the slave MCU is stretching the clock to read the data buffer register to avoid data collision and releasing the clock after.
## Project design:
![Project design](https://github.com/Piistachyoo/I2C-Communication-Between-3-PIC18F/blob/main/Project%20design%20screenshot.png?raw=true)

## Real-time simulation:
[I2C Communication Between 3 PIC18F (Proteus Simulation) - YouTube](https://www.youtube.com/watch?v=jmDqVv1Oj8w)
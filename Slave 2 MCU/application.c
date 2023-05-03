/* 
 * File:   application.c
 * Author: Omar Yamany
 *
 * Created on March 6, 2023, 2:10 AM
 */

#include "MCAL_Layer/I2C/hal_i2c.h"
#include "ECU_Layer/LED/ecu_led.h"

Std_ReturnType ret;

volatile uint8 i2c_received_data;

void I2C_Default_ISR(void){
    /* Hold clock low (Clock Stretch) */
    SSPCON1bits.CKP = 0;
    
    i2c_received_data = SSPBUF;
    
    /* Release clock */
    SSPCON1bits.CKP = 1;
}

MSSP_I2C_t I2C2 = {
    .i2c_cfg.i2c_mode = I2C_MSSP_SLAVE_MODE,
    .i2c_cfg.i2c_mode_cfg = I2C_SLAVE_MODE_7BIT_ADDRESS,
    .i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE,
    .i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE,
    .i2c_cfg.i2c_general_call = I2C_GENERAL_CALL_DISABLE,
    .i2c_cfg.i2c_slave_address = 0x32,
    .I2C_Report_Receive_Overflow = NULL,
    .I2C_DefaultInterruptHandler = I2C_Default_ISR,
    .I2C_Report_Write_Collision = NULL
};

led_t led1 = { .port_name = GPIO_PORTD_INDEX, .pin = GPIO_PIN0, .led_status = LED_OFF };

int main() {
    ret = MSSP_I2C_Init(&I2C2);
    ret = led_initialize(&led1);
    while(1){
        if(i2c_received_data == 'B'){
            led_turn_on(&led1);
        }
        else if(i2c_received_data == 'D'){
            led_turn_off(&led1);
        }
        else{ /* Do Nothing */ }
    }
    return (EXIT_SUCCESS);
}




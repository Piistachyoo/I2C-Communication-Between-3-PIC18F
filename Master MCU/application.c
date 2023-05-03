/* 
 * File:   application.c
 * Author: Omar Yamany
 *
 * Created on March 6, 2023, 2:10 AM
 */

#include "MCAL_Layer/I2C/hal_i2c.h"


#define SLAVE_1 0x30
#define SLAVE_2 0x32

Std_ReturnType ret;
uint8 slave_ACK;
uint8 app_counter=0;

MSSP_I2C_t I2C1 = {
    .i2c_clock = 100000,
    .i2c_cfg.i2c_mode = I2C_MSSP_MASTER_MODE,
    .i2c_cfg.i2c_mode_cfg = I2C_MASTER_MODE_DEFINE_CLOCK,
    .i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE,
    .i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE,
};

void MSSP_I2C_Send_1Byte(uint8 slave_add, uint8 _data){
    ret = MSSP_I2C_Master_Send_Start(&I2C1);
    ret = MSSP_I2C_Master_Write_Blocking(&I2C1, slave_add, &slave_ACK);
    ret = MSSP_I2C_Master_Write_Blocking(&I2C1, _data, &slave_ACK);
    ret = MSSP_I2C_Master_Send_Stop(&I2C1);
}

int main() {
    ret = MSSP_I2C_Init(&I2C1);
    while(1){
        MSSP_I2C_Send_1Byte(SLAVE_1, 'A');
        __delay_ms(1000);
        MSSP_I2C_Send_1Byte(SLAVE_2, 'B');
        __delay_ms(1000);
        MSSP_I2C_Send_1Byte(SLAVE_1, 'C');
        __delay_ms(1000);
        MSSP_I2C_Send_1Byte(SLAVE_2, 'D');
        __delay_ms(1000);
        app_counter++;
    }
    return (EXIT_SUCCESS);
}




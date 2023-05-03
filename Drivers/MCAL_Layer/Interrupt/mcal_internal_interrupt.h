/* 
 * File:   mcal_internal_interrupt.h
 * Author: omarm
 *
 * Created on March 15, 2023, 12:25 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* Section : Includes */
#include "mcal_interrupt_config.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

#if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

// This macro clears the interrupt enable for the EUSART TX module
#define EUSART_TX_INTERRUPT_ENABLE()      (PIE1bits.TXIE = 1)
// This macro sets the interrupt enable for the EUSART TX module
#define EUSART_TX_INTERRUPT_DISABLE()     (PIE1bits.TXIE = 0)
// This macro clears the interrupt flag for the EUSART TX module
#define EUSART_TX_FLAG_CLEAR()            (PIR1bits.TXIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE

// This macro sets the EUSART TX interrupt priority to be high priority
#define EUSART_TX_HighPrioritySet()       (IPR1bits.TXIP = 1)
// This macro sets the EUSART TX interrupt priority to be low priority
#define EUSART_TX_LowPrioritySet()        (IPR1bits.TXIP = 0)

#endif

#endif

#if EUSART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

// This macro clears the interrupt enable for the EUSART RX module
#define EUSART_RX_INTERRUPT_ENABLE()      (PIE1bits.RCIE = 1)
// This macro sets the interrupt enable for the EUSART RX module
#define EUSART_RX_INTERRUPT_DISABLE()     (PIE1bits.RCIE = 0)
// This macro clears the interrupt flag for the EUSART RX module
#define EUSART_RX_FLAG_CLEAR()            (PIR1bits.RCIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE

// This macro sets the EUSART RX interrupt priority to be high priority
#define EUSART_RX_HighPrioritySet()       (IPR1bits.RCIP = 1)
// This macro sets the EUSART RX interrupt priority to be low priority
#define EUSART_RX_LowPrioritySet()        (IPR1bits.RCIP = 0)

#endif
#endif

#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

// This macro clears the interrupt enable for the SPI module
#define MSSP_SPI_INTERRUPT_ENABLE()      (PIE1bits.SSPIE = 1)
// This macro sets the interrupt enable for the SPI module
#define MSSP_SPI_INTERRUPT_DISABLE()     (PIE1bits.SSPIE = 0)
// This macro clears the interrupt flag for the SPI module
#define MSSP_SPI_FLAG_CLEAR()            (PIR1bits.SSPIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
// This macro sets the SPI interrupt priority to be high priority
#define MSSP_SPI_HighPrioritySet()       (IPR1bits.SSPIP = 1)
// This macro sets the SPI interrupt priority to be low priority
#define MSSP_SPI_LowPrioritySet()        (IPR1bits.SSPIP = 0)
#endif

#endif

#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

// This macro clears the interrupt enable for the I2C module
#define MSSP_I2C_INTERRUPT_ENABLE()      (PIE1bits.SSPIE = 1)
#define MSSP_I2C_BUS_COL_INTERRUPTENABLE()  (PIE2bits.BCLIE = 0)
// This macro sets the interrupt enable for the I2C module
#define MSSP_I2C_INTERRUPT_DISABLE()     (PIE1bits.SSPIE = 0)
#define MSSP_I2C_BUS_COL_INTERRUPTDISABLE() (PIE2bits.BCLIE = 1)
// This macro clears the interrupt flag for the I2C module
#define MSSP_I2C_FLAG_CLEAR()            (PIR1bits.SSPIF = 0)
#define MSSP_I2C_BUS_COL_InterruptFlagClear()   (PIR2bits.BCLIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
// This macro sets the I2C interrupt priority to be high priority
#define MSSP_I2C_HighPrioritySet()       (IPR1bits.SSPIP = 1)
#define MSSP_I2C_BUS_COL_HighPrioritySet()  (IPR2bits.BCLIP = 1)
// This macro sets the I2C interrupt priority to be low priority
#define MSSP_I2C_LowPrioritySet()        (IPR1bits.SSPIP = 0)
#define MSSP_I2C_BUS_COL_LowPrioritySet()  (IPR2bits.BCLIP = 0)
#endif

#endif

/* Section : Data Type Declarations */

/* Section : Function Declarations */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */


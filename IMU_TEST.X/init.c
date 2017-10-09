/// Prolougue

//  initialise PIC, other device
//  Author      :   reo kashiyama

/// Include files
#include <xc.h>
#include "init.h"
#include "I2Clib.h"
#include "skADXL345I2C.h"
#include "CAN.h"
#include "MPU9250.h"
#include "eepromI2C.h"

#include "PSITG.h"
#include "interrupt.h"


#include "OrigamiTypeDefine.h"
#include "CommonDefine.h"

/// Global data


/// Method
/*
 *  initialise PIC setting
 *	arg      :   void
 *	return   :   void
 *	TODO     :   avoid double declation
 *	FIXME    :   not yet
 *	XXX      :   avoid hardcoding
*/
void initPic(void){
     OSCCONbits.IRCF0 = 1;
     OSCCONbits.IRCF1 = 1;
     OSCCONbits.IRCF2 = 1;
     ANCON0 = 0x00;
     ANCON1 = 0x00;
     TRISA = 0x00;
     TRISB = 0x00;
     TRISC = 0x80;
     PORTA = 0x00;
     PORTB = 0x00;
     PORTC = 0x40;
}
/*
 *  wait 1ms.
 *	arg      :   void
 *	return   :   void
 *	TODO     :   not yet
 *	FIXME    :   not yet
 *	XXX      :   not yet
*/
void wait1ms(UINT num) {
    do {
        __delay_ms(1);
    } while (--num > 0);
    return;
}
/*
 *  wait 1us. not correct for few micro second.
 *	arg      :   void
 *	return   :   void
 *	TODO     :   not yet
 *	FIXME    :   not yet
 *	XXX      :   not yet
*/
void wait1us(UINT num){
    do {
        __delay_us(1);
    } while (--num > 0);
    return;
}
/*
 *  initialise all device on MDC board
 *	arg      :   void
 *	return   :   void
 *	TODO     :   avoid double declation
 *	FIXME    :   not yet
 *	XXX      :   avoid hardcoding, reduce init method for here
*/
void initAll(void){
    initPic();
    InitI2C_Master(1) ;
    CAN_int();
    initInterrupt();
    initIMU();
    acceler_Init();
    gyro_Init();
}
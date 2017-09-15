#include <xc.h>
#include "init.h"
#include "I2Clib.h"
#include "skADXL345I2C.h"
#include "CAN.h"
#include "eepromI2C.h"
#include "HMC.h"
#include "PSITG.h"
#include "interrupt.h"
#include "ADC.h"
#include "PWM_LED.h"

void pic_int(){
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

// 10ms�E�F�C�g���[�`��
void Wait_1ms(int num) {
    do {
        __delay_ms(1);
    } while (--num > 0);
    return;
}

void Wait_1us(int num){
    do {
        __delay_us(1);
    } while (--num > 0);
    return;
}

void all_init(){
    pic_int();
    InitI2C_Master(1) ;          // �h�Q�b�̏���������(I2C���x400KHz)
    CAN_int();
    interrupt_int();             //�J�E���g�Ɏg�p
    acceler_Init() ;             // �Z���T�[�̏��������s��(10bit,�}2G,OutRate=200Hz)
    magnet_Init();
    gyro_Init();
    AD_init();
    PWM_init();
}
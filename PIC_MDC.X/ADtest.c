#include <xc.h>
#include "ADtest.h"

void AD_init(){
    ANCON0 = 0x17; //AN2pin_ON
    ANCON1 = 0x07; //AN10pin_ON
    ADCON1 = 0x00; //�O���d���Q�Ɛݒ�
    ADCON2 = 0x2D;
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA5 = 1;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB4 = 1;
}

int AD_read(unsigned char *data){
    
    //AD�ǂݎ��
    AN0; //ADpin_con AN10
    //ADCON1 = 0x10; //�O���d���Q�Ɛݒ�
    //ADCON2 = 0x2D; //
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    data[0] = ADRESH;
    
    //AD�ϊ��N���A
    AN4;
    //ADCON1 = 0x10;
    //ADCON2 = 0x2D;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    
    //AD�ǂݎ��
    AN1; //ADpin_con AN10
    //ADCON1 = 0x10; //�O���d���Q�Ɛݒ�
    //ADCON2 = 0x2D; //
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    data[1] = ADRESH;
    
    //AD�ϊ��N���A
    AN4;
    //ADCON1 = 0x10;
    //ADCON2 = 0x2D;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    
    //AD�ǂݎ��
    AN2; //ADpin_con AN10
    //ADCON1 = 0x10; //�O���d���Q�Ɛݒ�
    //ADCON2 = 0x2D; //
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    data[2] = ADRESH;
    
    //AD�ϊ��N���A
    AN4;
    //ADCON1 = 0x10;
    //ADCON2 = 0x2D;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    
    //AD�ǂݎ��
    AN8; //ADpin_con AN10
    //ADCON1 = 0x10; //�O���d���Q�Ɛݒ�
    //ADCON2 = 0x2D; //
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    data[3] = ADRESH;
    
    //AD�ϊ��N���A
    AN4;
    //ADCON1 = 0x10;
    //ADCON2 = 0x2D;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    
    //AD�ǂݎ��
    AN9; //ADpin_con AN10
    //ADCON1 = 0x10; //�O���d���Q�Ɛݒ�
    //ADCON2 = 0x2D; //
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    data[4] = ADRESH;
    
    //AD�ϊ��N���A
    AN4;
    //ADCON1 = 0x10;
    //ADCON2 = 0x2D;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    
    //AD�ǂݎ��
    AN10; //ADpin_con AN10
    //ADCON1 = 0x10; //�O���d���Q�Ɛݒ�
    //ADCON2 = 0x2D; //
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    data[5] = ADRESH;
    
    return 0;
    
}

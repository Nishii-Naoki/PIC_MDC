/// Prolougue

//  AD setting initialise, read Analog vlotage for get SMA antenna dBm
//  Author      :   reo kashiyama

/// Include files
#include <xc.h>
#include "CommonDefine.h"
#include "ADC.h"
#include "OrigamiTypeDefine.h"


/// Global data
/// Method
/*
 *  initialise PIC AD setting
 *	arg      :   void
 *	return   :   void
 *	TODO     :   nothing
 *	FIXME    :   not yet
 *	XXX      :   avoid hardcoding
 */
void AD_init(void){
    ANCON0 = 0x17; //AN2pin_ON
    ANCON1 = 0x07; //AN10pin_ON
    ADCON1 = 0x00; //外部電圧参�?�設�?
    ADCON2 = 0x2D;
    TRISAbits.TRISA0 = TRIS_IN;
    TRISAbits.TRISA1 = TRIS_IN;
    TRISAbits.TRISA2 = TRIS_IN;
    TRISAbits.TRISA3 = TRIS_IN;
    TRISAbits.TRISA5 = TRIS_IN;
    TRISBbits.TRISB0 = TRIS_IN;
    TRISBbits.TRISB1 = TRIS_IN;
    TRISBbits.TRISB4 = TRIS_IN;
}

/*
 *  AD Read Me
 *	arg      :   void
 *	return   :   void
 *	TODO     :   nothing
 *	FIXME    :   not yet
 *	XXX      :   avoid hardcoding
                 avoid AN0,AN1,,,,
 */
 int AD_read(unsigned char *data){

     //AD読み取り
     AN0; //ADpin_con AN10
     //ADCON1 = 0x10; //外部電圧参�?�設�?
     //ADCON2 = 0x2D; //
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);
     data[0] = ADRESH;

     //AD変換クリア
     AN4;
     //ADCON1 = 0x10;
     //ADCON2 = 0x2D;
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);

     //AD読み取り
     AN1; //ADpin_con AN10
     //ADCON1 = 0x10; //外部電圧参�?�設�?
     //ADCON2 = 0x2D; //
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);
     data[1] = ADRESH;

     //AD変換クリア
     AN4;
     //ADCON1 = 0x10;
     //ADCON2 = 0x2D;
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);

     //AD読み取り
     AN2; //ADpin_con AN10
     //ADCON1 = 0x10; //外部電圧参�?�設�?
     //ADCON2 = 0x2D; //
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);
     data[2] = ADRESH;

     //AD変換クリア
     AN4;
     //ADCON1 = 0x10;
     //ADCON2 = 0x2D;
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);

     //AD読み取り
     AN8; //ADpin_con AN10
     //ADCON1 = 0x10; //外部電圧参�?�設�?
     //ADCON2 = 0x2D; //
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);
     data[3] = ADRESH;

     //AD変換クリア
     AN4;
     //ADCON1 = 0x10;
     //ADCON2 = 0x2D;
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);

     //AD読み取り
     AN9; //ADpin_con AN10
     //ADCON1 = 0x10; //外部電圧参�?�設�?
     //ADCON2 = 0x2D; //
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);
     data[4] = ADRESH;

     //AD変換クリア
     AN4;
     //ADCON1 = 0x10;
     //ADCON2 = 0x2D;
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);

     //AD読み取り
     AN10; //ADpin_con AN10
     //ADCON1 = 0x10; //外部電圧参�?�設�?
     //ADCON2 = 0x2D; //
     ADCON0bits.GO = 1;
     while(ADCON0bits.GO);
     data[5] = ADRESH;

     return 0;

 }

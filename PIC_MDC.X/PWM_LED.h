/* 
 * File:   PWM_LED.h
 * Author: �e�B���_��
 *
 * Created on 2016/12/05, 14:36
 */

#ifndef PWM_LED_H
#define	PWM_LED_H

#ifndef _XTAL_FREQ
 #define _XTAL_FREQ 16000000       // �g�p����PIC���ɂ�蓮����g���l��ݒ肷��
#endif

int PWM_init(void);
int PWM_LED(int lux);
void rLED_ON(void);
void rLED_OFF(void);

#endif	/* PWM_LED_H */


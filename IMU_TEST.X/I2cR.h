/* 
 * File:   I2cR.h
 * Author: �e�B���_��
 *
 * Created on 2016/11/30, 22:30
 */

#ifndef I2CR_H
#define	I2CR_H

#ifndef _XTAL_FREQ
 
 #define _XTAL_FREQ 16000000       // �g�p����PIC���ɂ�蓮����g���l��ݒ肷��
#endif

// �h�Q�b�̃A�h���X
#define AD5252_ADRES 0x2C       // AD5252�̃A�h���X>>1
// ���W�X�^�̃A�h���X
#define RDAC1         0x21        //wiper setting
#define RDAC3         0x23        //wiper setting

int changeR();

#endif	/* I2CR_H */


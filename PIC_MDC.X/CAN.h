/* 
 * File:   CAN.h
 * Author: �e�B���_��
 *
 * Created on 2016/10/25, 2:39
 */

#ifndef CAN_H
#define	CAN_H

#ifndef _XTAL_FREQ
 #define _XTAL_FREQ 16000000       // �g�p����PIC���ɂ�蓮����g���l��ݒ肷��
#endif

#define CAN_ID_L  0xEB
#define CAN_ID_H  0xFF
#define CAN_EID_L  0xFF
#define CAN_EID_H  0xFF

void initCan();
void readCanData(char *read_data);
void sendCanData(char *send_data);

#endif	/* CAN_H */


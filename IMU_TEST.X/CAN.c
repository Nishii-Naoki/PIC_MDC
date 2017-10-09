#include <xc.h>
#include "CAN.h"

//CAN������
void CAN_int(){
    //TRISCbits.TRISC6 = 0;  //Can�ݒ�@RC6=0�ARC7=1
    //TRISCbits.TRISC7 = 1;
    CANCON = 0x80; //config���[�hON
    CANSTAT = 0x80; //�������J�n
    //
    ECANCON = 0x00;
    BRGCON1 = 0x09; //T_Q = 2/Fosc, Sync_seg = 1 * T_Q
    BRGCON2 = 0x91; //Phase_seg1 = 3 * T_Q, Prop_seg = 2 * T_Q;
    BRGCON3 = 0x01; //Phase_seg2 = 2 * T_Q
    /***************************************************************************
     * Nominal bit time = T_Q * (Sync_seg + Prop_seg + Phase_seg1 + Phase_seg2)
     **************************************************************************/
    RXB0CON = 0x40; //�}�X�NON�g���t�H�[�}�b�g
    RXB1CON = 0x40; //�}�X�NON�g���t�H�[�}�b�g
    //
    TXB0D0 = 0x00;
    TXB0D1 = 0x00;
    TXB0D2 = 0x00;
    TXB0D3 = 0x00;
    TXB0D4 = 0x00;
    TXB0D5 = 0x00;
    TXB0D6 = 0x00;
    TXB0D7 = 0x00;
    TXB0SIDL = 0x00;
    TXB0SIDH = 0x00;
    TXB0DLC = 0x00;
    TXB0CON = 0x00;
    //
    RXB0D0 = 0x00;
    RXB0D1 = 0x00;
    RXB0D2 = 0x00;
    RXB0D3 = 0x00;
    RXB0D4 = 0x00;
    RXB0D5 = 0x00;
    RXB0D6 = 0x00;
    RXB0D7 = 0x00;
    //
    CANSTAT =0x00;
    CANCON = 0x00; //�m�[�}�����[�h
    return;
} 

//CAN��M
void CAN_read(char *read_data){
    RXF0SIDH = CAN_ID_H;
    RXF0SIDL = CAN_ID_L;
    RXF0EIDH = CAN_EID_H;
    RXF0EIDL = CAN_EID_L;
    
    while(RXB0CONbits.RXFUL==0){}//�f�[�^����M�ł��Ă��邩�m�F
    read_data[0] = RXB0D0;//��M�����f�[�^���i�[
    read_data[1] = RXB0D1;
    read_data[2] = RXB0D2;
    read_data[3] = RXB0D3;
    read_data[4] = RXB0D4;
    read_data[5] = RXB0D5;
    read_data[6] = RXB0D6;
    read_data[7] = RXB0D7;
    RXB0CONbits.RXFUL = 0;//�f�[�^����ɂ���
    return;
}

//CAN���M
void CAN_send(char *send_data){
    TXB0D0 = send_data[0];//���M�f�[�^���`
    TXB0D1 = send_data[1];
    TXB0D2 = send_data[2];
    TXB0D3 = send_data[3];
    TXB0D4 = send_data[4];
    TXB0D5 = send_data[5];
    TXB0D6 = send_data[6];
    TXB0D7 = send_data[7];
    TXB0SIDL = CAN_ID_L;//ID���i�[
    TXB0SIDH = CAN_ID_H;
    TXB0EIDL = CAN_EID_L;
    TXB0EIDH = CAN_EID_H;
    TXB0DLC = 0x08;
    TXB0CON = 0x0B;//���M
    while(TXB0CONbits.TXREQ){}
    return;
}


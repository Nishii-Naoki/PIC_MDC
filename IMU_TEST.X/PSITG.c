#include <xc.h>
#include "PSITG.h"
#include "I2Clib.h"

int Gregister_read(char address)
{
     int ans ;

     ans = I2C_Start(PSITG_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(address) ;                // ���W�X�^�A�h���X�̑��M
          I2C_rStart(PSITG_ADRES,RW_1) ;   // ���s�[�g�E�X�^�[�g�R���f�B�V�����𔭍s����
          ans = I2C_Receive(NOACK);          // �f�[�^���e����M����
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����
     return ans ;
}

int Gregister_write(char address, char val)
{
     int ans ;

     ans = I2C_Start(PSITG_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(address) ;                // ���W�X�^�A�h���X�̑��M
          I2C_Send(val) ;                    // �f�[�^���e�̑��M
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����
     return ans ;
}

int gyro_Init()
{
    int ans ;

     __delay_us(2000) ;                      // �����オ���҂�
     ans = Gregister_read(WHO) ;            // �ڑ��n�j���h�c��ǂ݂����Č���
     if (ans == WHO_VALUE) {
          //F_sample=F_internal / (divider + 1)
          Gregister_write(SAMPLE_RATE,0x00) ;     //divider=0,
          Gregister_write(DLPF,0x1E) ;            //range=�}2000��/s,F_internal=1kHz,Lowfilter=5Hz
          Gregister_write(IN_CONFIG,0x35) ;       //interrupt=enable
          Gregister_write(POWER_MANAGE,0x00) ;    //clock=internal
          __delay_us(2000) ;                      //wait for set config
     } else ans = -1 ;
     return ans ;
}

int gyro_Read(unsigned char *data, int n)
{
     int ans , i , ack ;
     
     while(ans != 0x01){
         ans = Gregister_read(IN_STAT) ;
         ans = ans & 0x01;
     }
     
     ans = I2C_Start(PSITG_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(DATA_XG) ;                // ���W�X�^�A�h���X�̑��M
          I2C_rStart(PSITG_ADRES,RW_1) ;   // ���s�[�g�E�X�^�[�g�R���f�B�V�����𔭍s����
          ack = ACK ;
          for (i=0 ; i<8 ; i++) {
               if (i==7) ack = NOACK ;
               data[n+i] = I2C_Receive(ack); // �w�x�y�̂R���f�[�^��ǂݏo��
          }
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����

     return ans ;
}
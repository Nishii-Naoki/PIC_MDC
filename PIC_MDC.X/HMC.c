#include <xc.h>
#include "HMC.h"
#include "I2Clib.h"

int Mregister_read(char address)
{
     int ans ;

     ans = I2C_Start(HMC_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(address) ;                // ���W�X�^�A�h���X�̑��M
          I2C_rStart(HMC_ADRES,RW_1) ;   // ���s�[�g�E�X�^�[�g�R���f�B�V�����𔭍s����
          ans = I2C_Receive(NOACK);          // �f�[�^���e����M����
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����
     return ans ;
}
// AHMC5883�̃��W�X�^�[�Ƀf�[�^���������ޏ���
// adress : �������ރA�h���X���w��
// val    : �������ރf�[�^���w��
int Mregister_write(char address, char val)
{
     int ans ;

     ans = I2C_Start(HMC_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(address) ;                // ���W�X�^�A�h���X�̑��M
          I2C_Send(val) ;                    // �f�[�^���e�̑��M
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����
     return ans ;
}

int magnet_Init()
{
    int ans ;

     __delay_us(2000) ;                      // �����オ���҂�
     ans = Mregister_read(ID_REGA) ;            // �ڑ��n�j���h�c��ǂ݂����Č���
     if (ans == ID_REGA_VALUE) {
          Mregister_write(CONFIG_A,0x18) ;     // �m�[�}�����[�h�E�o�̓f�[�^���[�g��75Hz
          Mregister_write(CONFIG_B,0x20) ; // �Q�C���ݒ�@1090
          Mregister_write(MODE_REG,0x00) ;    // �A�����胂�[�h
          __delay_us(2000) ;                 // �ݒ肳���̂�҂�
     } else ans = -1 ;
     return ans ;
}
/*
*    ans : �O������@�|�P���Ǎ��ݎ��s(I2C�ُ�)                                 *
******************************************************************************/ 
int magnet_Read(unsigned char *data)
{
     int ans , i , ack ;
     
    while(ans != 0x01){
         ans = Mregister_read(ID_STAT) ;
         ans = ans & 0x02;
    }

     ans = I2C_Start(HMC_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(DATA_XM) ;                // ���W�X�^�A�h���X�̑��M
          I2C_rStart(HMC_ADRES,RW_1) ;   // ���s�[�g�E�X�^�[�g�R���f�B�V�����𔭍s����
          ack = ACK ;
          for (i=0 ; i<6 ; i++) {
               if (i==5) ack = NOACK ;
               data[i] = I2C_Receive(ack); // �w�x�y�̂R���f�[�^��ǂݏo��
          }
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����

     return ans ;
}

#include <xc.h>
#include "I2cR.h"
#include "I2Clib.h"

int ADregister_read(char address)
{
     int ans ;

     ans = I2C_Start(AD5252_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(address) ;                // ���W�X�^�A�h���X�̑��M
          I2C_rStart(AD5252_ADRES,RW_1) ;   // ���s�[�g�E�X�^�[�g�R���f�B�V�����𔭍s����
          ans = I2C_Receive(NOACK);          // �f�[�^���e����M����
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����
     return ans ;
}

int ADregister_write(char address, char val)
{
     int ans ;

     ans = I2C_Start(AD5252_ADRES,RW_0);    // �X�^�[�g�R���f�B�V�����𔭍s����
     if (ans == 0) {
          I2C_Send(address) ;                // ���W�X�^�A�h���X�̑��M
          I2C_Send(val) ;                    // �f�[�^���e�̑��M
     } else ans = -1 ;
     I2C_Stop() ;                            // �X�g�b�v�R���f�B�V�����𔭍s����
     return ans ;
}

int changeR(){
    
    int ans;
        
    ans = ADregister_write(RDAC1,0xFF);
    
    return ans ;
    
}
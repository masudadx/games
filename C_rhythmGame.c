#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


//�f�B���C�����֐�
void delay(int milliseconds) {

    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);

}

//���̓X�g�b�v�p�֐�
void stop (void){

    char c = 0;//�L�[�{�[�h�Ǘ��p

    for(;;){

        if(kbhit()){
            c = getch();
            break;
        }
    }
}


//�^�C�~���O�Q�[�������֐�
int timing (int round){

     ((unsigned)time(NULL));

    int i , k;      //for�����Ŏg�p�@���W�p
    int dec;            //decide �^�C�~���O�ۑ��p
    int point = 0;      //�ۑ�����dec��_���ɕϊ�����p
    int end = 0;       //�I���Ǘ��p
    char charkey = 0;   //�L�[�{�[�h�Ǘ��p
    int delaytime = rand()%80 + 10; //�P�R�}������̎���(�~���b)
                                    //����͗������g�p���Ă��܂����A�Œ莞�Ԃ��w�肷�邱�Ƃ��������\�ł�
    

    printf("===========�~�߂�ɂ�s�L�[����͂��Ă�!============\n"); //UI�\��
    printf("\n\n");
    printf("xxxxxxxxxxxxxx| GOOD | JUST | GOOD |xxxxxxxxxxxxxx\n");

    while (end == 0) {         //�^�C�~���O�o�[�\���p
    for( i = 1 ; i <= 25 ; i ++){
        
        printf("|");
        delay(delaytime);

        if(kbhit()){        //��������̃L�[�������ꂽ��I��
            charkey = getch();
            end += 1; 
            dec = i;
            break;
        }

        printf("\033[2K");
        printf(" ");
        
    }
    
    for( k = 25 ; k >= 1 ; k --){

        if(end != 0){ // ������E�ɍs���Ƃ��ɃX�g�b�v�������ꂽ�ꍇ�A�E���獶�ɍs���������X�L�b�v���܂�
            break;
        }
        
        printf("\033[3D");
        printf("|");
        delay(delaytime);

        if(kbhit()){        //��������̃L�[�������ꂽ��I��
            charkey = getch();
            end += 1; 
            dec = k;
            break;

        }
        
        printf("\033[2K");

    }
    }

    //printf("\ni�@�܂��� k �� %d\n", dec );
    // �����̓e�X�g�p�ł��@�l������Ƃ��Ɏg�p���Ă�������

    delay(10);

    if( dec <= 7 || dec > 17){
        printf("\n                     MISS!\n\n");
        point = 0;
        

    }else if( 7 < dec && dec <= 10 || 14 < dec &&  dec <= 17  ){
        printf("\n               %d�A��!    GOOD!  +5�_\n\n",round);
        point += 5;

    }else if(10 < dec && dec <= 14 ){
        printf("\n               %d�A��!    JUST!  +10�_\n\n",round);
        point += 10;

    }

    return point;

}

int main(void){
 
    int result = 0;    //�^�C�~���O�Q�[���֐����ŏ��������_���ۊǗp
    int beforeresult = 0;//�O��̃X�R�A��ۑ�
    int times = 0;     //�Q�[���̃��E���h���Ǘ��p
    int T_times = 0;   //���v���E���h�\���p
    
    int endB = 0;      //�Q�[���I���Ǘ��p
    char charkey = 0;  //�L�[�{�[�h�Ǘ��p

    //�ȉ��Q�[���{��
    printf("============================\n");
    printf("=     �^�C�~���O�Q�[��      =\n");
    printf("= Press any key to start!  =\n");
    printf("============================\n");

    printf("�E�^�C�~���O�ǂ�S�L�[�������Ă�!\n");
    printf("�E���Ŏ~�߂�ƃQ�[���I��!\n");
    printf("�E�ō��X�R�A��ڎw���Ď����̌��E�ɒ���!\n");
    printf("\n");

    stop();//�L�[�{�[�h���͎�t&���̊ԏ������~�߂�֐�

    for(times  = 1 ;; times ++){  //�^�C�~���O�Q�[�����񂵑�����ӏ�

        beforeresult = result;
        result = result + timing(times);

        if(result == beforeresult  ){
            break;
        }

        T_times = times;
    }
    
    delay(100); //�ȉ����U���g�\���p
    printf("\n\n");
    printf("==================\n");
    printf("======RESULT======\n");
    printf("\n�A���Q�[����:%d��!\n",T_times);
    printf("\n���v�_      :%d�_!\n",result);
    printf("\n\n==================\n");
   
    printf("\n\n--�I��--\n\n");
    
    return 0;
}
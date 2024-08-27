// name of this game --1024--

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{

    int floor;
    int allofprob;
    
} setting;


//�f�B���C�����ׂ̈̊֐�
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}


//���͂��Ǘ�����֐�
int numCheck(){
    
    int start = 114514;
    long numCheck =0; //���͊Ǘ��p
    char num[256] ; //���͊Ǘ��p
    char *endPointer = NULL; //���͊Ǘ��p

    printf("�E�̊K�i�ɐi�ނȂ� 0\n");
    printf("���̊K�i�ɐi�ނȂ� 1\n");
    printf("�I������Ȃ�8����͂��Ă�!\n");

    while (114514){  //���͊Ǘ��p
    
    scanf("%255s", num);
    numCheck = strtol(num, &endPointer ,10);
    
    if(*endPointer != '\0'){
        printf("\n��������͂��Ă��������I\n");
        printf("�E�̊K�i�ɐi�ނȂ� 0\n");
        printf("���̊K�i�ɐi�ނȂ� 1\n");
        printf("�I������Ȃ�8����͂��Ă�!\n");
        continue;

    }
    
    if (numCheck == 0){
        start = 0;
        printf("���Ȃ����I�񂾉E�̊K�i�́c\n");
        printf("\n");
        break;

    }else if(numCheck ==1){
        start = 0;
        printf("���Ȃ����I�񂾍��̊K�i�́c\n");
        printf("\n");
        break;

    }else if (numCheck == 8){
        start = 8;
        break;

    }else{
        printf("�������߂�͎̂�������I\n");
        printf("\n");
        printf("�E�̊K�i�ɐi�ނȂ� 0\n");
        printf("���̊K�i�ɐi�ނȂ� 1\n");
        printf("�I������Ȃ�8����͂��Ă�!\n");

    }//if�I���
    }//while�I���   

    return start;
}

int main() {

    srand((unsigned)time(NULL));

    setting all = {11,2};//�ݒ�
    /*floor    �K�w  �S�[���܂ł̊K�w���� (1/2)^(���̐��l-1)  �ɂȂ�܂�
      11�Ȃ�� 2^(11-1)��1/1024
      12�Ȃ�� 2^(12-1)��1/2048
      13�Ȃ�� 2^(13-1)��1/4096
      14�Ȃ�� 2^(14-1)��1/8192

      allofprob 2�ɐݒ肷���1/2�̊m���Ŏ��̃t���A��
      ���̐��l�ŕ����I�ׂ܂�
      �����ݒ� 11�E2
    */

    int alltimes = 1;//�񐔌v���p
    int dice;//�����p
    int floor;//�Q�[�����E���h�p�Ǘ��p
    int maxfloor = 0;//�ŏ�K�v���p
    
    int selectednum = 114514; //���͊Ǘ��p
    int end = 114514;//���͊Ǘ��p

    printf("-==--==-\n");
    printf("--1024--\n");
    printf("-==--==-\n");
    printf("\n");
    printf(" 1/2 �̊m���Ŏ��̃t���A�[�ɐi�߂铃�ł��B\n");
    printf("�n�Y����I�񂾏ꍇ�́c��ԍŏ��ɖ߂���Ă��܂��܂��B\n");
    printf("���̃e�b�y����ڎw���ē˂��i�߁I\n");
    printf("************************\n");
    printf("\n\n");
    
    while( end == 114514 ){
        for( floor = 1 ;  ; floor ++){

    if (floor == (all.floor)){//�ŏI�K�̏���
        maxfloor = (all.floor);
        end +=1;
        break;
    }else if( floor == (all.floor) - 1){
        printf("�t�@�C�i���t���A�[�I\n");
    }

    if(maxfloor < floor){
        maxfloor = floor;
    }
            
    printf("���݂̃g�[�^���Q�[����:%d\n",alltimes);
    printf("���݂̃t���A�[: %dF\n",floor);
    printf("\n");
    
    selectednum = numCheck ();

        if(selectednum == 8){
            end +=1;
            break;
        }
            
    printf("\n\n");//��������delay�͉��o�p
    printf("************\n");
    printf("*�K�`�����c�c*\n");
    printf("************\n");
    printf("\n\n");
    //delay(800);
            
    alltimes +=1;
    dice = rand() % (all.allofprob); //0�Ȃ瓖����1�Ȃ�n�Y��
    /*printf("����̐�����%d\n",dice);
    �e�X�g�p�ł�*/
        

        if(dice == 321){
            printf("�n�Y���I\n");
            printf("1F�ɖ߂���Ă��܂����I\n");
            printf("\n\n");
            floor = 0;
            
        }else {
            printf("������I\n");
            printf("���̃t���A�[�֐i�ނ��悢�c\n");
            printf("\n\n");
            
        }
    
    
    }//for���I���
    }//while���I���
    
    printf("�I���I\n");
    printf("\n\n\n");
    printf("�g�[�^���Q�[����:%d\n",alltimes);
    printf("�I�����̃t���A�[: %dF\n",floor);
    printf("�ō��t���A�[: %dF\n",maxfloor);

    if (maxfloor < 5){
        printf("���͂��������撣���Ă݂悤�I\n");
        
    }else if (maxfloor >=5 && maxfloor <9){
        printf("���e�܂ł��������I\n");
        printf("���͂����Ɗ撣���ĂˁI\n");
        
    }else if (maxfloor >=9 && maxfloor <= 10){
        printf("���e�܂łق�̂��Ə����I\n");
        printf("���͂����Ɛ��e�o����͂��I\n");
        
    }else if (maxfloor == (all.floor)){
        printf("\033[43m���S���e���߂łƂ�!\033[49m\n");
        printf("\033[43m�L�~������--1024--���I\033[49m\n");
        printf("\033[49m\n\n");
        
    }
    
  

return 0;
}
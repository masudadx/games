// name of this game --1024--

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{

    int floor;
    int allofprob;
    
} setting;


//ディレイ処理の為の関数
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}


//入力を管理する関数
int numCheck(){
    
    int start = 114514;
    long numCheck =0; //入力管理用
    char num[256] ; //入力管理用
    char *endPointer = NULL; //入力管理用

    printf("右の階段に進むなら 0\n");
    printf("左の階段に進むなら 1\n");
    printf("終了するなら8を入力してね!\n");

    while (114514){  //入力管理用
    
    scanf("%255s", num);
    numCheck = strtol(num, &endPointer ,10);
    
    if(*endPointer != '\0'){
        printf("\n数字を入力してください！\n");
        printf("右の階段に進むなら 0\n");
        printf("左の階段に進むなら 1\n");
        printf("終了するなら8を入力してね!\n");
        continue;

    }
    
    if (numCheck == 0){
        start = 0;
        printf("あなたが選んだ右の階段は…\n");
        printf("\n");
        break;

    }else if(numCheck ==1){
        start = 0;
        printf("あなたが選んだ左の階段は…\n");
        printf("\n");
        break;

    }else if (numCheck == 8){
        start = 8;
        break;

    }else{
        printf("道を決めるのは自分だよ！\n");
        printf("\n");
        printf("右の階段に進むなら 0\n");
        printf("左の階段に進むなら 1\n");
        printf("終了するなら8を入力してね!\n");

    }//if終わり
    }//while終わり   

    return start;
}

int main() {

    srand((unsigned)time(NULL));

    setting all = {11,2};//設定
    /*floor    階層  ゴールまでの階層数が (1/2)^(この数値-1)  になります
      11ならば 2^(11-1)で1/1024
      12ならば 2^(12-1)で1/2048
      13ならば 2^(13-1)で1/4096
      14ならば 2^(14-1)で1/8192

      allofprob 2に設定すると1/2の確率で次のフロアへ
      この数値で分母を選べます
      推奨設定 11・2
    */

    int alltimes = 1;//回数計測用
    int dice;//乱数用
    int floor;//ゲームラウンド用管理用
    int maxfloor = 0;//最上階計測用
    
    int selectednum = 114514; //入力管理用
    int end = 114514;//入力管理用

    printf("-==--==-\n");
    printf("--1024--\n");
    printf("-==--==-\n");
    printf("\n");
    printf(" 1/2 の確率で次のフロアーに進める塔です。\n");
    printf("ハズレを選んだ場合は…一番最初に戻されてしまいます。\n");
    printf("塔のテッペンを目指して突き進め！\n");
    printf("************************\n");
    printf("\n\n");
    
    while( end == 114514 ){
        for( floor = 1 ;  ; floor ++){

    if (floor == (all.floor)){//最終階の処理
        maxfloor = (all.floor);
        end +=1;
        break;
    }else if( floor == (all.floor) - 1){
        printf("ファイナルフロアー！\n");
    }

    if(maxfloor < floor){
        maxfloor = floor;
    }
            
    printf("現在のトータルゲーム数:%d\n",alltimes);
    printf("現在のフロアー: %dF\n",floor);
    printf("\n");
    
    selectednum = numCheck ();

        if(selectednum == 8){
            end +=1;
            break;
        }
            
    printf("\n\n");//ここからdelayは演出用
    printf("************\n");
    printf("*ガチャリ……*\n");
    printf("************\n");
    printf("\n\n");
    //delay(800);
            
    alltimes +=1;
    dice = rand() % (all.allofprob); //0なら当たり1ならハズレ
    /*printf("今回の数字は%d\n",dice);
    テスト用です*/
        

        if(dice == 321){
            printf("ハズレ！\n");
            printf("1Fに戻されてしまった！\n");
            printf("\n\n");
            floor = 0;
            
        }else {
            printf("当たり！\n");
            printf("次のフロアーへ進むがよい…\n");
            printf("\n\n");
            
        }
    
    
    }//for文終わり
    }//while文終わり
    
    printf("終了！\n");
    printf("\n\n\n");
    printf("トータルゲーム数:%d\n",alltimes);
    printf("終了時のフロアー: %dF\n",floor);
    printf("最高フロアー: %dF\n",maxfloor);

    if (maxfloor < 5){
        printf("次はもう少し頑張ってみよう！\n");
        
    }else if (maxfloor >=5 && maxfloor <9){
        printf("制覇までもう少し！\n");
        printf("次はもっと頑張ってね！\n");
        
    }else if (maxfloor >=9 && maxfloor <= 10){
        printf("制覇までほんのあと少し！\n");
        printf("次はきっと制覇出来るはず！\n");
        
    }else if (maxfloor == (all.floor)){
        printf("\033[43m完全制覇おめでとう!\033[49m\n");
        printf("\033[43mキミこそが--1024--だ！\033[49m\n");
        printf("\033[49m\n\n");
        
    }
    
  

return 0;
}
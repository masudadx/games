#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


//ディレイ処理関数
void delay(int milliseconds) {

    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);

}

//入力ストップ用関数
void stop (void){

    char c = 0;//キーボード管理用

    for(;;){

        if(kbhit()){
            c = getch();
            break;
        }
    }
}


//タイミングゲーム処理関数
int timing (int round){

     ((unsigned)time(NULL));

    int i , k;      //for文内で使用　座標用
    int dec;            //decide タイミング保存用
    int point = 0;      //保存したdecを点数に変換する用
    int end = 0;       //終了管理用
    char charkey = 0;   //キーボード管理用
    int delaytime = rand()%80 + 10; //１コマあたりの時間(ミリ秒)
                                    //今回は乱数を使用していますが、固定時間を指定することももちろん可能です
    

    printf("===========止めるにはsキーを入力してね!============\n"); //UI表示
    printf("\n\n");
    printf("xxxxxxxxxxxxxx| GOOD | JUST | GOOD |xxxxxxxxxxxxxx\n");

    while (end == 0) {         //タイミングバー表示用
    for( i = 1 ; i <= 25 ; i ++){
        
        printf("|");
        delay(delaytime);

        if(kbhit()){        //何かしらのキーが押されたら終了
            charkey = getch();
            end += 1; 
            dec = i;
            break;
        }

        printf("\033[2K");
        printf(" ");
        
    }
    
    for( k = 25 ; k >= 1 ; k --){

        if(end != 0){ // 左から右に行くときにストップが押された場合、右から左に行く処理をスキップします
            break;
        }
        
        printf("\033[3D");
        printf("|");
        delay(delaytime);

        if(kbhit()){        //何かしらのキーが押されたら終了
            charkey = getch();
            end += 1; 
            dec = k;
            break;

        }
        
        printf("\033[2K");

    }
    }

    //printf("\ni　または k は %d\n", dec );
    // ここはテスト用です　値を見るときに使用してください

    delay(10);

    if( dec <= 7 || dec > 17){
        printf("\n                     MISS!\n\n");
        point = 0;
        

    }else if( 7 < dec && dec <= 10 || 14 < dec &&  dec <= 17  ){
        printf("\n               %d連続!    GOOD!  +5点\n\n",round);
        point += 5;

    }else if(10 < dec && dec <= 14 ){
        printf("\n               %d連続!    JUST!  +10点\n\n",round);
        point += 10;

    }

    return point;

}

int main(void){
 
    int result = 0;    //タイミングゲーム関数内で処理した点数保管用
    int beforeresult = 0;//前回のスコアを保存
    int times = 0;     //ゲームのラウンド数管理用
    int T_times = 0;   //合計ラウンド表示用
    
    int endB = 0;      //ゲーム終了管理用
    char charkey = 0;  //キーボード管理用

    //以下ゲーム本編
    printf("============================\n");
    printf("=     タイミングゲーム      =\n");
    printf("= Press any key to start!  =\n");
    printf("============================\n");

    printf("・タイミング良くSキーを押してね!\n");
    printf("・ｘで止めるとゲーム終了!\n");
    printf("・最高スコアを目指して自分の限界に挑め!\n");
    printf("\n");

    stop();//キーボード入力受付&その間処理を止める関数

    for(times  = 1 ;; times ++){  //タイミングゲームを回し続ける箇所

        beforeresult = result;
        result = result + timing(times);

        if(result == beforeresult  ){
            break;
        }

        T_times = times;
    }
    
    delay(100); //以下リザルト表示用
    printf("\n\n");
    printf("==================\n");
    printf("======RESULT======\n");
    printf("\n連続ゲーム数:%d回!\n",T_times);
    printf("\n合計点      :%d点!\n",result);
    printf("\n\n==================\n");
   
    printf("\n\n--終了--\n\n");
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
このプログラムの構造
1.構造体
    -1.通常設定用
    -2.BIG用
    -3.REG用

2.関数
    -1.delay処理用
    -2.BIG用
    -3.REG用

3.メイン関数
    -1.茶番パート
    -2.イントロ用
    -3.ゲーム本編処理
    -4.抽選処理
    -5.エンディング処理
*/


//通常時の設定に関する構造体
typedef struct {

    int gamblingAll; //全体パターン数
    int big;         //bigが当たるパターン数 1/全体にしたったら0を入力
    int reg;         //regが当たるパターン数
    int cherry;      //チェリーのパターン数
    
} nomSettei;



//BIGの設定に関する構造体
typedef struct{

    int round;      //ラウンド数
    int atariMedal; //1Rあたりのメダル数
    int renchanAll; //1/(この数)の連チャン確率になる
    
} bigSettei;



//REGの設定に関する構造体
typedef struct{

    int round; //ラウンド数
    int atariMedal; //1Rあたりのメダル数
    int renchanAll; //1/(この数)の連チャン確率になる
    
} regSettei;



//ディレイ処理の関数(フリーズに使う)
//参考文献:ジャパンシーモア
void delay(int milliseconds) {

    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);

}



//BIGボーナスに関する関数
int big (int * medal){

    bigSettei a = { 5, 20 , 5}; /*ラウンド数・1Rあたりの当たりメダル枚数・1/(この数)で連チャン確率を決定する*/

    int startMedal = *medal; //メダル枚数計算用
    int start =114514;       //スタートフラグ
    int end = 0;             //エンドフラグ
    int renchan =114514;     //連チャン管理用
    int biggames = 0;

    long numCheck =0;        //入力管理用
    char num[256] ;          //入力管理用
    char *endPointer = NULL; //入力管理用
    
    srand((unsigned)time(NULL));
    
    
    while(end == 0){    //連チャンの時は0 ハズレの時はend+=1

        printf("---------------------------\n"); //ボーナスゲーム区間を管理する箇所
        for(int i = 0 ; i < (a.round) ; i ++){
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("BIGボーナスゲーム%dゲーム目!\n",i + 1);
            printf("スロットを回すには0を入力してね!\n");
            
            
            
        while (114514){  //入力管理用

            scanf("%255s", num);
            numCheck = strtol(num, &endPointer ,10);

                if(*endPointer != '\0'){
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\n数字を入力しなさいよ!\n");
                    printf("準備はいい？\nスロットを回すなら0を入力してね!\n");
                    continue;

                }

                if (numCheck == 0){
                    start = 0;
                    delay(500);
                    break;

                }else if (numCheck == 8){
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\nせっかくBIGボーナスが当たってるんだから回しなさいよ!\n");
                    printf("スロットを回すなら0を入力してね!\n");

                }else{
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\n準備してから入力しなさいよ!\n");
                    printf("スロットを回すなら0を入力してね!\n");

                }
        }  //入力管理用終了

        printf("\n\n\n\n\n");
        printf("\n  {[{  B I G BONUS  }]}\n");
        printf("  #*~+~*~+=~~~=+~*~+~*#\n");
        printf("  #| [7] | [7] | [7] |#\n");
        printf("  #*~+~*~+=~~~=+~*~+~*#\n  ");
            for( int j = 0; j < i +1 ; j ++){
                printf("*-*-");
            }
        printf("*\n   メダル20枚獲得!\n\n\n\n\n\n");
        *medal += (a.atariMedal);
        biggames += 1;

        }//ここで1ゲーム終わり

        printf("\n\n\n---------------------------\n");
        printf("BIGボーナスゲーム終了!\n次のレバーオンで連チャンを引き当てろ!\n0を入力してレバーオンだ!\n");
        
        while (114514){  //入力管理用箇所

            scanf("%255s", num);
            numCheck = strtol(num, &endPointer ,10);

                if(*endPointer != '\0'){
                    printf("\n数字を入力しなさいよ!\n");
                    printf("レバーオンなら0を入力してね!\n");
                    continue;

                }if (numCheck == 0){
                    start = 0;
                    break;

                }else if (numCheck == 8){
                    printf("\n連チャンチャレンジなんだから回しなさいよ!\n");
                    printf("スロットを回すなら0を入力してね!\n");

                }else{
                    printf("\n準備してから入力しなさいよ!\n");
                    printf("レバーオンなら0を入力してね!\n");

                }

        }//入力管理用箇所終わり

        
        renchan = rand() %(a.renchanAll);  //連チャンの可否はここで決まる
        if (renchan == 0){                 //連チャンなら0ハズレならend+=1

            printf("\n\n\n");//ここからdelayまでは演出

            for(int k = 1; k <= 7;k++){
                printf("\033[43m\033[31m+-;_;-+:~:*~+-\\ \\-+:~:*~+-;_;-+\033[39m\033[49m\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }

            printf("\033[43m\033[31m+-;_;-+|  ______|:~:+:~:*~+-;_;-+\033[39m\033[49m\n");
                
            for(int k = 1; k <= 7;k++){
                printf("\033[43m\033[31m+-;_;-+:~:*~+-\\ \\-+:~:*~+-;_;-+\033[39m\033[49m\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }
            printf("\n");

            delay(2500);//単位はミリ秒
        
            printf("\n\n  $$$$$$$$$$$$$$$$$$$$$\n");
            printf("  $$$               $$$\n");
            printf("  $   連チャン確定！  $\n");
            printf("  $もう1回BIGボーナス!$\n");
            printf("  $$$               $$$\n");
            printf("  $$$$$$$$$$$$$$$$$$$$$\n");
            
            start = 114514;
            renchan = 114514;
            end = 0;

        } else{

            printf("\n\n\n");//ここからdelayまでは演出
            for(int k = 1; k <= 7;k++){
                printf("+-;_;-+:~:*~+-xxx-+:~:*~+-;_;-+\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }

            for(int k = 1; k <= 7;k++){
                printf("+-;_;-+:~:*~+-xxx-+:~:*~+-;_;-+\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                    }
            }
            printf("\n");

            delay(1000);//単位はミリ秒

            printf("\n\n  -----------------------\n");
            printf("  ##     残念…………      ##\n");
            printf("  ## -BIGボーナス終了- ##\n");
            printf("  ##   獲得枚数%d枚!  ##\n",*medal - startMedal);
            printf("  -----------------------\n");
            end += 1;
            
        }
    }
    return biggames;
}//ここでBIG関数終わり


//REGボーナスに関する関数
int reg (int * medal){

    regSettei a = { 5, 10 , 5 };  /*ラウンド数・1Rあたりの当たりメダル枚数・1/(この数)で連チャン確率を決定する*/
    
    int startMedal = *medal; //メダル枚数計算用
    int start =114514;       //スタートフラグ
    int end = 0;             //エンドフラグ
    int renchan =114514;     //連チャン管理用
    int reggames = 0;

    long numCheck =0;        //入力管理用
    char num[256] ;          //入力管理用
    char *endPointer = NULL; //入力管理用
    
    srand((unsigned)time(NULL));

    //連チャンなら0 ハズレならend+=1
    while(end == 0){

        printf("------------------------------\n");  //regゲームの内容

        for(int i = 0 ; i < (a.round) ; i ++){
            printf("------------------------------\n\n");
            printf("REGボーナスゲーム%dゲーム目!\n",i + 1);
            printf("スロットを回すには0を入力してね!\n");

            

            while (114514){  //入力管理用

                scanf("%255s", num);
                numCheck = strtol(num, &endPointer ,10);

                    if(*endPointer != '\0'){
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("\n数字を入力しなさいよ!\n");
                        printf("スロットを回すなら0を入力してね!\n");
                        continue;

                    }if (numCheck == 0){
                        start = 0;
                        delay(500);
                        break;
                    }else if (numCheck == 8){
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("\nせっかくREGボーナスが当たってるんだから回しなさいよ!\n");
                        printf("スロットを回すなら0を入力してね!\n");
                    }else{
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("\n準備してから入力しなさいよ!\n");
                        printf("スロットを回すなら0を入力してね!\n");
                    }
            }  //入力管理用終わり

            printf("\n\n\n\n\n");
            printf("\n  [{[{  R E G BONUS  }]}]\n");
            printf("  #=-_-_-=~*$*~=-_-_-_-=#\n");
            printf("  #| [7] | [7] | [BAR] |#\n");
            printf("  #=-_-_-=~*$*~=-_-_-_-=#\n  ");
                for( int j = 0; j < i + 1 ; j ++){
                    printf("*-*-");
                }
            printf("*-*\n    メダル10枚獲得!\n\n\n\n\n\n");
            *medal += (a.atariMedal);
            reggames += 1;
        
        }//regボーナスの1週分ここで終わり

        printf("------------------------------\n");
        printf("REGボーナスゲーム終了!\n次のレバーオンで連チャンを引き当てろ!\n0を入力してレバーオンだ!\n");

        
        while (114514){    //入力管理用
            scanf("%255s", num);
            numCheck = strtol(num, &endPointer ,10);

                if(*endPointer != '\0'){
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\n数字を入力しなさいよ!\n");
                    printf("レバーオンなら0を入力してね!\n");
                    continue;

                }if (numCheck == 0){
                    start = 0;
                    break;

                }else if (numCheck == 8){
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\n連チャンチャレンジなんだから回しなさいよ!\n");
                    printf("スロットを回すなら0を入力してね!\n");

                }else{
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\n準備してから入力しなさいよ!\n");
                    printf("レバーオンなら0を入力してね!\n");

                }
        }//入力管理用終わり

        renchan = rand() %(a.renchanAll);
        //連チャンなら0 ハズレならend+=1
        if (renchan == 0){

            printf("\n\n\n");//ここからdelayまでは演出
            for(int k = 1; k <= 7;k++){
                printf("+-;_;-+:~:*~+-!-+:~:*~+-;_;-+\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }

            delay(2000);//単位はミリ秒

            printf("\n\n  $$$$$$$$$$$$$$$$$$$$$\n");
            printf("  $$$               $$$\n");
            printf("  $   連チャン確定！  $\n");
            printf("  $もう1回REGボーナス!$\n");
            printf("  $$$               $$$\n");
            printf("  $$$$$$$$$$$$$$$$$$$$$\n");

            start = 114514;
            renchan = 114514;
            end = 0;
        } else{

            printf("\n\n\n");//ここからdelayまでは演出
            for(int k = 1; k <= 7;k++){
                printf("+-;_;-+:~:*~+-xxx-+:~:*~+-;_;-+\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }

            delay(1000);//単位はミリ秒

            printf("\n\n  -------------------------\n");
            printf("  ##       残念…………      ##\n");
            printf("  ### -REGボーナス終了- ###\n");
            printf("  ####  獲得枚数%d枚! ####\n",*medal - startMedal);
            printf("  -------------------------\n");
            end += 1;
            
        }
    }
    return reggames;

}//ここでreg関数終了



//以下ゲーム本編の関数
int main (void){

    srand((unsigned)time(NULL));

    nomSettei a = { 10 , 5, 1 , 1 };

     /*  全体パターン数 ・ BIG当たりパターン数 ・REGパターン数・チェリーのパターン数
        ・1以上の整数を入力すること
        ・全体パターン数> BIGパターン数 + REGパターン数 + チェリーパターン数にすること

        <例>　実働パターン(設定6) 350 , 10 , 10 , 50
        <例>　実働パターン(設定1) 350 , 5 , 5 , 20
     　 テスト設定 20 , 1 , 1 , 3                                                      */
    
    int medal = 500;        //メダル枚数
    int hazureNum[3] ={0};  //ハズレ用数字
    int start =114514;      //スタートフラグ

    int gambling = 810;     //当たり管理用数字
    int ending = 0;         //エンドフラグ

    int biggames = 0;   //BIGゲーム数
    int bigTgames = 0;  //トータルBIG数
    int reggames = 0;   //REGゲーム数
    int regTgames = 0;  //トータルREH数
    int cheTgames = 0;  //トータルチェリー数
    int hazTgames = 0;  //トータルハズレゲーム数
    int totalGames = bigTgames + regTgames + cheTgames + hazTgames ; //上記の和

    long numCheck =　0　;         //入力管理用
    char num[256] ;           //入力管理用
    char *endPointer = NULL;  //入力管理用

    //茶番パート開始
    printf("\n\n");
    printf("   ####################\n");
    printf("   ##                ##\n");
    printf("   #  NOW LOADING...  #\n");
    printf("   ##                ##\n");
    printf("   ####################\n\n");
    printf("   ");//progresバー用

    for(int m = 0 ; m < 10 ; m ++){
      
        printf("@@");
        delay(500);
      
    }

    printf("\n\n\n-----------------------------------------------------------------\n\n");
    printf("      　XXX--スロットゲーム--XXX\n");
    printf("             --ルール説明--\n\n");
    printf("      ･スタート時のメダルは500枚\n");
    printf("      ･1回スロットを回すのにメダルを3枚使用する\n");
    printf("      ･持ちメダルが3枚未満になったらゲームオーバー\n");
    printf("      ･BIGボーナスゲームやREGボーナスゲームを引いて\n       メダルをジャンジャン稼ごう！\n");
    printf("\n  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n  皆様がご存知のスロットはボタンを3つ押してリールを止めるもの\n");
    printf("    だと思いますが今回はワンボタンでリールが3つ止まる\n");
    printf("  スタイルのものになっています。遊びやすくて最高ですね！\n");
    printf("\n  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("-----------------------------------------------------------------\n");
    
    printf("\n準備はいい？\n始めるなら0を入力してね!\n");

    while (114514){     //入力管理用

        scanf("%255s", num);
        numCheck = strtol(num, &endPointer ,10);

        if(*endPointer != '\0'){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n\n数字を入力しなさいよ!\n");
            printf("準備はいい？\n始めるなら0を入力してね!\n");
            continue;

        }if (numCheck == 0){
            break;

        }else{
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n\n準備してから入力しなさいよ!\n");
            printf("準備はいい？\n始めるなら0を入力してね!\n");

        }
    }   //入力管理用終わり
    
    printf("------------------------------\n");
    printf("\nゲームを始めるよ!\nリールを回すには0を入力してね!\n終了する時には8を入力してね!\n");


    while (114514){  //入力管理用

        scanf("%255s", num);
        numCheck = strtol(num, &endPointer ,10);

        if(*endPointer != '\0'){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n\n数字を入力しなさいよ!\n");
            printf("準備はいい？\n始めるなら0を入力してね!\n");
            continue;

        }if (numCheck == 0){
            start = 0;
            break;

        }else if (numCheck == 8){
            start = 8;
            break;

        }else{
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n\n準備してから入力しなさいよ!\n");
            printf("準備はいい？\n始めるなら0を入力してね!\n");
        }
    }  //入力管理用終わり
    
    //ゲームを続けるなら0 終了なら8
    while(start == 0){

        if ( numCheck == 0){
            medal -= 3;
        }

        gambling = rand()% (a.gamblingAll)+1 ;//抽選開始

        if ( gambling >= 1 && (a.big)>= gambling ){//BIG当選

            printf("\n\n\n");//ここからdelayまでは演出

            for(int k = 1; k <= 7;k++){
                printf("\033[43m\033[31m+-;_;-+:~:*~+-\\ \\-+:~:*~+-;_;-+\033[39m\033[49m\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }

            printf("\033[43m\033[31m+-;_;-+|  ______|:~:+:~:*~+-;_;-+\033[39m\033[49m\n");
                
            for(int k = 1; k <= 7;k++){
                printf("\033[43m\033[31m+-;_;-+:~:*~+-\\ \\-+:~:*~+-;_;-+\033[39m\033[49m\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }
            printf("\n\n\n");

            delay(2000);//単位はミリ秒
            
            printf("\n\n  =========================\n");
            printf("  ||      大当たり！      ||\n");
            printf("  | BIGボーナスゲーム開始! | \n");
            printf("  =========================\n");
            printf("\n   {[{  B I G BONUS  }]}\n");
            printf("   #*~+~*~+=~~~=+~*~+~*#\n");
            printf("   #| [7] | [7] | [7] |#\n");
            printf("   #*~+~*~+=~~~=+~*~+~*#\n");

            biggames = big (&medal); //BIG関数へ
            bigTgames += biggames;    //BIGゲーム数記録用

        }else if (gambling > (a.big) && gambling <= (a.reg) + (a.big)){//REG当選

            printf("\n\n\n");//ここからdelayまでは演出
            for(int k = 1; k <= 7;k++){
                printf("+-;_;-+:~:*~+-!-+:~:*~+-;_;-+\n");

                for(int l = 0; l < k ;l++){
                    printf(" ");
                }
            }
            printf("\n\n\n");
            delay(1500);//単位はミリ秒
            
            printf("\n\n  =========================\n");
            printf("  ||       当たり！      ||\n");
            printf("  | REGボーナスゲーム開始!| \n");
            printf("  =========================\n");
            printf("\n   [{[{  R E G BONUS  }]}]\n");
            printf("   #=-_-_-=~*$*~=-_-_-_-=#\n");
            printf("   #| [7] | [7] | [BAR] |#\n");
            printf("   #=-_-_-=~*$*~=-_-_-_-=#\n");

            reggames = reg (&medal); //REG関数へ
            regTgames += reggames;   //REGゲーム数記録用    
            
        }else if ( (a.reg) + (a.big) < gambling && gambling <= (a.reg) + (a.big) +(a.cherry)){//チェリー当選

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//画面遷移を表現
            printf(" #*~+~*~+=~~~~~=+~*~+~*#\n");
            printf("#| .抽。 | .選｡ | .中｡ |#\n");
            printf(" #*~+~*~+=~~~~~=+~*~+~*#\n");
            printf("\n\n\n\n");

            delay(1000);
            printf("\n\n\n- - - - - - - - - - - - - - - - - - - - -\n\n\n");
            
            printf("\n      +-チェリー当選-+\n");
            printf("  ==========================\n");
            printf("  #|      小当たり！      |#\n");
            printf("  |  チェリー.人。ゲット！  | \n");
            printf("  ==========================\n");
            printf("   #*~+~*~+=~~~~~=+~*~+~*#\n");
            printf("  #| .人。 | .人｡ | .人｡ |#\n");
            printf("   #*~+~*~+=~~~~~=+~*~+~*#\n\n\n");
            printf("       メダル10枚獲得\n");

            medal += 13;    //チェリーの増加枚数(コイン消費を打ち消すために+3する)
            cheTgames += 1; //ゲーム数記録用
        
        }else{//ハズレ当選

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//画面遷移をこれで表現
            printf("  #*~+~*~+=~~~~~=+~*~+~*#\n");
            printf(" #| .抽。 | .選｡ | .中｡ |#\n");
            printf("  #*~+~*~+=~~~~~=+~*~+~*#\n");
            printf("\n\n\n\n\n\n");

            delay(1000);
            printf("\n\n- - - - - - - - - - - - - - - - - - - - -\n\n\n");

            hazureNum[0] = rand()%9 +1;
            hazureNum[1] = rand()%9 +1;
            hazureNum[2] = rand()%9 +1;

            while(hazureNum[1] == hazureNum[2]){ //中・右の数字が揃わないように処理する

                hazureNum[2] = rand()%9 +1;

            }

            printf("\n  [[[ ………ハズレ………… ]]]\n");
            printf("  #=-_-_-=~*$*~=-_-_-=#\n");
            printf("  #| [%d] | [%d] | [%d] |#\n",hazureNum[0],hazureNum[1],hazureNum[2]);
            printf("  #=-_-_-=~*$*~=-_-_-=#\n\n\n");

            hazTgames += 1;//ハズレゲーム数記録用
            
        }  //当選管理終了

        start = 114514;
        gambling =114514;

        if(medal<3){  //メダルが3枚未満なら終了
            break;

        } 
            
        printf("\n\n----*現在の所持メダル枚数は%d枚!*----\n\n",medal);
        printf(" リールを回すには0を入力してね!\n  終了する時には8を入力してね!\n\n");

        
        while (114514){  //入力管理用
    
        scanf("%255s", num);
        numCheck = strtol(num, &endPointer ,10);
    
            if(*endPointer != '\0'){
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\n\n数字を入力しなさいよ!\n");
                printf("リールを回すなら0を入力してね!\n終了する時には8を入力してね!\n\n");
                continue;

            }if (numCheck == 0){
                start = 0;
                break;

            }else if (numCheck == 8){
                start = 8;
                break;

            }else{
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\n\n準備してから入力しなさいよ!\n");
                printf("リールを回すなら0を入力してね!\n終了する時には8を入力してね!\n\n");

            }
        } //入力管理用終わり
    } //ゲーム本編終わり

    /*FILE* fp;//ファイル書き込み

    fp = fopen("test.csv", "w");

    fprintf(fp, "トータルゲーム数,BIGBONUS数,REGBONUS数,Cherry数,合計獲得メダル枚数\n");
    fprintf(fp, "%d,%d,%d,%d,%d\n",totalGames,bigTgames,regTgames,cheTgames,medal-500);
    
    fclose(fp); 書き込み終わり */


    //リザルト画面
    totalGames = bigTgames + regTgames + cheTgames + hazTgames ;
    printf("========================================\n"); 
    printf("      ゲーム終了！\n");
    printf("       +RESULTS+\n");
    printf("   Total Games: %d G\n",totalGames);
    printf("    BIG  BOUNS: %d G\n",bigTgames);
    printf("    REG  BONUS: %d G\n",regTgames);
    printf("      Cherry  : %d times\n",cheTgames);
    printf("合計メダル枚数: %d枚\n",medal);
    printf("  --獲得枚数--  %d枚\n\n",medal - 500);

    //エンディングに流すコメント管理用
    if ( medal < 400 ){ 
        ending = 0;

    } else if( medal < 500  && medal >= 400){ 
        ending = 1 ;

    } else if (medal >= 500 && medal < 10000){
        ending = 2;

    } else if ( medal >= 10000){
        ending = 3;

    }
    
    //エンディングに流すコメント
    switch (ending){

        case 0:
            printf("タコ負けですね笑\nまたのご来店をお待ちしております笑\n");
            break;

        case 1:
            printf("やや負けですね…\n次はきっと勝てますよ!\nまたのご来店をお待ちしております!\n");
            break;

        case 2:
            printf("おめでとうございます！\n次はもっとメダルを出してくださいね!\n");
            break;

        case 3:
            printf("こんなにメダルを出した人は初めてです…！\nおめでとうございます!\n");
            break;

        default:
            printf("何をしたの！？\n");
            break;

        }

    printf("======================================\n");
    
    return 0;
}

#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std ;
struct line_1_2 {
    int line_1 [4];
    int line_2 [4];
};

struct balls_with_num {
    int ball[6][6] = {//تعریف رنگ توپ ها و دورنگ بودن یا نبودن - سطر اول همگی 0 مشکلی نداره - اولین هر کدام رنگ اصلی - آخری بمب دار
            {0, 0, 0, 0, 0, 0},
            {1, 9, 10, 13, 14, 17},//رنگ سبز
            {2, 6, 11, 13, 15, 19},//زرد
            {3, 6, 7, 8, 9, 18},//قرمز
            {4, 8, 12, 14, 15, 20},//بنفش
            {5, 7, 10, 11, 12, 21}//آبی
    };
};

using namespace std;


void first_second_line(line_1_2 &line) {
    for (int i = 0; i < 4; i++) {
        line.line_1[i] = rand() % 5 + 1;
        line.line_2[i] = rand() % 5 + 1;
    }
}
int random_line(int list [3]) {//تولید خطوط به صورت رندم
    srand(time(0));
    balls_with_num balls ;
    int list_1[22];
    for(int i = 0 ; i<22 ; i++)
        list_1[i]=0 ;
    //****************
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);
    //الگوریتم بهینه تر برای تولید اعداد رندم (gpt)
    //*********************************
    for(int i = 0 ; i<3 ; i++) {
        int random_num_between_0_100=0 ;
        int random_num;
        //**************************
        if (list[i]==0 && i==0 ){
            random_num = rand() % 21 + 1;
            return (random_num/2)+1;
        }
        //اگه یکی از اعداد ابتدا و انتها بازه بود عدد داده شده کلا رندم باشه
        //******************************
        if (list[i]<=5 && list[i]>=1) { //اگه توپ معمولی بود
            random_num_between_0_100= dis(gen);
            if (random_num_between_0_100 >= 0 && random_num_between_0_100 < 10)//10 درصد احتمال آمدن همون رنگ توپ
                list_1[list[i]] += 1;
            if (random_num_between_0_100 >= 10 && random_num_between_0_100 < 20) {//10 درصد احتمال اومدن توپ رنگی همون
                random_num = rand() % 5 + 1;
                list_1[balls.ball[list[i]][random_num]] += 1;
            }
            if (random_num_between_0_100 >= 20 && random_num_between_0_100 < 25) {//احتمال اومدن توپ قفل شده همون
                list_1[balls.ball[list[i]][5]] += 1;
            }
            if (random_num_between_0_100 >= 25) {//یک رنگ توپ ساده دیگه 75 درصد
                random_num = rand() % 5 + 1;
                if (random_num == 5)
                    list_1[16] += 1;
                else
                    list_1[random_num]+=1 ;
            }
        }//توپ های ساده
        if (list[i]>6 && list[i]<=15) {
            int ball_1 = 0, ball_2 = 0;
            for (int z = 1; z < 6; z++) {
                for (int o = 0; o < 6; o++) {
                    if (balls.ball[z][o] == list[i] && ball_1 == 0)
                        ball_1 = z;
                    else if (balls.ball[z][o] == list[i] && ball_1 != 0)
                        ball_2 = z;
                }
            }
            random_num_between_0_100= dis(gen);
            if (random_num_between_0_100 >= 0 && random_num_between_0_100 < 10)//10 درصد توپ رنگی اول
                list_1[ball_1] += 1;
            if (random_num_between_0_100 >= 10 && random_num_between_0_100 < 20)//10 درصد توپ رنگی دوم
                list_1[ball_2] += 1;
            if (random_num_between_0_100 >= 20 && random_num_between_0_100 < 35)// 15 درصد خودش
                list_1[list[i]] += 1;
            if (random_num_between_0_100 >= 35) {//65 درصد رندوم یه چیز دیگه
                random_num = rand() % 21 + 1;
                list_1[random_num] += 1;
            }
        } // توپ های دورنگ
        if (list[i]==16) {
            random_num_between_0_100= dis(gen);
            if (random_num_between_0_100 < 10)//10 درصد خودش
                list_1[16] += 1;
            if (random_num_between_0_100 >= 10 && random_num_between_0_100 < 100) {//80 درصد یه چیز دیگه
                random_num = rand() % 21 + 1;
                list_1[random_num] += 1;
            }
        }//توپ مشکی
        if(list[i]>16 && list[i]<=21) {
            random_num_between_0_100= dis(gen);
            if (random_num_between_0_100 <= 50) {//50 درصد خودش
                list_1[list[i]] += 1;
            }
            else if (random_num_between_0_100 < 70) {//20 درصد توپ ساده از خودش
                int ball_1 = 0;
                for (int z = 1; z < 6; z++) {
                    for (int o = 0; o < 6; o++) {
                        if (balls.ball[z][o] == list[i])
                            ball_1 = z;
                    }
                }
                list_1[ball_1] += 1;
            }
            if (random_num_between_0_100 > 70){//30 درصد یه چیز دیگه
                random_num = rand() % 21 + 1;
                list_1[random_num] += 1;
            }


        }//توپ قفل دار

            }
    int x_1=0 , x_2=0,x_3=0 ;
    for(int i = 0 ; i<22 ;i++) {
        if(list_1[i]>=2)//اگه دو عدد یکسان همون جا پایان
            return i;
        else if(list_1[i]==1 && x_1 ==0)
            x_1 = i;
        else if(list_1[i]==1 && x_1 !=0 && x_2 ==0 )
            x_2 = i ;
        else if(list_1[i]==1 && x_1 !=0)
            x_3 = i ;
    }
    //************************
    int color[3][2];
    int color_2 [6];
    for(int i = 0 ; i<6  ; i++)
        color_2[i]=0 ;
    for(int i = 0 ; i<3;i++)
        for(int j = 0 ; j<2 ; j++)
            color[i][j]=0 ;
    for (int z = 1; z < 6; z++) {
        for (int o = 0; o < 6; o++) {
            if (balls.ball[z][o] == x_1 && color[0][0] == 0)
                color[0][0] = z;
            else if (balls.ball[z][o] == x_2 && color[0][0] != 0 && color[1][0]==0)
                color[1][0] = z;
            else if (balls.ball[z][o] == x_3 && color[1][0] != 0)
                color[2][0] = z;
        }
    }
    //پیدا کردن رنگ یکسان
//********************************

    for (int z = 0; z < 3; z++) {
        color_2[color[z][0]]+=1 ;
    }
    for(int i = 0 ; i<6  ; i++){
        if(color_2[i]>=2 && i!=0)
            return i ;
    }
    //*********************
    int hazf_x = 0 ;
    if (x_3==0)
        hazf_x=1;
    int randnum = rand()%(3-hazf_x)+1;
    switch (randnum) {
        case 1 :
            return x_1 ;
        case 2:
            return x_2 ;
        case 3 :
            return x_3 ;
    }
    //اگه دو تا رنگ یکی هم ندیدیم یکی از بین اونا رندم انتخاب میکنیم
    //***********************

}



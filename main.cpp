#include <iostream>
#include "C:\function\screen\main.cpp"

using namespace std ;

void list_toop_ha(int list [13][10],double & enteghali,int width,int &c,int mouse_x,int mouse_y ) { // از 13 ردیف دو ردیف در بالای صفحه و ردیف آخر در زیر border تعریف میشه
    if (enteghali > width * .08) {
        for (int i = 12; i > 0; i--) {
            swap(list[i], list[i - 1]);
        enteghali=0.1 ;

        }

        for (int j = 0; j < 10; j++) {
            int zir_list[3];
            if (j == 0) {
                zir_list[0] = 0;
                zir_list[1] = list[1][j];
                zir_list[2] = list[1][j + 1];
            } else if (j < 9) {
                zir_list[0] = list[0][j - 1];
                zir_list[1] = list[1][j];
                zir_list[2] = list[1][j + 1];
            } else if (j == 9) {
                zir_list[0] =  list[0][j - 1];
                zir_list[1] = list[1][j];
                zir_list[2] = 0 ;
            }
            srand(j*time(0)-j+10*mouse_x-4*mouse_y);
            list[0][j] = random_line(zir_list);

        }
        c+=1 ;//برای به هم نریختن هنگام سوییچ
        c%=2 ;

    }
}
void line_cannon(int x_mouse , int y_mouse ) {
    int x1 = 530;
    int y1=745 ;
    
}
int cannon_random(int list[13][10],int mouse_x) {
    bool zirlist[6];
    for(int i = 0 ; i<5 ; i++)
        zirlist[i]=0;
    for(int i = 0 ;i<13 ; i++){
        for(int j = 0 ; j<10 ;j++) {
            switch(list[i][j]) {
                case 1 :
                    zirlist[1]=1;
                    break ;
                case 2 :
                    zirlist[2]=1;
                    break ;
                case 3 :
                    zirlist[3]=1;
                    break ;
                case 4 :
                    zirlist[4]=1;
                    break ;
                case 5 :
                    zirlist[5]=1;
                    break ;
                case 6 :
                    zirlist[2]=1;
                    zirlist[3]=1;
                    break ;
                case 7 :
                    zirlist[5]=1;
                    zirlist[3]=1;
                    break ;
                case 8 :
                    zirlist[4]=1;
                    zirlist[3]=1;
                    break ;
                case 9 :
                    zirlist[1]=1;
                    zirlist[3]=1;
                    break ;
                case 10 :
                    zirlist[1]=1;
                    zirlist[5]=1;
                    break ;
                case 11 :
                    zirlist[2]=1;
                    zirlist[5]=1;
                    break ;
                case 12 :
                    zirlist[4]=1;
                    zirlist[5]=1;
                    break ;
                case 13 :
                    zirlist[1]=1;
                    zirlist[2]=1;
                    break ;
                case 14 :
                    zirlist[1]=1;
                    zirlist[4]=1;
                    break ;
                case 15 :
                    zirlist[2]=1;
                    zirlist[4]=1;
                    break ;
                case 17 :
                    zirlist[1]=1;
                    break ;
                case 18 :
                    zirlist[3]=1;
                    break ;
                case 19 :
                    zirlist[2]=1;
                    break ;
                case 20 :
                    zirlist[4]=1;
                    break ;
                case 21 :
                    zirlist[5]=1;
                    break ;



            }
        }
    }
    int counter = 0 ;
    for(int i = 0 ; i<5 ; i++){
        if(zirlist[i]==1)
            counter++;
    }
    srand(mouse_x*time(0));
    int rand_num= rand() % counter + 1;
    int c = 0;
    while(rand_num>0) {
        if (zirlist[c] == 1) {
            rand_num--;
        }
        c++;

    }
    return c ;



}


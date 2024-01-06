#include <iostream>
#include "C:\function\screen\main.cpp"
using namespace std ;

void list_toop_ha(int list [13][10],double & enteghali,int width,int &c ) { // از 13 ردیف دو ردیف در بالای صفحه و ردیف آخر در زیر border تعریف میشه
    if (enteghali > width * .08) {
        for (int i = 12; i > 0; i--) {
            swap(list[i], list[i - 1]);
        }
        enteghali=0 ;

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
            list[0][j] = random_line(zir_list);

        }
        c+=1 ;//برای به هم نریختن هنگام سوییچ
        c%=2 ;

    }
}

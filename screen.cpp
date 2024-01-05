#include<bits/stdc++.h>
using namespace std ;

struct line_1_2 {
    int line_1 [4];
    int line_2 [3];
};

void first_second_line( line_1_2 & line ){
    srand(time(0));
    for(int i = 0 ; i<4 ; i++) {
        line.line_1[i]=rand() %5 +1 ;
        line.line_2[i]=rand() %5 +1;
    }

}

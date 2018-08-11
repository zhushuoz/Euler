/*************************************************************************
	> File Name: 33.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月28日 星期六 11时36分53秒
 ************************************************************************/

#include <stdio.h>

int gcd(int x, int y){
    if ( y % x == 0) return x;
    return gcd(y % x, x);
}
int main() {
    int xx = 1, yy = 1;
    for (int a = 1; a < 10; a++){
        for (int b = 1; b < 10; b++){
            for (int c = a + 1; c < 10; c++)
            if((a * 10 + b) * c == (b * 10 + c) * a){
                printf ("%d %d %d\n", a, b, c);
                xx *= a;
                yy *= c;
            }
        }

    }
    printf ("%d", yy / gcd(xx, yy));


    return 0;
}

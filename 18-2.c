/*************************************************************************
	> File Name: 18-2.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月29日 星期日 14时55分35秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) >(b) ? (a) : (b))
#define MAX_N 15

int keep[MAX_N + 5][MAX_N + 5];
//动态规划  keep[i][j]表示从最后一行到点(i, j)的最大值
int main() {
    int ans = 0;
    for (int i = 0; i < MAX_N; i++){
        for (int j = 0; j <= i; j++)
        scanf("%d", &keep[i][j]);
    }
    /*for (int i = 0; i < MAX_N; i++){
        for (int j = 0; j <= i; j++){
            printf("%d  ", keep[i][j]);
        }
        printf("\n");
    }*/
    for (int i = MAX_N - 2; i >= 0; i--){
        for (int j = 0; j <= i; j++ ){
            keep[i][j] += max(keep[i + 1][j], keep[i + 1][j + 1]);
        }

    }
    printf("%d\n", keep[0][0]);
    return 0;

}

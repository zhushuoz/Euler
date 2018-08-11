/*************************************************************************
	> File Name: 18-3.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月29日 星期日 15时27分52秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX_N 15

int keep[MAX_N + 5][MAX_N + 5];

int main() {
    int ans = 0;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &keep[i][j]);
        }
    }

    for (int i = 1; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 && (keep[i][j] += keep[i - 1][0])) continue;
            if (j == i && (keep[i][j] += keep[i - 1][j - 1])) continue;
            keep[i][j] += max(keep[i - 1][j], keep[i - 1][j - 1]);
        }

    }

    for (int i = 0; i < MAX_N; i++){
        if (ans < keep[MAX_N - 1][i])
        ans = keep[MAX_N - 1][i];
    }
    printf("%d\n", ans);


    return 0;
}

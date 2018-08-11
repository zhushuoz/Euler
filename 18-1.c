/*************************************************************************
	> File Name: 18.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月29日 星期日 14时40分49秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 15
//递归加记忆化
int map[MAX_N + 5][MAX_N + 5];
int keep[MAX_N + 5][MAX_N + 5];

int solve(int i, int j){
    if (i == MAX_N) return 0;
    if (keep[i][j]) return keep[i][j]; 
    int lnum = solve(i + 1, j), rnum = solve(i + 1, j + 1);
    keep[i][j] = (lnum > rnum ? lnum : rnum) + map[i][j];
    //记忆化的过程 保证每个位置只求一次
    return keep[i][j];
}


int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++)
        scanf("%d", &map[i][j]);
    }
    printf("%d\n", solve(0, 0));
    return 0;
}

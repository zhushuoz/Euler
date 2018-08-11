/*************************************************************************
	> File Name: 31-1.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月27日 星期五 21时11分26秒
 ************************************************************************/

#include <stdio.h>
#define MAX_W 201


// 数组降维
int dp[MAX_W] = {0};
int w[8] = {1, 2, 5, 10, 20, 50, 100, 200};


int main() {
    dp[0] = 1;
    for (int i = 0; i < 8; i++){
        for (int j = w[i]; j < MAX_W; j++){
            dp[j] += dp[j - w[i]];
        }
    }
    printf("%d\n", dp[MAX_W - 1]);
    return 0;
}

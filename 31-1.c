/*************************************************************************
	> File Name: 31.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月27日 星期五 11时50分00秒
 ************************************************************************/

#include <stdio.h>
#define MAX_W 201

int dp[8][MAX_W] = {0}; //dp[i][j] 表示用前i种钱币组成j元钱有多少种方式
int w[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

int main() {
  //  dp[0] = 0;
    for (int i = 1; i <= 8; i++){
        for (int j = 0; j < MAX_W; j++){

            if (j == 0){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] < 0) continue;
            dp[i][j] += dp[i][j - w[i]];
        }
    }

    printf("%d\n", dp[8][200]);

    

    return 0;
}

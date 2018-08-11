/*************************************************************************
	> File Name: 16.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月26日 星期四 23时33分20秒
 ************************************************************************/

#include <stdio.h>
//大数乘法
int main() {
    int ans[400] = {1, 2}, sum = 0;//初始化为2
    for (int i = 2; i <= 1000; i++){
        for (int j = 1; j <= ans[0]; j++){
            ans[j] <<= 1;//各位左移一位
        }

        for (int j = 1; j <= ans[0]; j++){
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            if (j == ans[0] && (ans[0]++));//进位
        }


    }
    for (int i = 1; i <= ans[0]; i++ )
        sum += ans[i];

    printf("%d\n", sum);





    return 0;
}

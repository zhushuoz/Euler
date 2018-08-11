/*************************************************************************
	> File Name: 6.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月22日 星期日 09时48分50秒
 ************************************************************************/

#include <stdio.h>
int main() {
    int sum1 = 0, sum2 = 0, n = 100;
    for (int i = 1 ; i <= n; i++){
        sum1 += i;
        sum2 += i * i;
    }
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;

}

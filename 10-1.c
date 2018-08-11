/*************************************************************************
	> File Name: 7-1.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月24日 星期二 10时32分51秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 2000000
#include <inttypes.h>
int prime[MAX_N + 5] = {0};
//小于两百万素数的和

int main () {
    int64_t ans = 0;
    for (int i = 2; i <= MAX_N; i++){
        if (!prime[i]){
            ans += i;
            prime[++prime[0]] = i;
        }

        for (int j = 1; j <= prime[0] && prime[j] * i <=MAX_N; j++){
            prime [i * prime[j]] = 1;
            if (i % prime[j] == 0)  break;            
        }
    }

    printf("%" PRId64 "\n", ans);    



        
}

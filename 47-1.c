/*************************************************************************
> File Name: 47.c
> Author: zhushuo
> Mail: 
> Created Time: 2018年08月01日 星期三 10时38分35秒
************************************************************************/




#include <stdio.h>

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};//素数数组
int dnum[MAX_N + 5] = {0};//dnum[i]表示i的质因数

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) { 
            prime[++prime[0]] = i; 
            dnum[i] = 1;//质数的质因子只有一个
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            dnum[prime[j] * i] = dnum[i] + (i % prime[j] != 0);//若i%prime[j]!=0 表示priem[j]是i的质因子
            if (i % prime[j] == 0) {
                break;
            }

        }

    }
    for (int i = 1; i <= MAX_N - 3; i++) {
        if (dnum[i] < 4) continue;
        if (dnum[i + 1] < 4) continue; 
        if (dnum[i + 2] < 4) continue;
        if (dnum[i + 3] < 4) continue;
        printf("%d\n", i);
        break;

    }
    return 0;

}

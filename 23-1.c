/*************************************************************************
	> File Name: 23.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年08月06日 星期一 21时24分20秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_N 100000
#define MAX_K 28123
int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};
int mnum[MAX_N +5] = {0};

int init() {
    for (int i = 2; i < MAX_N; i++){
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i + 1;
        }
        for (int j = 1; j <= prime[0]; j++){
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0){
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] * (1 - pow(prime[j], mnum[i] + 2)) / (1 - pow(prime[j], mnum[i] + 1));
                break;
            }else{
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
                mnum[i * prime[j]] = 1;
            }
        }
    }
}

int main() {
    init();
    int ans = 0;
    dnum[0] = 0;
    for (int i = 2; i < MAX_K; i++){
        if (dnum[i] - i > i)
        dnum[++dnum[0]] = i;
    }
    memset(prime, 0, sizeof(prime));
    for (int i = 1; i <= dnum[0]; i++){
        for (int j = i; j <= dnum[0]; j++){
            if (dnum[i] + dnum[j] > MAX_K) break;
            prime[dnum[i] + dnum[j]] = 1;
        }
    }
    for (int i = 1; i <= MAX_K; i++){
        if (!prime[i])
        ans += i;
    }
    printf("%d\n", ans);

    return 0;
}

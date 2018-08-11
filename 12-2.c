/*************************************************************************
	> File Name: 12-3.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月30日 星期一 14时21分33秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100000
int prime[MAX_N] = {0};//记录素数
int dnum[MAX_N] = {0};//记录最小素因子的因子个数
int mnum[MAX_N] = {0};//记录最小素因子的幂次

int init() {
    for (int i = 2; i * 2<= MAX_N; i++){
        if (!prime[i]){ //如果为素数
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++){
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0){
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            }else{//两个数互质
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
                mnum[i * prime[j]] = 1;
            }


        }

    }
    return 1;
}
int factor_nums(int n){
    if (n & 1){
        return dnum[n] * dnum[(n + 1) / 2];
    }
    return dnum[n / 2] * dnum[n + 1];
}

int main() {
    init();
    int i = 2;
    while(factor_nums(i) < 500) i++;
    printf("%d\n", i * (i + 1) / 2);


    return 0;
}

/*************************************************************************
	> File Name: test_3.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年08月06日 星期一 16时20分12秒
 *************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 100000
int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};//因子和
int mnum[MAX_N + 5] = {0};//最小质因子的幂次方
int jnum[MAX_N + 5] = {0};//因子个数

void init() {
    for (int i = 2; i < MAX_N; i++){
        if (!prime[i]){
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i + 1;
            jnum[i] = 2;
        }
        for (int j = 1; j <= prime[0]; j++){
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0){
                jnum[i * prime[j]] = jnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                dnum[i * prime[j]] = dnum[i] * (1 - pow(prime[j], mnum[i] + 2)) / (1 - pow(prime[j], mnum[i] + 1));
                mnum[i * prime[j]] = mnum[i] + 1;

                break;
            }else{
                jnum[i * prime[j]] = jnum[i] * jnum[prime[j]];
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
                mnum[i * prime[j]] = 1;
            }
        }
        


    }


}


int main() {
    init();
    for (int i = 2; i < 100; i++)
    printf("%d %d %d\n", i, jnum[i], dnum[i]);




    return 0;
}

/*************************************************************************
> File Name: 21-1.c
> Author: zhushuo
> Mail: 
> Created Time: 2018年08月04日 星期六 20时40分18秒
************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};//因子和
int mnum[MAX_N + 5] = {0};//最小质因子的幂次方
void init() {
    for (int i = 2; i <= MAX_N; i++){
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1 + i;
            mnum[i] = i;//只有两个因子　1和本身

        } 
        for(int j = 1; j <= prime[0]; j++){
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {

                if (i == mnum[i]) {
                    dnum[i * prime[j]] = dnum[i] + i * prime[j];

                }else{
                    dnum[i * prime[j]] = dnum[i / mnum[i]] * dnum[mnum[i] * prime[j]];

                }
                mnum[i * prime[j]] = mnum[i] * prime[j];
                break;

            }
            dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];//互质的情况
            mnum[i * prime[j]] = prime[j];

        }
    }

}

int main() {
    init();
    int ans = 0;
   /* for (int i = 2; i < 100; i++){
        printf("%d  %d  %d\n",i, dnum[i], mnum[i]);

    }*/
    for (int i = 2; i < MAX_N; i++){
        dnum[i] -= i;
    }

    for (int i = 2; i < MAX_N; i++){
        if (dnum[i] < MAX_N && i == dnum[dnum[i]] && i != dnum[i]) {
            ans += i;
            printf("%d %d %d\n", i, dnum[i], dnum[dnum[i]]);       

        }

    }

    printf("%d\n", ans);

    return 0;


}



/*************************************************************************
	> File Name: euler46.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时42分59秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100000
int is_prime[MAX_N] = {0};
int prime[MAX_N] = {0};
int init(){
    for (int i = 2; i < MAX_N; i++){
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++){
            if (i * prime[j] > MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

}

int main() {
    init();
    int ans = 0;
    for (int i = 35; !ans ; i += 2){
        int flag = 1;
        if(!is_prime[i] ) continue;
        for (int j = 1; j * j * 2< i; j++){
            if (!is_prime[i - 2 * j * j] && (flag = 0)) break;//找到一个使猜想成立的数则跳出循环
        }
        if (flag){
            ans = i;
        }
    }

    printf("%d\n",ans);

    return 0;
}

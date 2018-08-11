/*************************************************************************
	> File Name: 7.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月23日 星期一 16时08分40秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200000

//素数筛
int prime[MAX_N + 5] = {0};

void init(){
    for (int i = 2; i * i<= MAX_N; i++){
          if (prime[i]) continue;
            for (int j = i * i; j <= MAX_N; j += i)
            prime[j] = 1;
    }
    for (int i = 2; i <= MAX_N; i++){
        if (prime[i])  continue;
        prime[prime[0]++] = i;
 
    }
    return ;
}


int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}

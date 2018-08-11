/*************************************************************************
	> File Name: 37.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月28日 星期六 16时15分13秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 1000000

int prime[MAX_N] = {0}; 
int is_prime[MAX_N] = {0};

void if_prime (){

for (int i = 2; i < MAX_N; i++){
        if (!is_prime[i] && (prime[++prime[0]] = i));
        for (int j = 1; j <= prime[0] ; j++){
            if (prime[j] * i > MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime [j] == 0) break;
        }
         
    }
}
int digit(int x) {
    
    return floor(log10(x)) + 1;

}


int left(int x){//从左向右截
    int len = digit(x) - 1;
    
        do{
        if (is_prime[x] || x==0) return 0;
        x %= (int)pow(10, len);
    }while(len--);

    return 1;

}


int right(int x) {//从右向左截
    is_prime[1] = 1;

    while(x){
        if (is_prime[x] || x==0) return 0;
        x /= 10;
    }
    return 1;
}


int main() {
    int num = 0,ans = 0;
    if_prime();//建立素数表
    for (int i = 13; num < 11; i++){
        if (!left(i)) continue;
        if (!right(i)) continue;
        printf("%d\n", i);
        ans += i;
        num++;
        
    }
    printf ("%d\n", ans);
    return 0;
}


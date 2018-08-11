/*************************************************************************
	> File Name: 35.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月28日 星期六 12时13分46秒
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

int is_digit(int x) {
    
    return floor(log10(x)) + 1;

}


int main() {

    if_prime();//素数表

    int ans = 0;
    for (int i = 2; i <= MAX_N; i++){
        int len = is_digit(i); //计算i的位数
        int num = i, j;
        for (j = 0; j < len; j++){ //旋转len次
            if (is_prime[num]) break;
            num = num % 10 * (int)pow(10, len - 1) + num / 10;  
        } 
        if (j == len && ans++);
    }
    printf("%d\n",ans);

    return 0;
}

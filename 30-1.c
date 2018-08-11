/*************************************************************************
	> File Name: 30.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月22日 星期日 11时08分17秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 354294

//上界的取值为 当9的五次方 * 7时为一个六位数，即不可能为七位数，最大为六位数 

int is_equal(int x) {
    int temp = 0, sum = x;
    while(sum) {
        temp += (int)pow(sum % 10, 5);
        sum /= 10;
    }
    return temp == x; 
}


int main() {
    int ans = 0;
    for (int i = 2; i <= MAX_N; i++){
        if (!is_equal(i)) continue;
        ans += i;
    }
    
    printf("%d\n", ans);
    return 0;
    
}

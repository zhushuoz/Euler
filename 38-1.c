/*************************************************************************
    > File Name: euler38.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年08月02日 星期四 09时22分28秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
int dnum[10] = {0};

int digit(int x){//计算x的位数
    return floor(log10(x)) + 1;
}


int is_pan(int x){
    while(x) {
        if (x % 10 == 0) return 0; 
        if(dnum[x % 10]) return 0;
        dnum[x % 10] = 1;
        x /= 10;
    }
    return 1;
}


int is_mul(int x) {
    int n = 2, num = x;
    while(digit(num) < 9) {//位数小于九就继续循环
        if(!is_pan(x * n)) return 0;//假如 x * n 不是全数字 返回0
        num = num * (int)pow(10, digit(x * n)) + x * n;//将x * n拼接到num上
        n++;
    }
    if(digit(num) > 9) return 0;//假如结果大于九位数 返回0;

    return num;

}

int main() {
    int ans = 0;
    for (int i = 1; i < 10000; i++){
        memset(dnum, 0, sizeof(dnum));
        if (!is_pan(i)) continue;
        int num = is_mul(i);
     //   if (num) printf("%d\n", num);
        if (num > ans){
            ans = num;
        }
    }

    printf("%d\n", ans);
    


    return 0;
}

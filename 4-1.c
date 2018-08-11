/*************************************************************************
	> File Name: 4-2.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月22日 星期日 09时26分25秒
 ************************************************************************/

#include <stdio.h>

int is_palindromic (int num){
    int temp = 0, x = num;
    while(x){//数字翻转
        temp = temp * 10 + x % 10;
        x /= 10;
    }
    return (temp == num);
}



int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++){
        for (int j = i; j < 1000; j++){
            if (ans > i * j) continue;
            if (!is_palindromic(i * j)) continue;
            ans = i * j;
        }
    }
        printf("%d\n", ans);
 

    return 0;
}

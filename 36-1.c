/*************************************************************************
	> File Name: 36.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月22日 星期日 14时52分28秒
 ************************************************************************/

#include <stdio.h>
int is_palindromic(int x, int n){ //找出n进制下的x的回文数
    int temp = 0, num = x;
    while (num) {
        temp = temp * n + num % n;
        num /= n;
    }
    return temp == x;
}



int main() {
    int ans = 0;
    for (int i = 1; i <= 1000000; i++){
        if (!is_palindromic(i, 10)) continue;
        if (!is_palindromic(i, 2)) continue;
        ans += i;
    }
    printf("%d\n", ans);

    return 0;
}

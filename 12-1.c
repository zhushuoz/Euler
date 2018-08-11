/*************************************************************************
	> File Name: 12-1.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月30日 星期一 10时40分49秒
 ************************************************************************/

#include <stdio.h>
int num(int n){
    return (n + 1) * n / 2;
}

int factor_num(int n) {
    int cnt = 0;
    //暴力求解 找到一个因子加2
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) cnt += 1;
        else if (n % i == 0) cnt += 2;
    }
    return cnt;

}

int main() {
    int n = 1;
    while (factor_num(num(n)) < 500) ++n;
    printf("%d\n", num(n));
    return 0;
}

/*************************************************************************
	> File Name: 3.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月20日 星期五 17时02分46秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define NUM 600851475143

int main() {
    int64_t num = NUM, n = 2, ans = 0;
    while (n * n <= num) { 
    
                if (num % n == 0) ans = n; // n 一定是素数
                while (num % n == 0) num /= n; //将num中因子n除尽       
                n += 1;
    }

    if (num != 1){
        ans = num;
    } // num 一定是素数
        printf("%" PRId64 "\n", ans);
        return 0;
}

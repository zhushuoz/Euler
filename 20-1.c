/*************************************************************************
	> File Name: 20.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月30日 星期一 14时42分22秒
 ************************************************************************/

#include <stdio.h>
//大数乘法
int main() {
    int ans = 0;
    int digit[200] = {1, 1};

    for (int i = 2; i <= 100; i++){
        for (int j = 1; j <= digit[0]; j++)
            digit[j] *= i;
        if (i % 4 != 0) continue;
        for (int j  = 1; j <= digit[0]; j++){
            if (digit[j] < 10) continue;
            digit[j + 1] += digit[j] / 10;
            digit[j] %= 10;
            if (digit[0] += (j == digit[0]));
        }

    }
    for (int i = 1; i <= digit[0]; i++)
        ans += digit[i];
    
    printf("%d\n", ans);



    return 0;
}

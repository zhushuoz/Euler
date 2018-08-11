/*************************************************************************
	> File Name: 9-1.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月30日 星期一 09时52分09秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
//素勾股数
int main() {
    int ans = 0;
    for (int i = 1;!ans; i++){
        for (int j = 1; j < i && !ans; j++){
            int a = 2 * i * j;
            int b = i * i - j * j;
            int c = i * i + j* j;
            if (1000 % (a + b + c) == 0){
                ans = pow(1000 / (a + b + c), 3) * a * b * c;
                printf("%d\n", ans);
            }
                
        }
    }
    return 0;
}

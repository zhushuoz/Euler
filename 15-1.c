/*************************************************************************
	> File Name: 15-1.c
	> Author: zhushuo
	> Mail:
	> Created Time: 2018年08月05日 星期日 11时15分26秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int64_t ans = 1;
    int j = 2;
    for (int i = 21; i <= 40; i++){
        ans *= i;
        while (j <= 20 && ans % j == 0){
            ans /= j;
            j++;
        }
        


    }
    printf("%"PRId64"\n", ans);



}

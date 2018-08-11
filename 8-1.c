/*************************************************************************
	> File Name: 8.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月24日 星期二 11时40分56秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "08.h"
//滑动窗口
int main() {
    char num[1005];
    int64_t p = 1, zero = 0, ans = 0;
   
    for (int i = 0; num[i]; i++){
        if (num[i] - '0'){
            p *= (num[i] - '0');
        }else{
            zero += 1;
        }
        if (i >= 13) {
            if (num[i - 13] - '0')   zero -= 1;
            else  p /= (num[i - 13] - '0');
        }
        if (zero == 0 && p > ans) ans = p;

    }
    
    printf("%" PRId64 "\n", ans); //PRId64 为一个宏

    return 0;
}

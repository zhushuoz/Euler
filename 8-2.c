/*************************************************************************
	> File Name: lianxi.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月26日 星期四 09时20分04秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
int main() {
    char sum[1005];
    int64_t ans = 0, p = 1, zero = 0;
    for (int i = 1; i <= 1000; i++)
        scanf("%c", &sum[i]);
    for (int i = 1; sum[i]; i++) {
        if (sum[i]  - '0') p *= (sum[i] - '0');
        else zero += 1;
        if (i > 13){
            if (sum[i - 13] -'0')
            zero -= 1;
            else
            p /= (sum[i - 13] - '0');
        }
    }
    if (zero == 0 && ans < p && (ans = p));

    printf("%" PRId64 "\n", ans);
    return 0;
}

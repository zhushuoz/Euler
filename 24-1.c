/*************************************************************************
	> File Name: test_2.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年08月06日 星期一 14时34分26秒
 *******************************************************************/

#include <stdio.h>

int main () {
    int n, k;
    while(scanf("%d %d", &n, &k)!=EOF){
        int dnum[10] = {0};// dnum[i]为记录数字是否出现过
        int num[100] = {0};// 计算阶乘
        num[0] = 1;
        for (int i = 1; i < n; i++){
            num[ i ] = num[ i - 1 ] * i;
        }
        k -= 1;
        for (int i = n - 1; i >= 0; i--) {
            int m = k / num[i] + 1; //m为需要寻找到第几个未被使用的数字
            int a = -1; 
            while(m){
                a++;
                if (dnum[a]) continue;
                m--;

            }
            dnum[a] = 1;
            k %= num[i];
            printf("%d ", a);

        }
    }




    return 0;
}

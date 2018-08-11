/*************************************************************************
	> File Name: 26.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月31日 星期二 10时02分23秒
 ************************************************************************/
//求最长循环节
#include <stdio.h>
#define MAX_N 1000
#include <string.h>
int dnum[MAX_N] = {0};//记录余数出现的位置 每种余数只能出现一次 出现第二次时则成立循环节

int get_length (int d) {
    int y = 1, n = 1; //y是余数 n是位置
    memset(dnum, 0, sizeof(dnum));
    while (y != 0 && dnum[y] == 0) {
        dnum[y] = n;
        y = y * 10 % d;
        n += 1;
    }
    return y ? n - dnum[y] : 0;
}



int main() {
    int max_length = 0, ans = 0;
    for (int i = 2; i < MAX_N; i++){
        int temp_length = get_length(i);
        if (temp_length > max_length) {
            max_length = temp_length;
            ans = i;

        }

    }
    printf("%d\n", ans);



    return 0;
}

/*************************************************************************
	> File Name: 34.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月22日 星期日 11时47分30秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 50000
//上限为 2540160 

int is_factorials (int x, int *a) {

    int temp = 0, sum = x;

    while (sum){
        temp += a[sum % 10];
        sum /= 10;
    }
    return temp == x;

}


int main() {
    int a[10] = {1};
    int ans = 0;
    for (int i = 1; i < 10 && (a[i] = a[i- 1] * i); i++);
    

    for (int i = 10; i <= MAX_N; i++){
        if (!is_factorials(i, a)) continue;
        ans += i;
    }
    printf("%d\n", ans);

    return 0;
}

/*************************************************************************
	> File Name: test.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月27日 星期五 00时21分35秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>


#define MAX_N 10000 
int canAdd[MAX_N] = {0};//判断某个数字是否出现过


int pandigital (int x, int *gital){
    while (x){
        if (x % 10 == 0 || gital[x % 10]) return 0;
        gital[x % 10] = 1;
        x /= 10;
    }
    

    return 1;
}
//判断是否为全数字
int is_pandigital (int a, int b){
    int gital[10] = {0};
    if (!pandigital(a, gital)) return 0;
    if (!pandigital(b, gital)) return 0;
    if (!pandigital(a * b, gital)) return 0;
    return 1;
}


int digs (int a, int b){
    int sum = 0;
    sum += (int)floor(log10(a)) + 1;
    sum += (int)floor(log10(b)) + 1;
    sum += (int)floor(log10(a * b)) + 1;
    return sum;
}
//求整数i，j的位数
int main() {
    int ans = 0;
    for (int i = 100; i < 5000; i++){
        for (int j = 2; j < 99; j++){
            int d = digs(i, j);
            if (d < 9) continue;
            else if (d > 9) break;
            if(is_pandigital(i, j)){

                ans += i * j * (1 - canAdd[i * j]);
    
                canAdd[i * j] = 1;
            }
        }
    }
    printf("%d\n", ans);





    return 0;
}




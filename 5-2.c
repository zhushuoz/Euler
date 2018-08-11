/*************************************************************************
	> File Name: 5-2.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月22日 星期日 16时07分28秒
 ************************************************************************/

#include <stdio.h>
int gcd(int x, int y){
   // if(!y) return x;
   // return gcd(y, x % y);
    return (y ? gcd(y, x % y) : x);
}


int main() {
    int ans = 1;
    for (int i = 1; i <= 20; i++){
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
    printf("%d\n", ans);


    return 0;
}

/*************************************************************************
	> File Name: 17.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月26日 星期四 15时43分25秒
 ************************************************************************/

#include <stdio.h>
int main() {
    int ans, hundred = 7, l_and = 3;
    int units_digits = 36, b = 70;//分别表示 1-9，10-19的和

    int ten_digits = 46; // 表示20,30,40-90的和

    ans = units_digits + b; //表示1-19的和
    
    ans += ten_digits * 10 + units_digits * 8; //20-99  80个数字  


    ans += units_digits * 100 + ans * 9 + hundred  * 900 + l_and * 891; //100-999  900个数字 
    
    ans += 11;  //1000


    printf("%d\n", ans);
    return 0;
}

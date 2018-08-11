/*************************************************************************
	> File Name: 5.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月21日 星期六 21时17分22秒
 ************************************************************************/

#include <stdio.h>
int main(){
    int prime[20] = {0};
    for (int i = 0; i < 20; i++){
        for (int j = 0; j * j <= i || ((prime[i] = 1) & 0); j++)
            if (i % j == 0) break;
    }
    for (int i = 0; i <= 20; i++ )
    printf("%d ",prime[i]);

}

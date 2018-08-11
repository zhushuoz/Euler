/*************************************************************************
	> File Name: lianxi.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月26日 星期四 11时25分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
//大数相加


int main() {
    int num[55] = {1,0};//倒叙存放结果的数组  倒叙的原因是为了进位方便

    char temp[55];
    for (int i = 0; i < 100; i++) {
        scanf("%s", temp);
        int len = strlen(temp);
        if (len > num[0] && (num[0] = len));//将新的字符串与结果字符串长度进行比较  num[0]存放的是结果字符串的长度
        for (int j = 0; j < len ; j++){
            num[len - j] += (temp[j] - '0');
        }//将新的字符串倒叙相加

        for (int l = 1; l <= num[0]; l++) {
            if (num[l] < 10) continue;
            num[l + 1] += num[l] / 10;
            num[l] %= 10;
            num[0] += (l == num[0]);//若最高位有进位 长度加一
        }
    }
    for (int i = num[0]; i > num[0] - 10; i--){
        printf("%d", num[i]);
    }

    return 0;
}

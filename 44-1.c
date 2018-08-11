/*************************************************************************
	> File Name: euler44.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年08月01日 星期三 17时22分58秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
long long temp = 0;
long long  num (long long  x){
    if((3 * x -1) * x/2 > temp)
    return (3 * x - 1) * x / 2;
}

//二分查找x是否是五边形数
int is_p (int x){
    int  head = 0, tail = x;
    while (head <= tail){
        int  mid = (head + tail) / 2;
        if (num(mid) == x) return mid;
        if (num(mid) > x)  tail = mid - 1;
        else head = mid + 1;
    }
    return 0;

}
int main() {
    int ans = INT32_MAX;
    for (int i = 2;i < 100000 ; i++){
        if (num(i) - num(i - 1) > ans)  break;//当num[i] - num[i - 1] > ans时不会有比ans更小的值 两个相邻五边形数的差只会越来越大
        for (int j = i - 1; j >= 1; j--){
            int n = num(i) - num(j);
            if (n > ans) break;
            if (!is_p(num(i) + num(j))) continue;
            if (!is_p(n)) continue;
            ans = n;
            printf("%d %d\n",i ,j);
        }
    }
    printf("%d\n",ans);

}

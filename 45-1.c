/*************************************************************************
	> File Name: 45.c
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年07月29日 星期日 18时15分25秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t Hexagonal(int64_t x) {

    return (2 * x - 1) * x;

}

int64_t Pentagonal(int64_t x) {

    return (3 * x - 1) * x / 2;

}

int64_t binary_search(int64_t (*num)(int64_t), int64_t n, int64_t x){ 
    int64_t head = 0, tail = n, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == x) return mid;
        if (x > num(mid)) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
//数组是物理结构的映射关系，函数是一种数学逻辑的映射关系 两者在二分查找的框架中没有差别


int main() {
    int64_t n = 144;
    while(n++) {
        //当一个数为六边形数时必为三角形数  我们只需判断这个数是否为五边形数即可
        if (binary_search(Pentagonal, 2 * n, Hexagonal(n)))  break;   
    }
    printf("%"PRId64"\n", Hexagonal(n));


    return 0;
}

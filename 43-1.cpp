/*************************************************************************
	> File Name: euler43.cpp
	> Author: zhushuo
	> Mail: 
	> Created Time: 2018年08月02日 星期四 10时40分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <inttypes.h>
using namespace std;
#define MAX_N 1000000000
int dnum[12] = {0, 2, 3, 5, 7, 11, 13, 17};
int64_t a[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int64_t ans = 0;


int64_t is_num(int64_t *a){
    int64_t ans = a[0];   
    for (int i = 1; i < 10; i++) {
        ans = ans * 10 + a[i];
        if (i > 7) continue;
        int n = a[i] * 100 + a[i + 1] * 10 + a[i + 2];
        if (n % dnum[i]) return 0;

    }
    return ans;
}


int main() {
    while (next_permutation(a, a + 10)){

        ans += is_num(a); 
        
    }

    cout<< ans << endl;

    return 0;
}

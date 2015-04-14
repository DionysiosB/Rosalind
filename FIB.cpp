#include <cstdio>

int main(){

    long long x(1), y(1);

    int n, k; scanf("%d %d\n", &n, &k);

    for(int p = 3; p <= n; p++){
        long long temp = y;
        y += 3 * x;
        x = temp;
    }

    printf("%lld\n", y);

    return 0;
}

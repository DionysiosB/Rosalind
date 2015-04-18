#include <cstdio>

int main(){

    const long N = 1000000;

    int n, k; scanf("%d %d\n", &n, &k);
    long perm(1);
    for(int p = n - k  + 1; p <= n; p++){perm *= p; perm %= N;}
    printf("%ld\n", perm);

    return 0;
}

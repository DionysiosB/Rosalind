#include <cstdio>

int main(){

    const long MOD = 1000000;
    int n; scanf("%d\n", &n);

    long ans(1);
    for(int p = 0; p < n; p++){
        ans *= 2;
        ans %= MOD;
    }

    printf("%ld\n", ans);

    return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    int n, m; scanf("%d %d\n", &n, &m);

    std::vector<long long> f(n + 1, 0); f[0] = 1; f[1] = 1; f[2] = 1;
    for(int p = 3; p <= n; p++){
        f[p] = f[p - 1] + f[p - 2];
        if(p > m){f[p] -= f[p - m - 1];}
    }
    //for(int p = 0; p <= n; p++){std::cout << f[p] << std::endl;}
    
    printf("%lld\n", f.back());

    return 0;
}

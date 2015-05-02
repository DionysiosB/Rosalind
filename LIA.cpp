#include <cstdio>
#include <cmath>

double binomial(int n, int k){
    double output = 1.0;
    if(k == 0 || k == n){return output;}
    for(int p = 1; p <= k; p++){output *= 1.0 * (n + 1 - p) / p;}
    return output;
}

int main(){

    int k, N; scanf("%d %d\n", &k, &N);
    double t = 1 << k;

    double prob(0);
    for(int p = N; p <= t; p++){prob += binomial(t, p) * pow(0.25, p) * pow(0.75, t - p);}
    printf("%.5lf\n", prob);

    return 0;
}

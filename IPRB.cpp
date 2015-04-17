#include <cstdio>

int main(){

    double k, m, n; scanf("%lf %lf %lf\n", &k, &m, &n);
    double output = (0.5 * k * (k - 1) + k * m + k * n + 0.375 * m * (m - 1) + 0.5 * m * n) / (0.5 * (k + m + n) * (k + m + n - 1));
    printf("%.5lf\n", output);

    return 0;
}

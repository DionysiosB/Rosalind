#include <cstdio>

int main(){

    double a1, a2, a3, a4, a5, a6; scanf("%lf %lf %lf %lf %lf %lf\n", &a1, &a2, &a3, &a4, &a5, &a6);
    double result = 2 * (a1 + a2 + a3 + 0.75 * a4 + 0.5 * a5);
    printf("%.5lf\n", result);

    return 0;
}

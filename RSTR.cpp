#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

int main(){

    long n; double gc; scanf("%ld %lf\n", &n, &gc);
    std::string dna; getline(std::cin, dna);

    long double prob = 1;
    for(int p = 0; p < dna.size(); p++){
        if(dna[p] == 'A' || dna[p] == 'T'){prob *= (1 - gc) / 2;}
        else{prob *= gc / 2;}
    }
    prob = 1 - prob;

    long double ans = 1.0;
    for(int p = 0; p < n; p++){ans *= prob;}
    ans = 1 - ans;
    printf("%.9Lf\n", ans);



    return 0;
}

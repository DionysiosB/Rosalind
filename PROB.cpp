#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>


int main(){

    const int N = 16;   //The length of the probability vector;
    
    std::string dna; getline(std::cin, dna);
    long n = dna.size();

    std::vector<double> array(N);
    for(int p = 0; p < N; p++){double temp; std::cin >> temp; array[p] = temp;}

    long gc(0);
    for(int p = 0; p < dna.size(); p++){if(dna[p] == 'G' || dna[p] == 'C'){++gc;}}

    for(int p = 0; p < N; p++){
        double ans = gc * log10(0.5 * array[p]) + (n - gc) * log10(0.5 * (1 - array[p]));
        printf("%.5lf ", ans);
    }
    puts("");

}

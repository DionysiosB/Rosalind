#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    long n; scanf("%ld\n", &n);
    std::string dna; getline(std::cin, dna);
    
    double temp;
    std::vector<double> A, B;
    while(std::cin >> temp){A.push_back(temp);}

    for(int p = 0; p < A.size(); p++){
        double gc = A[p];

        long double prob(1);
        for(int q = 0; q < dna.size(); q++){
            if(dna[q] == 'G' || dna[q] == 'C'){prob *= gc / 2;}
            else{prob *= (1 - gc) / 2;}
        }

        B.push_back((n - dna.size() + 1) * prob);
    }


    for(int p = 0; p < A.size(); p++){printf("%.5lf ", B[p]);}


    return 0;
}

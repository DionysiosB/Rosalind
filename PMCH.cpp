#include <iostream>

int main(){

    std::string name, rna;
    getline(std::cin, name);
    getline(std::cin, rna);

    long double a(0), g(0);

    for(int p = 0; p < rna.size(); p++){
        if(rna[p] == 'A'){++a;}
        if(rna[p] == 'G'){++g;}
    }

    std::cout << a << "\t" << g << std::endl;

    long double ans(1);
    for(int p = 1; p <= a; p++){ans *= p;}
    for(int p = 1; p <= g; p++){ans *= p;}

    std::cout << std::fixed;
    std::cout << ans << std::endl;

    return 0;
}

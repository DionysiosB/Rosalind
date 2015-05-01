#include <iostream>

int main(){

    std::string name; getline(std::cin, name);
    std::string rna; getline(std::cin, rna);


    int a(0), u(0), c(0), g(0);
    for(int p = 0; p < rna.size(); p++){
        if(rna[p] == 'A'){++a;}
        else if(rna[p] == 'U'){++u;}
        else if(rna[p] == 'C'){++c;}
        else if(rna[p] == 'G'){++g;}
    }

    int max1 = (a > u) ? a : u;
    int diff1 = (a > u) ? (a - u) : (u - a);
    int max2 = (c > g) ? c : g;
    int diff2 = (c > g) ? (c - g) : (c - g);

    std::cout << a << "\t" << u << "\t" << c << "\t" << g << std::endl;
    std::cout << "==============\n\n\n" << std::endl;
    std::cout << max1 << "\t" << max2 << "\t" << diff1 << "\t" << diff2 << std::endl;

    long long ans;
    for(int p = diff1 + 1; p <= max1; p++){ans *= p;}
    for(int p = diff2 + 1; p <= max2; p++){ans *= p;}


    return 0;
}

#include <iostream>

int main(){

    std::string dna; getline(std::cin, dna);
    long n = dna.size();
    std::string comp(n, 'a');
    for(int p = 0; p < n; p++){
        if(dna[p] == 'A'){comp[n - 1 - p] = 'T';}
        if(dna[p] == 'T'){comp[n - 1 - p] = 'A';}
        if(dna[p] == 'C'){comp[n - 1 - p] = 'G';}
        if(dna[p] == 'G'){comp[n - 1 - p] = 'C';}
    }

    std::cout << comp << std::endl;

    return 0;
}

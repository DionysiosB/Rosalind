#include <iostream>

int main(){

    std::string dna; getline(std::cin, dna);
    std::string rna(dna);
    for(int p = 0; p < rna.size(); p++){
        if(rna[p] == 'T'){rna[p] = 'U';}
    }

    std::cout << rna << std::endl;

    return 0;
}

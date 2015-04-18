#include <cstdio>
#include <iostream>
#include <map>

int main(){

    const long N = 1000000;

    std::map<char, int> codons;
    codons.insert(std::pair<char, int>('F', 2));
    codons.insert(std::pair<char, int>('L', 6));
    codons.insert(std::pair<char, int>('I', 3));
    codons.insert(std::pair<char, int>('M', 1));
    codons.insert(std::pair<char, int>('V', 4));
    codons.insert(std::pair<char, int>('S', 6));
    codons.insert(std::pair<char, int>('P', 4));
    codons.insert(std::pair<char, int>('T', 4));
    codons.insert(std::pair<char, int>('A', 4));
    codons.insert(std::pair<char, int>('H', 2));
    codons.insert(std::pair<char, int>('Q', 2));
    codons.insert(std::pair<char, int>('N', 2));
    codons.insert(std::pair<char, int>('K', 2));
    codons.insert(std::pair<char, int>('D', 2));
    codons.insert(std::pair<char, int>('E', 2));
    codons.insert(std::pair<char, int>('C', 2));
    codons.insert(std::pair<char, int>('Y', 2));
    codons.insert(std::pair<char, int>('W', 1));
    codons.insert(std::pair<char, int>('R', 6));
    codons.insert(std::pair<char, int>('G', 4));
    codons.insert(std::pair<char, int>('$', 3));   //Stop Codon;


    std::string protein; getline(std::cin, protein);
    long comb(1);
    for(int p = 0; p < protein.size(); p++){
        comb *= codons[protein[p]];
        comb %= N;
    }

    comb *= codons['$']; comb %= N;
    std::cout << comb << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <map>

int main(){

    std::map<std::string, std::string> codonTable;
    codonTable.insert(std::pair<std::string, std::string>("UUU", "F"));
    codonTable.insert(std::pair<std::string, std::string>("UUC", "F"));
    codonTable.insert(std::pair<std::string, std::string>("UUA", "L"));
    codonTable.insert(std::pair<std::string, std::string>("UUG", "L"));
    codonTable.insert(std::pair<std::string, std::string>("UCU", "S"));
    codonTable.insert(std::pair<std::string, std::string>("UCC", "S"));
    codonTable.insert(std::pair<std::string, std::string>("UCA", "S"));
    codonTable.insert(std::pair<std::string, std::string>("UCG", "S"));
    codonTable.insert(std::pair<std::string, std::string>("UAU", "Y"));
    codonTable.insert(std::pair<std::string, std::string>("UAC", "Y"));
    codonTable.insert(std::pair<std::string, std::string>("UAA", ""));
    codonTable.insert(std::pair<std::string, std::string>("UAG", ""));
    codonTable.insert(std::pair<std::string, std::string>("UGA", ""));
    codonTable.insert(std::pair<std::string, std::string>("UGU", "C"));
    codonTable.insert(std::pair<std::string, std::string>("UGC", "C"));
    codonTable.insert(std::pair<std::string, std::string>("UGG", "W"));
    codonTable.insert(std::pair<std::string, std::string>("CUU", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CUC", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CUA", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CUG", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CCU", "P"));
    codonTable.insert(std::pair<std::string, std::string>("CCC", "P"));
    codonTable.insert(std::pair<std::string, std::string>("CCA", "P"));
    codonTable.insert(std::pair<std::string, std::string>("CCG", "P"));
    codonTable.insert(std::pair<std::string, std::string>("CAU", "H"));
    codonTable.insert(std::pair<std::string, std::string>("CAC", "H"));
    codonTable.insert(std::pair<std::string, std::string>("CAA", "Q"));
    codonTable.insert(std::pair<std::string, std::string>("CAG", "Q"));
    codonTable.insert(std::pair<std::string, std::string>("CGU", "R"));
    codonTable.insert(std::pair<std::string, std::string>("CGC", "R"));
    codonTable.insert(std::pair<std::string, std::string>("CGA", "R"));
    codonTable.insert(std::pair<std::string, std::string>("CGG", "R"));
    codonTable.insert(std::pair<std::string, std::string>("AUU", "I"));
    codonTable.insert(std::pair<std::string, std::string>("AUC", "I"));
    codonTable.insert(std::pair<std::string, std::string>("AUA", "I"));
    codonTable.insert(std::pair<std::string, std::string>("AUG", "M"));
    codonTable.insert(std::pair<std::string, std::string>("ACU", "T"));
    codonTable.insert(std::pair<std::string, std::string>("ACC", "T"));
    codonTable.insert(std::pair<std::string, std::string>("ACA", "T"));
    codonTable.insert(std::pair<std::string, std::string>("ACG", "T"));
    codonTable.insert(std::pair<std::string, std::string>("AAU", "N"));
    codonTable.insert(std::pair<std::string, std::string>("AAC", "N"));
    codonTable.insert(std::pair<std::string, std::string>("AAA", "K"));
    codonTable.insert(std::pair<std::string, std::string>("AAG", "K"));
    codonTable.insert(std::pair<std::string, std::string>("AGU", "S"));
    codonTable.insert(std::pair<std::string, std::string>("AGC", "S"));
    codonTable.insert(std::pair<std::string, std::string>("AGA", "R"));
    codonTable.insert(std::pair<std::string, std::string>("AGG", "R"));
    codonTable.insert(std::pair<std::string, std::string>("GUU", "V"));
    codonTable.insert(std::pair<std::string, std::string>("GUC", "V"));
    codonTable.insert(std::pair<std::string, std::string>("GUA", "V"));
    codonTable.insert(std::pair<std::string, std::string>("GUG", "V"));
    codonTable.insert(std::pair<std::string, std::string>("GCU", "A"));
    codonTable.insert(std::pair<std::string, std::string>("GCC", "A"));
    codonTable.insert(std::pair<std::string, std::string>("GCA", "A"));
    codonTable.insert(std::pair<std::string, std::string>("GCG", "A"));
    codonTable.insert(std::pair<std::string, std::string>("GAU", "D"));
    codonTable.insert(std::pair<std::string, std::string>("GAC", "D"));
    codonTable.insert(std::pair<std::string, std::string>("GAA", "E"));
    codonTable.insert(std::pair<std::string, std::string>("GAG", "E"));
    codonTable.insert(std::pair<std::string, std::string>("GGU", "G"));
    codonTable.insert(std::pair<std::string, std::string>("GGC", "G"));
    codonTable.insert(std::pair<std::string, std::string>("GGA", "G"));
    codonTable.insert(std::pair<std::string, std::string>("GGG", "G"));

    std::string rna; getline(std::cin, rna);
    for(int p = 0; p < rna.size() / 3; p++){
        std::string current = rna.substr(3 * p, 3);
        std::cout << codonTable[current];
    }

    puts("");
    return 0;
}

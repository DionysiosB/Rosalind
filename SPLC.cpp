#include <iostream>
#include <string>
#include <map>

std::string convertDNAtoProtein(std::string dna){

    std::map<std::string, std::string> codonTable;
    codonTable.insert(std::pair<std::string, std::string>("GCT", "A"));
    codonTable.insert(std::pair<std::string, std::string>("GCC", "A"));
    codonTable.insert(std::pair<std::string, std::string>("GCA", "A"));
    codonTable.insert(std::pair<std::string, std::string>("GCG", "A"));

    codonTable.insert(std::pair<std::string, std::string>("CGT", "R"));
    codonTable.insert(std::pair<std::string, std::string>("CGC", "R"));
    codonTable.insert(std::pair<std::string, std::string>("CGA", "R"));
    codonTable.insert(std::pair<std::string, std::string>("CGG", "R"));
    codonTable.insert(std::pair<std::string, std::string>("AGA", "R"));
    codonTable.insert(std::pair<std::string, std::string>("AGG", "R"));

    codonTable.insert(std::pair<std::string, std::string>("AAT", "N"));
    codonTable.insert(std::pair<std::string, std::string>("AAC", "N"));

    codonTable.insert(std::pair<std::string, std::string>("GAT", "D"));
    codonTable.insert(std::pair<std::string, std::string>("GAC", "D"));

    codonTable.insert(std::pair<std::string, std::string>("TGT", "C"));
    codonTable.insert(std::pair<std::string, std::string>("TGC", "C"));

    codonTable.insert(std::pair<std::string, std::string>("CAA", "Q"));
    codonTable.insert(std::pair<std::string, std::string>("CAG", "Q"));

    codonTable.insert(std::pair<std::string, std::string>("GAA", "E"));
    codonTable.insert(std::pair<std::string, std::string>("GAG", "E"));

    codonTable.insert(std::pair<std::string, std::string>("GGT", "G"));
    codonTable.insert(std::pair<std::string, std::string>("GGC", "G"));
    codonTable.insert(std::pair<std::string, std::string>("GGA", "G"));
    codonTable.insert(std::pair<std::string, std::string>("GGG", "G"));

    codonTable.insert(std::pair<std::string, std::string>("CAT", "H"));
    codonTable.insert(std::pair<std::string, std::string>("CAC", "H"));

    codonTable.insert(std::pair<std::string, std::string>("ATT", "I"));
    codonTable.insert(std::pair<std::string, std::string>("ATC", "I"));
    codonTable.insert(std::pair<std::string, std::string>("ATA", "I"));

    codonTable.insert(std::pair<std::string, std::string>("ATG", "M"));

    codonTable.insert(std::pair<std::string, std::string>("TTA", "L"));
    codonTable.insert(std::pair<std::string, std::string>("TTG", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CTT", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CTC", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CTA", "L"));
    codonTable.insert(std::pair<std::string, std::string>("CTG", "L"));

    codonTable.insert(std::pair<std::string, std::string>("AAA", "K"));
    codonTable.insert(std::pair<std::string, std::string>("AAG", "K"));

    codonTable.insert(std::pair<std::string, std::string>("TTT", "F"));
    codonTable.insert(std::pair<std::string, std::string>("TTC", "F"));

    codonTable.insert(std::pair<std::string, std::string>("CCT", "P"));
    codonTable.insert(std::pair<std::string, std::string>("CCC", "P"));
    codonTable.insert(std::pair<std::string, std::string>("CCA", "P"));
    codonTable.insert(std::pair<std::string, std::string>("CCG", "P"));

    codonTable.insert(std::pair<std::string, std::string>("TCT", "S"));
    codonTable.insert(std::pair<std::string, std::string>("TCC", "S"));
    codonTable.insert(std::pair<std::string, std::string>("TCA", "S"));
    codonTable.insert(std::pair<std::string, std::string>("TCG", "S"));
    codonTable.insert(std::pair<std::string, std::string>("AGT", "S"));
    codonTable.insert(std::pair<std::string, std::string>("AGC", "S"));

    codonTable.insert(std::pair<std::string, std::string>("ACT", "T"));
    codonTable.insert(std::pair<std::string, std::string>("ACC", "T"));
    codonTable.insert(std::pair<std::string, std::string>("ACA", "T"));
    codonTable.insert(std::pair<std::string, std::string>("ACG", "T"));

    codonTable.insert(std::pair<std::string, std::string>("TGG", "W"));

    codonTable.insert(std::pair<std::string, std::string>("TAT", "Y"));
    codonTable.insert(std::pair<std::string, std::string>("TAC", "Y"));

    codonTable.insert(std::pair<std::string, std::string>("GTT", "V"));
    codonTable.insert(std::pair<std::string, std::string>("GTC", "V"));
    codonTable.insert(std::pair<std::string, std::string>("GTA", "V"));
    codonTable.insert(std::pair<std::string, std::string>("GTG", "V"));

    codonTable.insert(std::pair<std::string, std::string>("TAA", ""));
    codonTable.insert(std::pair<std::string, std::string>("TAG", ""));
    codonTable.insert(std::pair<std::string, std::string>("TGA", ""));


    std::string output("");
    for(int p = 0; p < dna.size(); p += 3){
        std::string current = dna.substr(p, 3);
        output += codonTable[current];
    }

    return output;
}


int main(){

    std::string name; getline(std::cin, name);
    std::string dna; getline(std::cin, dna);
    while(getline(std::cin, name)){
        std::string exon; getline(std::cin, exon);
        std::size_t pos = dna.find(exon);
        if(pos != std::string::npos){dna.erase(pos, exon.size());}
    }

    std::string protein = convertDNAtoProtein(dna);
    std::cout << protein << std::endl;


    puts("");
    return 0;
}

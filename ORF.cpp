#include <iostream>
#include <map>
#include <set>

const int L = 3;   // Number of bases to form a protein;

std::string findCodon(std::string input){

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

    if(codonTable.find(input) == codonTable.end()){return "NONE";}
    return codonTable[input];
}

std::set<std::string> convertToProtein(std::string dna){

    std::set<std::string> output;
    std::string start = "ATG";
    int currentPos = -1;
    while(true){
        std::string currentProtein("");
        currentPos = dna.find(start, currentPos + 1);
        if(currentPos == std::string::npos){break;}

        bool final = 0;
        for(int p = currentPos; p < dna.size(); p += 3){
            std::string codon = dna.substr(p, L);
            std::string aminoacid = findCodon(codon);
            if(aminoacid.size() == 0){final = 1; break;}
            else{currentProtein += aminoacid;}
        }
        if(final){output.insert(currentProtein);}
    }

    return output;
}

std::string reverseComplement(std::string dna){

    std::string output(dna);
    int n = dna.size();
    for(int p = 0; p < n; p++){
        if(dna[p] == 'A'){output[n - 1 - p] = 'T';}
        else if(dna[p] == 'T'){output[n - 1 - p] = 'A';}
        else if(dna[p] == 'C'){output[n - 1 - p] = 'G';}
        else if(dna[p] == 'G'){output[n - 1 - p] = 'C';}
    }

    return output;
}


int main(){

    std::string name; getline(std::cin, name);
    std::string dna; getline(std::cin, dna);
    std::set<std::string> proteinsA = convertToProtein(dna);
    std::set<std::string> proteinsB = convertToProtein(reverseComplement(dna));
    std::set<std::string> output;
    for(std::set<std::string>::iterator setIter = proteinsA.begin(); setIter != proteinsA.end(); setIter++){output.insert(*setIter);}
    for(std::set<std::string>::iterator setIter = proteinsB.begin(); setIter != proteinsB.end(); setIter++){output.insert(*setIter);}
    for(std::set<std::string>::iterator setIter = output.begin(); setIter != output.end(); setIter++){std::cout << (*setIter) << std::endl;}


    return 0;
}

#include <iostream>
#include <vector>
#include <map>


int main(){

    std::string name, dna, consensus;
    getline(std::cin, name);
    getline(std::cin, dna);
    consensus = dna;

    std::map<char, long> emptyMap;
    emptyMap.insert(std::pair<char, long>('A', 0));
    emptyMap.insert(std::pair<char, long>('T', 0));
    emptyMap.insert(std::pair<char, long>('C', 0));
    emptyMap.insert(std::pair<char, long>('G', 0));

    std::vector<std::map<char, long> > count(dna.size(), emptyMap);
    for(int p = 0; p < dna.size(); p++){++count[p][dna[p]];}

    while(getline(std::cin, name)){
        getline(std::cin, dna);
        for(int p = 0; p < dna.size(); p++){++count[p][dna[p]];}
    }

    for(int p = 0; p < count.size(); p++){
        if(count[p]['A'] >= count[p]['T'] && count[p]['A'] >= count[p]['C'] && count[p]['A'] >= count[p]['G']){consensus[p] = 'A';}
        else if(count[p]['T'] >= count[p]['A'] && count[p]['T'] >= count[p]['C'] && count[p]['T'] >= count[p]['G']){consensus[p] = 'T';}
        else if(count[p]['C'] >= count[p]['A'] && count[p]['C'] >= count[p]['T'] && count[p]['C'] >= count[p]['G']){consensus[p] = 'C';}
        else if(count[p]['G'] >= count[p]['A'] && count[p]['G'] >= count[p]['T'] && count[p]['G'] >= count[p]['C']){consensus[p] = 'G';}
    }

    std::cout << consensus << std::endl;
    std::string nucl = "ACGT";
    for(int p = 0; p < nucl.size(); p++){
        std::cout << nucl[p] << ": ";
        for(int q = 0; q < count.size(); q++){std::cout << count[q][nucl[p]] << " ";}
        puts("");
    }

    return 0;
}

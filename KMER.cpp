#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> generateKMers(std::string input, int length){

    std::vector<std::string> current; current.push_back("");

    for(int p = 1; p <= length; p++){
        std::vector<std::string> previous = current;
        current.clear();
        for(int k = 0; k < previous.size(); k++){
            for(int m = 0; m < input.size(); m++){
                current.push_back(previous[k] + input[m]);
            }
        }
    }

    return current;
}


long countOccurences(std::string what, std::string where){

    long count(0);
    long pos = -1;
    while(true){
        pos = where.find(what, pos + 1);
        if(pos == std::string::npos){break;}
        ++count;
    }
    return count;
}


int main(){

    const int K = 4;
    const std::string B = "ACGT";
    std::vector<std::string> kmers = generateKMers(B, K);

    std::string name; getline(std::cin, name);
    std::string inputDna; getline(std::cin, inputDna);

    std::vector<long> countVec(kmers.size(), 0);
    for(int p = 0; p < countVec.size(); p++){countVec[p] = countOccurences(kmers[p], inputDna);}
    for(int p = 0; p < countVec.size(); p++){std::cout << countVec[p] << " ";}

    return 0;
}

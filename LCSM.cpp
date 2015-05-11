#include <iostream>
#include <vector>

int main(){

    std::vector<std::string> strands;

    std::string name, smallest;
    int minSize(10000);
    while(std::cin >> name){
        std::string dna; std::cin >> dna; strands.push_back(dna);
        if(dna.size() < minSize){smallest = dna; minSize = dna.size();}
    }

    std::string output("");
    for(int len = minSize; len > 0; len--){
        for(int start = 0; start + len < minSize; start++){
            std::string cand = smallest.substr(start, len);

            bool found = 1;
            for(int p = 0; p < strands.size(); p++){if(strands[p].find(cand) == std::string::npos){found = 0; break;}}
            if(found){output = cand; break;}
        }

        if(output.size() > 0){break;}
    }

    std::cout << output << std::endl;

    return 0;
}

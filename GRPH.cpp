#include <iostream>
#include <vector>


int main(){

    const int N = 3;
    std::string name;
    std::vector<std::pair<std::string, std::string> > seq;

    while(getline(std::cin, name)){
        std::string dna; getline(std::cin, dna);
        seq.push_back(std::pair<std::string, std::string>(name.substr(1), dna));
    }

    for(int p = 0; p < seq.size(); p++){
        std::string prefix = seq[p].second.substr(0,N);
        for(int q = 0; q < seq.size(); q++){
            if(p == q){continue;}
            std::string test = seq[q].second;
            std::string suffix = test.substr(test.size() - N,N);
            if(prefix == suffix){std::cout << seq[q].first << " " << seq[p].first << std::endl;}
        }
    }

    return 0;
}

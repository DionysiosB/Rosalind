#include <iostream>
#include <vector>

int main(){

    //std::string name; getline(std::cin, name);  //Delete the name first and remove newlines;
    std::string dna; getline(std::cin, dna);
    long n = dna.size();
    std::vector<long> score(n, 0);

    for(long len = 1; len < n; len++){
        std::string prefix = dna.substr(0, len);
        long currentPos(0);
        while(true){
            currentPos = dna.find(prefix, currentPos + 1);
            if(currentPos != std::string::npos){score[currentPos + len - 1] = len;}
            else{break;}
        }
    }

    for(int p = 0; p < n; p++){std::cout << score[p] << " ";}
    std::cout << std::endl;

    return 0;
}

#include <iostream>

char complement(char input){
    if(input == 'A'){return 'T';}
    if(input == 'T'){return 'A';}
    if(input == 'C'){return 'G';}
    if(input == 'G'){return 'C';}
    return '0';
}

bool isReversePalindrome(std::string input){

    if(input.size() % 2 == 1){return false;}
    size_t n = input.size();
    for(size_t p = 0; p < n; p++){
        if(input[p] != complement(input[n - 1 - p])){return false;}
    }
    
    return true;
}

int main(){

    std::string name; getline(std::cin, name);
    std::string dna; getline(std::cin, dna);

    for(int p = 0; p < dna.size(); p++){
        for(int q = 4; q <= 12; q += 2){
            if(p + q > dna.size()){continue;}
            std::string test = dna.substr(p, q);
            if(isReversePalindrome(test)){std::cout << (p + 1) << " " << q << std::endl;}
        }
    }


    return 0;
}

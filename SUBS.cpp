#include <iostream>
#include <string>

int main(){

    std::string source; getline(std::cin, source);
    std::string target; getline(std::cin, target);

    long pos(0);
    while(pos != std::string::npos){
        pos = source.find(target, 1 + pos);
        if(pos != std::string::npos){std::cout << (1 + pos) << " ";}
        else{break;}
    }

    std::cout << std::endl;

    return 0;
}

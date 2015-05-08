#include <iostream>

int main(){

    double p;
    while(std::cin >> p){std::cout << (2 * p * (1 - p)) << " ";}
    std::cout << std::endl;

    return 0;
}

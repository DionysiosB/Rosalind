#include <iostream>
#include <cmath>

int main(){

    double p;
    while(std::cin >> p){std::cout << (2 * sqrt(p) - p) << " ";}
    std::cout << std::endl;

    return 0;
}

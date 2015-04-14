#include <iostream>

int main(){

    std::string a, b; 
    getline(std::cin, a); 
    getline(std::cin, b);

    long dist(0);
    for(int p = 0; p < a.size() && p < b.size(); p++){
        if(a[p] != b[p]){++dist;}
    }

    std::cout << dist << std::endl;

    return 0;
}

#include <cstdio>
#include <iostream>

int main(){

    int n; scanf("%d\n", &n);
    std::string dummy; 
    int edges(n - 1);
    while(getline(std::cin, dummy)){--edges;}
    std::cout << edges << std::endl;

    return 0;
}

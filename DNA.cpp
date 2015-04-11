#include <iostream>

int main(){

    std::string input; getline(std::cin, input);
    long a(0), c(0), g(0), t(0);
    for(int p = 0; p < input.size(); p++){
        if(input[p] == 'A'){++a;}
        if(input[p] == 'C'){++c;}
        if(input[p] == 'G'){++g;}
        if(input[p] == 'T'){++t;}
    }

    std::cout << a << " " << c << " " << g << " " << t << std::endl;

    return 0;
}

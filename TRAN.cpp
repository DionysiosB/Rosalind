#include <iostream>

int main(){

    std::string name; getline(std::cin, name);
    std::string first; getline(std::cin, first);
    getline(std::cin, name);
    std::string second; getline(std::cin, second);

    double transitions(0), transversions(0);
    for(int p = 0; p < first.size() && p < second.size(); p++){
        if(first[p] == second[p]){continue;}

        if((first[p] == 'A' && second[p] == 'G') ||
           (first[p] == 'G' && second[p] == 'A') ||
           (first[p] == 'C' && second[p] == 'T') ||
           (first[p] == 'T' && second[p] == 'C')){++transitions;}
        else{++transversions;}
    }

    printf("%.7lf\n", transitions / transversions);

    return 0;
}

#include <cstdio>
#include <iostream>

double getGCcontent(std::string strand){

    if(strand.size() <= 0){return 0;}
    long GCcount(0);
    for(int p = 0; p < strand.size(); p++){if(strand[p] == 'G' || strand[p] == 'C'){++GCcount;}}
    return 1.0 * GCcount / strand.size();
}



int main(){

    std::string name, dna, bestStrand;
    double maxContent(0);
    while(getline(std::cin, name)){
        getline(std::cin, dna);
        double content = getGCcontent(dna);
        if(content > maxContent){maxContent = content; bestStrand = name.substr(1);}
    }

    std::cout << bestStrand << std::endl;
    printf("%.5lf\n", (100 * maxContent));

    return 0;
}

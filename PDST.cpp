#include <iostream>
#include <vector>

double distance(std::string strA, std::string strB){

    double diff(0);
    double n = strA.size();
    for(int p = 0; p < strA.size() && p < strB.size(); p++){
        if(strA[p] != strB[p]){++diff;}
    }

    return diff / n;
}


int main(){

    std::string name;
    std::vector<std::string> array;
    while(getline(std::cin, name)){
        std::string dna;
        getline(std::cin, dna);
        array.push_back(dna);
    }

    int n = array.size();
    for(int p = 0; p < n; p++){
        for(int q = 0; q < n; q++){
            printf("%.5lf ", distance(array[p], array[q]));
        }
        puts("");
    }
    
    return 0;
}

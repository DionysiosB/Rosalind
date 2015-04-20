#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int main(){

    std::vector<char> alphabet;
    while(true){
        char temp; scanf("%c", &temp);
        if(temp == ' '){continue;}
        else if(temp == '\n'){break;}
        else{alphabet.push_back(temp);}
    }

    int n; scanf("%d", &n);

    std::vector<std::string> current; current.push_back("");
    std::vector<std::string> previous;

    for(int p = 0; p < n; p++){
        previous = current;
        current.clear();
        for(int m = 0; m < alphabet.size(); m++){
            for(int k = 0; k < previous.size(); k++){
                current.push_back(alphabet[m] + previous[k]);
            }
        }
    }

    for(int p = 0; p < current.size(); p++){std::cout << current[p] << std::endl;}

    return 0;
}

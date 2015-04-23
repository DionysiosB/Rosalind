#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::string stringConvert(std::string input, std::map<char, char> dict){
    std::string output(input);
    for(int p = 0; p < input.size(); p++){output[p] = dict[input[p]];}
    return output;
}

int main(){

    std::vector<char> alphabet, alt;
    std::map<char, char> symbolMap;
    int counter(0);
    while(true){
        char temp; scanf("%c", &temp);
        if(temp == ' '){continue;}
        else if(temp == '\n'){break;}
        else{
            alphabet.push_back(temp);
            alt.push_back('a' + counter);
            symbolMap.insert(std::pair<char, char>('a' + counter, temp));
            ++counter;

        }
    }

    int n; scanf("%d", &n);

    std::vector<std::string> current; current.push_back("");
    std::vector<std::string> previous, cumVec;

    for(int p = 0; p < n; p++){
        previous = current;
        current.clear();
        for(int m = 0; m < alt.size(); m++){
            for(int k = 0; k < previous.size(); k++){
                current.push_back(alt[m] + previous[k]);
            }
        }

        cumVec.insert(cumVec.end(), current.begin(), current.end());
    }

    sort(cumVec.begin(), cumVec.end());
    for(int p = 0; p < cumVec.size(); p++){std::cout << stringConvert(cumVec[p], symbolMap) << std::endl;}

    return 0;
}

#include <iostream>
#include <map>

std::map<std::string, long> matchMap;

long long perfectMatch(std::string s){

    const long MOD = 1000000;
    const int n = s.size();
    if(n == 0){return 1;}
    if(n % 2 > 0){return 0;}

    int a(0), u(0), g(0), c(0);
    for(int p = 0; p < s.size(); p++){
        if(s[p] == 'A'){++a;}
        else if(s[p] == 'U'){++u;}
        else if(s[p] == 'C'){++c;}
        else if(s[p] == 'G'){++g;}
    }

    if((a != u) || (c != g)){return 0;}
    if(s.size() == 2){return 1;}

    char nuc = s[0];
    char com; 
    if(nuc == 'A'){com = 'U';}
    else if(nuc == 'U'){com = 'A';}
    else if(nuc == 'C'){com = 'G';}
    else if(nuc == 'G'){com = 'C';}

    long long output(0);
    for(int p = 1; p < n; p++){
        if(s[p] != com){continue;}
        int lengthLeft = p - 1; int lengthRight = n - p - 1;
        std::string stringLeft = s.substr(1, lengthLeft); std::string stringRight = s.substr(p + 1, lengthRight);
        long leftMatch;
        if(matchMap.find(stringLeft) != matchMap.end()){leftMatch = matchMap[stringLeft];}
        else{leftMatch = perfectMatch(stringLeft); matchMap.insert(std::pair<std::string, long>(stringLeft, leftMatch));}

        long rightMatch(1); 
        if(p < n - 1){
            if(matchMap.find(stringRight) != matchMap.end()){rightMatch = matchMap[stringRight];}
            else{rightMatch = perfectMatch(stringRight); matchMap.insert(std::pair<std::string, long>(stringRight, rightMatch));}
        }

        output += leftMatch * rightMatch; 
        output %= MOD;
    }

    if(matchMap.find(s) == matchMap.end()){matchMap.insert(std::pair<std::string, long>(s, output));}
    return output;

}

int main(){

    std::string name; getline(std::cin, name);
    std::string rna; getline(std::cin, rna);

    long long ans = perfectMatch(rna);
    std::cout << ans << std::endl;
    return 0;
}

#include <iostream>

int main(){

    //Remove the names
    std::string s; getline(std::cin, s);
    std::string t; getline(std::cin, t);

    int pos = 0;
    for(int p = 0; p < t.size(); p++){
        char c = t[p];
        pos = s.find(c, pos);
        if(pos == std::string::npos){puts("Something is REALLY wrong");}
        printf("%d ", pos + 1);
        pos++;
    }
    puts("");



    return 0;
}

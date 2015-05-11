#include <iostream>
#include <vector>
#include <string>

int main(){

    std::string name; getline(std::cin, name);
    std::string a; getline(std::cin, a);
    std::string name; getline(std::cin, name);
    std::string b; getline(std::cin, b);
    int n = a.size(); int m = b.size();

    std::vector<std::vector<std::pair<long, std::string> > > array(n + 1, std::vector<std::pair<long, std::string> >(m + 1));

    for(int p = 0; p <= n; p++){array[p][0].first = 0; array[p][0].second = "";}
    for(int p = 0; p <= m; p++){array[0][p].first = 0; array[0][p].second = "";}

    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= m; col++){
            int candA = array[row - 1][col - 1].first + (a[row] == b[col]);
            int candB = array[row][col - 1].first;
            int candC = array[row - 1][col].first;
            int candLength = candA; 
            std::string candString = array[row - 1][col - 1].second; if(a[row] == b[col]){candString += a[row];}
            if(candLength < candB){candLength = candB; candString = array[row][col - 1].second;}; 
            if(candLength < candC){candLength = candC; candString = array[row - 1][col].second;}
            array[row][col].first = candLength; array[row][col].second = candString;
        }
    }

    std::cout << array[n][m].second << std::endl;

    return 0;
}

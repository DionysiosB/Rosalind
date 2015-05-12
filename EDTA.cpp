#include <iostream>
#include <vector>

int main(){

    std::string name; getline(std::cin, name);
    std::string a; getline(std::cin, a);
    getline(std::cin, name);
    std::string b; getline(std::cin, b);
    int n = a.size(); int m = b.size();

    std::vector<std::vector<long> > score(n + 1, std::vector<long>(m + 1, 0));
    std::vector<std::vector<char> > prev(n + 1, std::vector<char>(m + 1, 'X'));
    for(int p = 1; p <= n; p++){score[p][0] = p; prev[p][0] = 'V';}
    for(int p = 1; p <= m; p++){score[0][p] = p; prev[0][p] = 'H';}

    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= m; col++){
            int candA = score[row - 1][col - 1] + (1 - (a[row - 1] == b[col - 1]));
            int candB = score[row - 1][col] + 1;
            int candC = score[row][col - 1] + 1;
            int cand = candA; char dir = 'D';
            if(candB < cand){cand = candB; dir = 'V';}; if(candC < cand){cand = candC; dir = 'H';}
            score[row][col] = cand;
            prev[row][col] = dir;
        }
    }

    printf("%ld\n", score[n][m]);
    std::string f(""), g("");
    int row(n), col(m);
    while(row > 0 || col > 0){
        if(prev[row][col] == 'D'){f = a[row - 1] + f; g = b[col - 1] + g; --row; --col;}
        else if(prev[row][col] == 'H'){f = '-' + f; g = b[col - 1] + g; --col;}
        else if(prev[row][col] == 'V'){f = a[row - 1] + f; g = '-' + g; --row;}
    }
    std::cout << f << std::endl << g << std::endl;

    return 0;
}

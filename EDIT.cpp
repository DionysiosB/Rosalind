#include <iostream>
#include <vector>

int main(){

    std::string name; getline(std::cin, name);
    std::string a; getline(std::cin, a);
    getline(std::cin, name);
    std::string b; getline(std::cin, b);
    int n = a.size(); int m = b.size();

    std::vector<std::vector<long> > score(n + 1, std::vector<long>(m + 1, 0));
    for(int p = 0; p <= n; p++){score[p][0] = p;}
    for(int p = 0; p <= m; p++){score[0][p] = p;}

    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= m; col++){
            int candA = score[row - 1][col - 1] + (1 - (a[row - 1] == b[col - 1]));
            int candB = score[row - 1][col] + 1;
            int candC = score[row][col - 1] + 1;
            int cand = candA;if(candB < cand){cand = candB;}; if(candC < cand){cand = candC;}
            score[row][col] = cand;
        }
    }

    //for(int row = 0; row <= n; row++){for(int col = 0; col <= m; col++){std::cout << score[row][col] << " ";}; std::cout << std::endl;}
    printf("%ld\n", score[n][m]);

    return 0;
}

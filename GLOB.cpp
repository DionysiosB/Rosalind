#include <iostream>
#include <vector>
#include <map>


std::map<std::pair<char, char>, int> constructPairScoreMatrix(){

    std::map<std::pair<char, char>, int> out;
    std::string aas ="ACDEFGHIKLMNPQRSTVWY";
    int matrix[] ={4,0,-2,-1,-2,0,-2,-1,-1,-1,-1,-2,-1,-1,-1,1,0,0,-3,-2,0,9,-3,-4,-2,-3,-3,-1,-3,-1,-1,-3,-3,-3,-3,-1,-1,-1,-2,-2,-2,-3,6,2,-3,-1,-1,-3,-1,-4,-3,1,-1,0,-2,0,-1,-3,-4,-3,-1,-4,2,5,-3,-2,0,-3,1,-3,-2,0,-1,2,0,0,-1,-2,-3,-2,-2,-2,-3,-3,6,-3,-1,0,-3,0,0,-3,-4,-3,-3,-2,-2,-1,1,3,0,-3,-1,-2,-3,6,-2,-4,-2,-4,-3,0,-2,-2,-2,0,-2,-3,-2,-3,-2,-3,-1,0,-1,-2,8,-3,-1,-3,-2,1,-2,0,0,-1,-2,-3,-2,2,-1,-1,-3,-3,0,-4,-3,4,-3,2,1,-3,-3,-3,-3,-2,-1,3,-3,-1,-1,-3,-1,1,-3,-2,-1,-3,5,-2,-1,0,-1,1,2,0,-1,-2,-3,-2,-1,-1,-4,-3,0,-4,-3,2,-2,4,2,-3,-3,-2,-2,-2,-1,1,-2,-1,-1,-1,-3,-2,0,-3,-2,1,-1,2,5,-2,-2,0,-1,-1,-1,1,-1,-1,-2,-3,1,0,-3,0,1,-3,0,-3,-2,6,-2,0,0,1,0,-3,-4,-2,-1,-3,-1,-1,-4,-2,-2,-3,-1,-3,-2,-2,7,-1,-2,-1,-1,-2,-4,-3,-1,-3,0,2,-3,-2,0,-3,1,-2,0,0,-1,5,1,0,-1,-2,-2,-1,-1,-3,-2,0,-3,-2,0,-3,2,-2,-1,0,-2,1,5,-1,-1,-3,-3,-2,1,-1,0,0,-2,0,-1,-2,0,-2,-1,1,-1,0,-1,4,1,-2,-3,-2,0,-1,-1,-1,-2,-2,-2,-1,-1,-1,-1,0,-1,-1,-1,1,5,0,-2,-2,0,-1,-3,-2,-1,-3,-3,3,-2,1,1,-3,-2,-2,-3,-2,0,4,-3,-1,-3,-2,-4,-3,1,-2,-2,-3,-3,-2,-1,-4,-4,-2,-3,-3,-2,-3,11,2,-2,-2,-3,-2,3,-3,2,-1,-2,-1,-1,-2,-3,-1,-2,-2,-2,-1,2,7};

    int counter(0);
    for(int p = 0; p < aas.size(); p++){
        for(int q = 0; q < aas.size(); q++){
            std::pair<char, char> key = std::pair<char, char>(aas[p], aas[q]);
            int value = matrix[counter++];
            std::pair<std::pair<char, char>, int> entry = std::pair<std::pair<char, char>, int>(key, value);
            out.insert(entry);
        }
    }

    //Verify:
    //for(int p = 0; p < aas.size(); p++){for(int q = 0; q < aas.size(); q++){std::cout << aas[p] << " " << aas[q] << "\t" << out[std::pair<char, char>(aas[p], aas[q])] << std::endl;}}
    return out;
}



int main(){

    const int gapPenalty = -5;
    std::map<std::pair<char, char>, int> pairScore = constructPairScoreMatrix();


    std::string name; getline(std::cin, name);
    std::string a; getline(std::cin, a);
    getline(std::cin, name);
    std::string b; getline(std::cin, b);
    int n = a.size(); int m = b.size();

    std::vector<std::vector<long> > score(n + 1, std::vector<long>(m + 1, 0));
    for(int p = 0; p <= n; p++){score[p][0] = gapPenalty * p;}
    for(int p = 0; p <= m; p++){score[0][p] = gapPenalty * p;}

    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= m; col++){
            int candA = score[row - 1][col - 1] + pairScore[std::pair<char, char>(a[row - 1], b[col - 1])];
            int candB = score[row - 1][col] + gapPenalty;
            int candC = score[row][col - 1] + gapPenalty;
            int cand = candA;if(candB > cand){cand = candB;}; if(candC > cand){cand = candC;}
            score[row][col] = cand;
        }
    }

    //for(int row = 0; row <= n; row++){for(int col = 0; col <= m; col++){std::cout << score[row][col] << "\t";}; std::cout << std::endl;}
    printf("%ld\n", score[n][m]);

    return 0;
}

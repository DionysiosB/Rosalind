#include <iostream>
#include <vector>
using namespace std;

int main(){

    //Remove names from input
    std::string a; getline(std::cin, a); int s = a.size(); 
    std::string b; getline(std::cin, b); int t = b.size(); 
    std::string c; getline(std::cin, c); int u = c.size(); 
    std::string d; getline(std::cin, d); int v = d.size(); 

    vector<vector<vector<vector<long> > > > score(s + 1, vector<vector<vector<long> > >(t + 1, vector<vector<long> >(u + 1, vector<long>(v + 1))));
    vector<vector<vector<vector<long> > > >  prev(s + 1, vector<vector<vector<long> > >(t + 1, vector<vector<long> >(u + 1, vector<long>(v + 1))));

    for(int p = 1; p <= s; p++){score[p][0][0][0] = -3 * p; prev[p][0][0][0] = 8;}
    for(int p = 1; p <= t; p++){score[0][p][0][0] = -3 * p; prev[0][p][0][0] = 4;}
    for(int p = 1; p <= u; p++){score[0][0][p][0] = -3 * p; prev[0][0][p][0] = 2;}
    for(int p = 1; p <= v; p++){score[0][0][0][p] = -3 * p; prev[0][0][0][p] = 1;}

    for(int x = 1; x <= s; x++){
        for(int y = 1; y <= t; y++){
            for(int z = 1; z <= u; z++){
                for(int w = 1; w <= v; w++){
                    int cand_XYZW = score[x - 1][y - 1][z - 1][w - 1] - (a[x - 1] != b[y - 1]) - (a[x - 1] != c[z - 1]) - (a[x - 1] != d[w - 1]) - (b[y - 1] != c[z - 1]) - (b[y - 1] != d[w - 1]) - (c[z - 1] != d[w - 1]); 

                    int cand_YZW = score[x][y - 1][z - 1][w - 1] - 3 - (b[y - 1] != c[z - 1]) - (b[y - 1] != d[w - 1]) - (c[z - 1] != d[w - 1]); 
                    int cand_XZW = score[x - 1][y][z - 1][w - 1] - 3 - (a[x - 1] != c[z - 1]) - (a[x - 1] != d[w - 1]) - (c[z - 1] != d[w - 1]); 
                    int cand_XYW = score[x - 1][y - 1][z][w - 1] - 3 - (a[x - 1] != b[y - 1]) - (a[x - 1] != d[w - 1]) - (b[y - 1] != d[w - 1]); 
                    int cand_XYZ = score[x - 1][y - 1][z - 1][w] - 3 - (a[x - 1] != b[y - 1]) - (a[x - 1] != c[z - 1]) - (b[y - 1] != c[z - 1]); 

                    int cand_ZW = score[x][y][z - 1][w - 1] - 4 - (c[z - 1] != d[w - 1]); 
                    int cand_YW = score[x][y - 1][z][w - 1] - 4 - (b[y - 1] != d[w - 1]);
                    int cand_YZ = score[x][y - 1][z - 1][w] - 4 - (b[y - 1] != c[z - 1]);
                    int cand_XW = score[x - 1][y][z][w - 1] - 4 - (a[x - 1] != d[w - 1]);
                    int cand_XZ = score[x - 1][y][z - 1][w] - 4 - (a[x - 1] != c[z - 1]);
                    int cand_XY = score[x - 1][y - 1][z][w] - 4 - (a[x - 1] != b[y - 1]);

                    int cand_X = score[x - 1][y][z][w] - 3;
                    int cand_Y = score[x][y - 1][z][w] - 3;
                    int cand_Z = score[x][y][z - 1][w] - 3;
                    int cand_W = score[x][y][z][w - 1] - 3;

                    int cand = cand_XYZW; int dir = 15;

                    if(cand_YZW > cand){cand = cand_YZW; dir = 7;}
                    if(cand_XZW > cand){cand = cand_YZW; dir = 11;}
                    if(cand_XYW > cand){cand = cand_YZW; dir = 13;}
                    if(cand_XYZ > cand){cand = cand_YZW; dir = 14;}

                    if(cand_ZW > cand){cand = cand_ZW; dir = 3;}
                    if(cand_YW > cand){cand = cand_YW; dir = 5;}
                    if(cand_YZ > cand){cand = cand_YZ; dir = 6;}
                    if(cand_XW > cand){cand = cand_XW; dir = 9;}
                    if(cand_XZ > cand){cand = cand_XZ; dir = 10;}
                    if(cand_XY > cand){cand = cand_XY; dir = 12;}

                    if(cand_X > cand){cand = cand_X; dir = 8;}
                    if(cand_Y > cand){cand = cand_Y; dir = 4;}
                    if(cand_Z > cand){cand = cand_Z; dir = 2;}
                    if(cand_W > cand){cand = cand_W; dir = 1;}

                    score[x][y][z][w] = cand; 
                    prev[x][y][z][w] = dir;
                    std::cout << x << " " << y << " " << z << " " << w << "\tSCORE: " << cand << "\t FROM:" << dir <<  std::endl;
                }
            }
        }
    }

    printf("%ld\n", score[s][t][u][v]);
    /*
    std::string f(""), g("");
    int x(n), y(m);
    while(x > 0 || y > 0){
        if(prev[x][y] == 'D'){f = a[x - 1] + f; g = b[y - 1] + g; --x; --y;}
        else if(prev[x][y] == 'H'){f = '-' + f; g = b[y - 1] + g; --y;}
        else if(prev[x][y] == 'V'){f = a[x - 1] + f; g = '-' + g; --x;}
    }
    std::cout << f << std::endl << g << std::endl;
    */

    return 0;
}

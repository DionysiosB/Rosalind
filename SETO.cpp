#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main(){

    int n; scanf("%d\n", &n);
    std::vector<int> omega(n);
    for(int p = 0; p < n; p++){omega[p] = p + 1;}

    std::vector<int> A, B;

    int num;
    std::string firstSet; getline(std::cin, firstSet); std::stringstream fss(firstSet); while (fss >> num){A.push_back(num);}
    std::string secondSet; getline(std::cin, secondSet); std::stringstream sss(secondSet); while (sss >> num){B.push_back(num);}
    sort(A.begin(), A.end()); sort(B.begin(), B.end());

    std::vector<int> C(n, 0); std::vector<int>::iterator it;

    it = std::set_union(A.begin(), A.end(), B.begin(), B.end(), C.begin()); C.resize(it - C.begin());
    printf("{"); for(int p = 0; p < C.size() - 1; p++){printf("%d, ", C[p]);} printf("%d}\n", C[C.size() - 1]);
    C.clear();C.resize(n);

    it = std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), C.begin()); C.resize(it - C.begin());
    printf("{"); for(int p = 0; p < C.size() - 1; p++){printf("%d, ", C[p]);} printf("%d}\n", C[C.size() - 1]);
    C.clear(); C.resize(n);

    it = std::set_difference(A.begin(), A.end(), B.begin(), B.end(), C.begin()); C.resize(it - C.begin());
    printf("{"); for(int p = 0; p < C.size() - 1; p++){printf("%d, ", C[p]);} printf("%d}\n", C[C.size() - 1]);
    C.clear(); C.resize(n);

    it = std::set_difference(B.begin(), B.end(), A.begin(), A.end(), C.begin()); C.resize(it - C.begin());
    printf("{"); for(int p = 0; p < C.size() - 1; p++){printf("%d, ", C[p]);} printf("%d}\n", C[C.size() - 1]);
    C.clear(); C.resize(n);

    it = std::set_difference(omega.begin(), omega.end(), A.begin(), A.end(), C.begin()); C.resize(it - C.begin());
    printf("{"); for(int p = 0; p < C.size() - 1; p++){printf("%d, ", C[p]);} printf("%d}\n", C[C.size() - 1]);
    C.clear(); C.resize(n);

    it = std::set_difference(omega.begin(), omega.end(), B.begin(), B.end(), C.begin()); C.resize(it - C.begin());
    printf("{"); for(int p = 0; p < C.size() - 1; p++){printf("%d, ", C[p]);} printf("%d}\n", C[C.size() - 1]);
    C.clear(); C.resize(n);
    return 0;
}

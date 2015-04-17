#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    int n; scanf("%d\n", &n);
    long total = 1;
    std::vector<int> array(n);
    for(int p = 0; p < n; p++){array[p] = p + 1; total *= p + 1;}
    printf("%ld\n", total);

    do{for(int p = 0; p < n; p++){printf("%d ", array[p]);}; puts("");} while(std::next_permutation(array.begin(), array.end()));

    return 0;
}

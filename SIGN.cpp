#include <cstdio>
#include <vector>

int main(){

    int n; scanf("%d\n", &n);
    long power = 1; for(int p = 0; p < n; p++, power *= 2);
    std::vector<int> array;

    long total = power; 
    for(int p = 1; p <= n; p++){array.push_back(p); total *= p;}
    printf("%ld\n", total);

    do{
        for(int p = 0; p < power; p++){
            long q = p;
            for(int r = 0; r < n; r++){printf("%d ", (q % 2) ? (-array[r]) : (array[r])); q /= 2;}
            puts("");
        }
    }while(std::next_permutation(array.begin(), array.end()));

    return 0;
}

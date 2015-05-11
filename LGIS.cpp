#include <cstdio>
#include <vector>

int main(){

    long n; scanf("%ld\n", &n);
    std::vector<long> data(n,0);
    for(int p = 0; p < n; p++){scanf("%ld", &data[p]);}

    std::vector<long> longestInc(n, 1); 
    std::vector<long> prevInc(n, 0); for(int p = 0; p < n; p++){prevInc[p] = p;}
    std::vector<long> longestDec(n, 1);
    std::vector<long> prevDec(n, 0); for(int p = 0; p < n; p++){prevDec[p] = p;}

    for(int p = 0; p < n; p++){
        for(int k = 0; k < p; k++){
            if(data[k] < data[p] && (longestInc[p] < longestInc[k] + 1)){longestInc[p] = 1 + longestInc[k]; prevInc[p] = k;}
            if(data[k] > data[p] && (longestDec[p] < longestDec[k] + 1)){longestDec[p] = 1 + longestDec[k]; prevDec[p] = k;}
        }
    }

    long maxLengthInc(0), maxLengthIncEnd(0); for(int p = 0; p < n; p++){if(maxLengthInc < longestInc[p]){maxLengthInc = longestInc[p]; maxLengthIncEnd = p;}}
    long maxLengthDec(0), maxLengthDecEnd(0); for(int p = 0; p < n; p++){if(maxLengthDec < longestDec[p]){maxLengthDec = longestDec[p]; maxLengthDecEnd = p;}}

    std::vector<long> maxLengthIncSeq; long index = maxLengthIncEnd;
    while(true){
        maxLengthIncSeq.push_back(data[index]);
        if(index <= prevInc[index]){break;}
        index = prevInc[index];
    }

    std::vector<long> maxLengthDecSeq; index = maxLengthDecEnd;
    while(true){
        maxLengthDecSeq.push_back(data[index]);
        if(index <= prevDec[index]){break;}
        index = prevDec[index];
   }

    for(int p = maxLengthIncSeq.size() - 1; p >= 0; p--){printf("%ld ", maxLengthIncSeq[p]);}; puts("");
    for(int p = maxLengthDecSeq.size() - 1; p >= 0; p--){printf("%ld ", maxLengthDecSeq[p]);}; puts("");

    return 0;
}

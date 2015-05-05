#include <iostream>
#include <map>

int main(){

    std::map<char, double> weight;

    weight.insert(std::pair<char, double>('A',71.03711));
    weight.insert(std::pair<char, double>('C',103.00919));
    weight.insert(std::pair<char, double>('D',115.02694));
    weight.insert(std::pair<char, double>('E',129.04259));
    weight.insert(std::pair<char, double>('F',147.06841));
    weight.insert(std::pair<char, double>('G',57.02146));
    weight.insert(std::pair<char, double>('H',137.05891));
    weight.insert(std::pair<char, double>('I',113.08406));
    weight.insert(std::pair<char, double>('K',128.09496));
    weight.insert(std::pair<char, double>('L',113.08406));
    weight.insert(std::pair<char, double>('M',131.04049));
    weight.insert(std::pair<char, double>('N',114.04293));
    weight.insert(std::pair<char, double>('P',97.05276));
    weight.insert(std::pair<char, double>('Q',128.05858));
    weight.insert(std::pair<char, double>('R',156.10111));
    weight.insert(std::pair<char, double>('S',87.03203));
    weight.insert(std::pair<char, double>('T',101.04768));
    weight.insert(std::pair<char, double>('V',99.06841));
    weight.insert(std::pair<char, double>('W',186.07931));
    weight.insert(std::pair<char, double>('Y',163.06333));

    const double epsilon = 0.01;
    double meas(0), prev(-1);
    while(std::cin >> meas){
        if(prev < 0){prev = meas; continue;}
        double diff = meas - prev;
        for(std::map<char, double>::iterator mapIter = weight.begin(); mapIter != weight.end(); mapIter++){
            char aminoacid = mapIter->first;
            double weight = mapIter->second;
            if(-epsilon <= weight - diff && weight - diff <= epsilon){printf("%c", aminoacid); break;}
        }
        prev = meas;
    }
    puts("");

    return 0;
}

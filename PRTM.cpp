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

    std::string protein; getline(std::cin, protein);
    double totalWeight(0);
    for(int p = 0; p < protein.size(); p++){totalWeight += weight[protein[p]];}
    printf("%.5lf\n", totalWeight);

    return 0;
}

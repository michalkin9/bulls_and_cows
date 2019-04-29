#include "calculate.hpp"
#include <iostream>
#include <string>


using std::string;

string bullpgia::calculateBullAndPgia(string chooser, string guesser) {
    int bull = 0, pgia = 0;
    string ans;
    int size = chooser.length();
    int arr[size];
    if(size != guesser.length()){
        throw "The guess's length is not equal to the choice's length";
    }
    for(int i=0; i<size; i++){
        if(chooser[i] == guesser[i]) bull++;
        else{
            size_t found = chooser.find(guesser[i]); 
            if(found<size && arr[found] != -1){
                pgia++;
                arr[found] = -1;
            }
    }
    ans = bull +","+ pgia;
    return ans;
}
}

#include "calculate.hpp"
#include <iostream>
#include <string>


using namespace std;

/*
* This function gets 2 strings and check how many bulls and cows were.
* @param chooser - the string that we need to guess
* @param guesser - the string that we try to guess with.
* @return - string in the format: "bull,cow".
*
*/
string bullpgia::calculateBullAndPgia(string chooser, string guesser) {
    int bull = 0, pgia = 0;
    string ans="";
    int size = chooser.size();
    int arr[size];

    for(int i=0; i<size; i++){
        if(chooser[i] == guesser[i]){
            bull++;
            arr[i] = -1;
           // cout << guesser.at(i) <<endl;
        }
        else{
            size_t found = chooser.find(guesser[i]); 
            if(found<size && arr[found] != -1){
                pgia++;
                arr[found] = -1;
                //cout << guesser[i] <<endl;
            }
    }
    }
    ans = to_string(bull) +","+ to_string(pgia);
    return ans;
}


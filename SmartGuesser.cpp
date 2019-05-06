#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace bullpgia;

string SmartGuesser::guess(){

set<string>::iterator it=options.begin();
int randomIndex = rand()%options.size(); //calculate random index
advance(it,randomIndex); //taking random number from all the options
_guess = *it; 
return _guess;

}

void SmartGuesser::learn(string calculateStatus) {

		for (set<string>::iterator it=options.begin(); it!=options.end();){
		string ans = calculateBullAndPgia(*it, _guess);
		if(!calculateStatus.compare(ans)){
			cout<<"hello\n";
			it = options.erase(it);
		}
		else
		{
			++it;
		}
		
	}
}
void SmartGuesser::startNewGame(uint length){
	//starting a new game with the length, builidng a set of options
	this->length = length;
	buildset(length);
}

void SmartGuesser::buildset(int length){
	//building set with all the guess options
	string num;
	int MAX_NUM;
	int curr_length;
	for(int i = 0; i < length; i++){
		num += "9";
	}
	MAX_NUM = std::stoi(num);	
	
	for(int i=0; i <= MAX_NUM; i++){
		string curr = to_string(i);
		ostringstream ss;
		ss  << setw(length) << setfill('0') << curr;
		options.insert(ss.str());
	}
	// for (set<string>::iterator it=options.begin(); it!=options.end(); ++it){
	// 	cout << ' ' << *it;
	// 	cout<<"\n";
	// }
}



// void SmartGuesser::remove_from_set(string calculateStatus, string choice){
	
// 		for (set<string>::iterator it=options.begin(); it!=options.end();){
// 		string ans = calculateBullAndPgia(*it, choice);
// 		if(!calculateStatus.compare(ans)){
// 			cout<<"hello\n";
// 			it = options.erase(it);
// 		}
// 		else
// 		{
// 			++it;
// 		}
		
// 	}
// }










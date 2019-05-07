#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace bullpgia;

/*
*The function guess chooses a random guess from the list of options
*@return _guess - the random guess 
*/
string SmartGuesser::guess(){
 list<string>::iterator it=options.begin();
int randomIndex = rand()%options.size(); //calculate random index
advance(it,randomIndex); //taking random number from all the options
_guess = *it; 
return _guess;

}

/*
*The function learn iterate through the list of options and erase options that dont get the same result from "calculateBullAndPgia()"
*@param calculateStatus - the status of the current guess and the secret choice 
*/
void SmartGuesser::learn(string calculateStatus) {


		for (list<string>::iterator it=options.begin(); it!=options.end();){
		string ans = calculateBullAndPgia(*it,_guess);
		if(calculateStatus!=ans){
			it = options.erase(it);
		}
		else
		{
			it++;
		}
		
	}

}

/*
*The function startNewGame - starts a new game by building a list with all the guess options
*/
void SmartGuesser::startNewGame(uint length){
	//starting a new game with the length, builidng a set of options
	this->length = length;
	buildset(length);
}

/*
*The function buildset - builids a set when the amount of options depends on the length of the guess
*@param length - the lentgh of the guess 
*/
void SmartGuesser::buildset(uint length){
	//building set with all the guess options
	string num;
	int MAX_NUM;
	
	if(!options.empty()){
		options.clear();
	}

	for(int i = 0; i < length; i++){
		num += "9";
	}
	
	MAX_NUM = std::stoi(num);	
	
	for(int i=0; i <= MAX_NUM; i++){
		string curr = to_string(i);
		ostringstream ss;
		ss  << setw(length) << setfill('0') << curr;
		string s = ss.str();
		options.push_back(s);
	}
	
}

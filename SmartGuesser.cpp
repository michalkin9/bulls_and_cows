#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <iomanip>

using namespace std;
using namespace bullpgia;

string SmartGuesser::guess(){
		string str;
		#int currGuess = random(length);
		#learn(calculateBullandPgia(currGuess), currGuess);
		#check if there are 4 bulls - if so - win and return.
		#else call learn.
		return str;

		}
void SmartGuesser::learn (string st) {
	#need to call remove from here
	#if 1 left - win
	
}
void SmartGuesser::startNewGame(uint length){
	this->length = length;
	buildset(length);
}

int SmartGuesser::random(int length){
	// rand between 0000 to length
}
void SmartGuesser::buildset(int length){
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
	for (set<string>::iterator it=options.begin(); it!=options.end(); ++it){
		cout << ' ' << *it;
		cout<<"\n";
	}
}

void SmartGuesser::remove_from_set(string status, string choice){
	
	for (set<string>::iterator it=options.begin(); it!=options.end();){
		string ans = calculateBullAndPgia(*it, choice);
		if(!status.compare(ans)){
			cout<<"hello\n";
			it = options.erase(it);
		}
		else
		{
			++it;
		}
		
	}
	
	// cout <<"newSetttttt"<<endl;
	// for (set<string>::iterator it=options.begin(); it!=options.end(); ++it){
	// 	cout << ' ' << *it;
	// 	cout<<"\n";
	// }
	
}








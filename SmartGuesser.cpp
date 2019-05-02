#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <iomanip>

using namespace std;
using namespace bullpgia;

string SmartGuesser::guess(){
			string str;
			return str;

		}
void SmartGuesser::learn (string st) {}
void SmartGuesser::startNewGame(uint length){
	this->length = length;
	buildset(length);
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








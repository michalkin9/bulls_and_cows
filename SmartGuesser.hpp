#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <string>
#include <list>
#include <iterator>

using namespace std;

namespace bullpgia{
	
class SmartGuesser: public bullpgia::Guesser {
	public:
		string guess() override;
		string _guess;
		list<string> options;
		void buildset(uint length);
		void learn (string st) override;
		void startNewGame(uint length) override;
};
}
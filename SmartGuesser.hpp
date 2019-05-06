#pragma once
#include "Guesser.hpp"
#include "Chooser.hpp"
#include "calculate.hpp"
#include <string>
#include <set>
#include <iterator>

using namespace std;

namespace bullpgia{
	
class SmartGuesser: public bullpgia::Guesser {
	public:
		string guess() override;
		string _guess;
		set<string> options = {};
		void buildset(int length);
		void learn (string st) override;
		void startNewGame(uint length) override;
		void remove_from_set(string status, string choice);
};
}

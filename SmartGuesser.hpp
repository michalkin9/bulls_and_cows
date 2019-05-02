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
		set<string> options = {};
		void buildset(int length);
		void remove_from_set(string status, set<string>);
		void learn (string st) override;
		void startNewGame(uint length) override;
};
}
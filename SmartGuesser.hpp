#pragma once
#include "Guesser.hpp"
#include "Chooser.hpp"
#include "calculate.hpp"
#include <string>
using std::string;
namespace bullpgia{
class SmartGuesser: public bullpgia::Guesser {
	string guess() override;
	void learn (string st) override;
	void startNewGame(uint length) override;
};
}
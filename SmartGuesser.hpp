#pragma once
#include "Guesser.hpp"
using std::string;

class SmartGuesser: public bullpgia::Guesser {
	string guess() override;
};
#pragma once
#include<string>
#include<iostream>

using std::string;
using namespace bullpgia;

Class Guesser{
    public:
        virtual string guess(unsigned int length) = 0;
        virtual void startNewGame(const unsigned int length);
        void virtual learn(const string reply);

}


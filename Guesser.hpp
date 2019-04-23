#pragma once
#include<string>
#include<iostream>

using std::string;
typedef unsigned int uint;
namespace bullpgia {
    class Guesser{
        protected:
            string replay;
            uint length;
        public:
            virtual string guess() = 0;
           virtual void startNewGame(uint length){}
            virtual void learn(string reply){}

    };
}


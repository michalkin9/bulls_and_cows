#pragma once
#include<string>

using std::string;
//using namespace bullpgia;

namespace bullpgia{
class Chooser{
    public:
    virtual string choose(uint length) = 0;
    
};
}


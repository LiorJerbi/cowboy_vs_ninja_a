#pragma once

#include "ninja.hpp"
#include <string>
namespace ariel{

class OldNinja: public Ninja{
    public:
        OldNinja(const std::string& name,Point spot);
        void move(Character *enemy);
};

}
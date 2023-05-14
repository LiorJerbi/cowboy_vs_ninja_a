#pragma once

#include "character.hpp"
#include <string>
namespace ariel{

class Cowboy: public Character{

    private:
        int _bullet_amount;

    public:
        Cowboy(std::string& name,Point &spot);
        ~Cowboy(){}
        void shoot(Character* enemy);
        bool hasboolets() const;
        void reload();
        int getBullAmount() const;
        std::string print() const;
};

}
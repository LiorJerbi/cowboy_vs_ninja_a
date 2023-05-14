#pragma once
#include "point.hpp"
#include <string>
namespace ariel{

class Character{

    protected:      //only accessiable by subclasses
        Point& _spot;
        int _hitpoints;
        std::string _name;
    private:

    public:
        Character(std::string& name,Point& spot,int hitpoints);
        bool isAlive() const;
        double distance(Character *other) const;
        void hit(int dmg);

        std::string getName() const;
        Point& getLocation() const;
        virtual std::string print() const = 0;

        virtual ~Character(){};

};

}
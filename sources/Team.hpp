#pragma once

#include <vector>
#include "character.hpp"
#include "ninja.hpp"
#include "oldninja.hpp"
#include "youngninja.hpp"
#include "trainedninja.hpp"
#include "cowboy.hpp"

namespace ariel{

    class Team{

        // protected:
        //     Character *_leader;
        //     std::vector<Character*> _squad;
        private:
            Character *_leader;
            std::vector<Character*> _squad;            
        public:
            Team(Character* leader);
            void add(Character* member);
            virtual void attack(Team* enmy_team);
            int stillAlive() const;
            virtual void print() const;
            virtual ~Team(){}
    };


}
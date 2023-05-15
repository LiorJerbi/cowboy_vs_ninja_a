#include "character.hpp"


using namespace ariel;
using namespace std;

Character::Character(const string& name,Point& spot,int hitpoints):_name(name),_spot(spot),_hitpoints(hitpoints){
}

bool Character::isAlive() const{
    return (_hitpoints>0) ? true : false;
}
double Character::distance(Character *other) const{
    return _spot.distance(other->_spot);
}
void Character::hit(int dmg){
    if(_hitpoints>0){
       _hitpoints-=dmg; 
    }  
}

string Character::getName() const{
    return _name;
}
Point& Character::getLocation() const{
    return _spot;
}
Character::~Character(){
    
}

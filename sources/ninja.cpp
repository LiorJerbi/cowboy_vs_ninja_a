#include "ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(const string& name,Point &spot,int hitpoints, int speed):Character(name,spot,hitpoints),_speed(speed){
}
void Ninja::slash(Character *enemy){

}
string Ninja::print() const{
    string ans = "N: ";
    if(_hitpoints>0){
        ans += _name + " " + to_string(_hitpoints) + " " + _spot.print();
    }
    else{
        ans += "("+_name + ") " + _spot.print();
    }
    return ans;
}
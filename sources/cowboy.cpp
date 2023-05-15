#include "cowboy.hpp"

using namespace ariel;
using namespace std;


Cowboy::Cowboy(const std::string& name,Point spot):Character(name,spot,110),_bullet_amount(6){};

void Cowboy::shoot(Character* enemy){
    if(_hitpoints<=0 && hasboolets()){
        _bullet_amount--;
        enemy->hit(10);
    }
    
}
bool Cowboy::hasboolets() const{
    return (_bullet_amount>0) ? true : false;
}
void Cowboy::reload(){
    _bullet_amount=6;
}
int Cowboy::getBullAmount() const{
    return _bullet_amount;
}
string Cowboy::print() const{
    string ans = "C: ";
    if(_hitpoints>0){
        ans += _name + " " + to_string(_hitpoints) + " " + _spot.print();
    }
    else{
        ans += "("+_name + ") " + _spot.print();
    }
    return ans;
}
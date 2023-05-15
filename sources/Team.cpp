#include "Team.hpp"

using namespace ariel;
using namespace std;

Team::Team(Character* leader):_leader(leader){}
void Team::add(Character* member){

}
void Team::attack(Team* enmy_team){

}
int Team::stillAlive() const{
    return 0;
}
void Team::print() const{
    
}
// Team::~Team(){
//     // delete _leader;
//     // for (auto member : _squad)
//     // {
//     //     delete member;
//     // }
// }
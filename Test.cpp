#include "doctest.h"
#include "sources/character.hpp"
#include "sources/oldninja.hpp"
#include "sources/youngninja.hpp"
#include "sources/trainedninja.hpp"
#include "sources/cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/team2.hpp"
#include "sources/smartteam.hpp"
#include "string"
using namespace std;
using namespace ariel;

TEST_CASE("Point Tests:"){
    Point p1(2,7);
    Point p2(0,7);
    Point p3(3.14,0.7777);
    Point q1(-1,-2);
    Point q2(0,0);
    Point q3(-1,2);
    
    CHECK_EQ(p1.distance(p2),2.0);
    CHECK_FALSE(p2.distance(q2)!=7.0);

    CHECK_EQ(q2.distance(q1),q2.distance(q3));
    CHECK((p1.distance(q1)<9.5&&p1.distance(q1)>9.4));
    CHECK_EQ(p3.distance(p1),p1.distance(p3));

    double d = p2.distance(q2);

    Point t1 = Point::moveTowards(p2,q2,d/2);
    CHECK_EQ(p2.distance(t1),d/2);
    Point t2 = Point::moveTowards(t1,q2,d/2);
    CHECK_EQ(t1.distance(q2),0);



}
TEST_CASE("Characters Tests:"){

    Cowboy c1("Lior",Point(1,0));
    Cowboy c2("Or",Point(-1,0));
    TrainedNinja n1("Yael",Point(0,1));

    CHECK_EQ(n1.getName(),"Yael");
    CHECK_EQ(c1.getName(),"Lior");
    CHECK((c2.isAlive()&&n1.isAlive()&&c1.isAlive()));
    CHECK_EQ(c1.distance(&n1),c2.distance(&n1));
    CHECK_EQ(c1.getLocation().distance(Point(1,0)),0);
    CHECK_EQ(c1.getLocation().distance(c2.getLocation()),2);

    CHECK_NOTHROW(c2.hit(110));
    CHECK_FALSE(c2.isAlive());
    
    //cowboy tests
    for(int i=1;i!=6;++i){      //shoot all mag
        c1.shoot(&n1);
    }
    CHECK_FALSE((c1.hasboolets()&&!n1.isAlive()));      //no bullets and ninja alive
    CHECK_NOTHROW(c1.shoot(&n1));
    c1.reload();
    YoungNinja yn("sheep",Point(5,2));
    yn.hit(90);
    CHECK(yn.isAlive());
    c1.shoot(&yn);
    CHECK((c1.hasboolets()&&!yn.isAlive()));        //has bullets after reload and ninja dead
    
    //ninja tests
    YoungNinja yn1("Young",Point(17,0));
    TrainedNinja tn1("Trained",Point(7,7));
    OldNinja on1("Old",Point(-1,5));

    CHECK_EQ(yn1.distance(&c1),16);
    yn1.move(&c1);      // 2 meters away(14 speed)
    CHECK_EQ(yn1.distance(&c1),2);
    yn1.slash(&c1);     //should not hit c1 still with 110hp
    CHECK_NOTHROW(yn1.slash(&c1));

    CHECK(tn1.distance(&c1)<12);
    tn1.move(&c1);      //has reached the cowboy(12 speed)
    CHECK_EQ(tn1.distance(&c1),0);
    CHECK_NOTHROW(tn1.slash(&c1),0);
    tn1.slash(&c1);     //should hit, hp left 70
    tn1.slash(&c1);    //should hit, hp left 30
    yn1.move(&c1);      //moving youngninja to cowboy, should reach;
    yn1.slash(&c1);     //should hit, cowboy dead
    CHECK_FALSE(c1.isAlive());

    CHECK(on1.distance(&n1)<5);     //should be approx 4.12
    on1.move(&n1);      //has reached the ninja.
    CHECK_EQ(on1.distance(&n1),0);
    on1.slash(&n1);     //had 60hp now 20hp
    n1.slash(&on1);     //slash back
    CHECK((on1.isAlive() && n1.isAlive()));
    on1.slash(&n1);     //had 20hp now dead.
    CHECK_NOTHROW(n1.slash(&on1));  //dead ninja slash not throws
    on1.hit(100);       //had 110 now have 10. to check if dead ninja does not make damage
    n1.slash(&on1);     //should not make impact
    CHECK(on1.isAlive());

}


TEST_CASE("Teams Tests:"){

    OldNinja leadninj("Splinter",Point(2.5,0));
    Team Ninja_Turtels(&leadninj);
    CHECK_EQ(Ninja_Turtels.stillAlive(),1);
    TrainedNinja tn1("Leonardo",Point(2,0.5));
    TrainedNinja tn2("Donatello",Point(3,0.5));
    TrainedNinja tn3("Michelangelo",Point(1.5,1));
    TrainedNinja tn4("Rafael",Point(3.5,1));
    Ninja_Turtels.add(&tn1);
    Ninja_Turtels.add(&tn2);
    Ninja_Turtels.add(&tn3);
    Ninja_Turtels.add(&tn4);
    CHECK_EQ(Ninja_Turtels.stillAlive(),5);

    Cowboy leadcby("Lucky luke", Point(2.5,-7));
    CHECK_THROWS(Team2(&leadninj));     //appointing leader of another squad 
    Team2 Lucky_luke(&leadcby);
    CHECK_EQ(Lucky_luke.stillAlive(),1);
    Cowboy cl1("Lucky luke2", Point(0,-7));
    Cowboy cl2("Lucky luke3", Point(1,-7));
    Cowboy cl3("Lucky luke4", Point(3,-7));
    Cowboy cl4("Lucky luke5", Point(1.5,-7));
    CHECK_EQ(Lucky_luke.stillAlive(),5);
    
    for(int i=0;i<2;++i){
        Ninja_Turtels.attack(&Lucky_luke);
    }
    CHECK(Lucky_luke.stillAlive()<5);
    


}
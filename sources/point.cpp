#include "point.hpp"
#include <iostream>
#include <cmath>
using namespace ariel;
using namespace std;

Point::Point(double x, double y):_x(x),_y(y){
}
double Point::getX() const{
    return _x;
}
double Point::getY() const{
    return _y;
}

double Point::distance(const Point &other) const{
    return sqrt(pow((other._x-_x),2.0)+pow((other._y-_y),2.0));
}

string Point::print() const{
    string ans;
    ans += "(" + to_string(getX()) + "," + to_string(getY()) + ")";
    return ans;
}

Point& Point::moveTowards(const Point &src,const Point &dst,double dist){   // need to implement
    return *this;
}

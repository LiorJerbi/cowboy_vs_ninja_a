#pragma once
#include <string>

namespace ariel{

class Point{

    private:
        double _x,_y;

    public:
        Point(double x, double y);

        double getX() const;
        double getY() const;
        double distance(const Point &other) const;

        std::string print() const;
        Point& moveTowards(const Point &src,const Point &dst,double dist);

};



}
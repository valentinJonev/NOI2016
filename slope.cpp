#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

# define PI           3.14159265358979323846
#define RADTODEG(R)((180.0 * R) / PI)

using namespace std;

class Point{
private:
    int x;
    int y;

public:
    int get_x(){
        return this->x;
    }

    int get_y(){
        return this->y;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    Point(){
    }

    void set_x(int x){
        this->x = x;
    }

    void set_y(int y){
        this->y = y;
    }
};

class Line{
private:
    Point p1;
    Point p2;
    double angle;

    void calculateAngle(){
        if(p1.get_y() == p2.get_y()) this->angle = 0;
        else if(p1.get_x() == p2.get_x()) this->angle = 90;
        else{
            double a, b, c, y, z;
            a = abs(p2.get_y() - p1.get_y());
            b = abs(p2.get_x() - p1.get_x());
            c = sqrt((a*a) + (b*b));
            y = a/c;
            z = asin(y);
            if(p1.get_x() < p2.get_x()){
                if(p1.get_y() < 0)
                    this->angle = -(RADTODEG(z));
                else
                    this->angle = RADTODEG(z);
            }
            else{
                if(p2.get_y() < 0)
                    this->angle = -(RADTODEG(z));
                else
                    this->angle = RADTODEG(z);
            }
        }
    }

public:
    Line(Point p1, Point p2){
        this->p1 = p1;
        this->p2 = p2;
        this->calculateAngle();
    }

    double get_angle(){
        return this->angle;
    }
};


int main()
{
    int n = 0;
    cin >> n;

    list<double> degrees;
    for(int i = 0; i< n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1);
        Point p2(x2, y2);
        Line line(p1, p2);
        if (find(degrees.begin(), degrees.end(), line.get_angle()) == degrees.end())
            degrees.push_back(line.get_angle());
    }
    cout << degrees.size();
}

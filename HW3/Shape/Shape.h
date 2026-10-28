#pragma once

class Shape {
public:
    virtual double getArea()=0;
    virtual ~Shape()=default;
};

class Rectangle: public Shape
{
private:
    double w;
    double h;
public:
    Rectangle(double w, double h): w(w), h(h) {};
    double getArea();
};

class Circle: public Shape
{
private:
    double r;
public:
    Circle(double r): r(r) {};
    double getArea();
};
//Elijah Morris
//Shapes Program

#include <iostream>
using namespace std;
class BasicShape{
protected:
    double area;
public:
    double getArea(){
        return area;
    }
    virtual void calcArea() = 0;
};
class Circle : public BasicShape{
private:
    long centerX;
    long centerY;
    double radius;
public:
    Circle(long cX, long cY, double r){
        centerX = cX;
        centerY = cY;
        radius = r;
        calcArea();
    }
    long getCenterX(){
        return centerX;
    }
    long getCenterY(){
        return centerY;
    }
    double getRadius(){
        return radius;
    }
    void calcArea(){
        area = 3.14159*radius*radius;
    }
};
class Rectangle : public BasicShape{
private:
    long width;
    long length;
public:
    Rectangle(long w, long l){
        width = w;
        length = l;
        calcArea();
    }
    long getWidth(){
        return width;
    }
    long getLength(){
        return length;
    }
    void calcArea(){
        area = length*width;
    }
};
class Triangle : public BasicShape{
private:
    long base;
    long height;
public:
    Triangle(long b, long h){
        base = b;
        height = h;
        calcArea();
    }
    long getBase(){
        return base;
    }
    long getHeight(){
        return height;
    }
    void calcArea(){
        area = (base*height) / 2.0;
    }
};
int main(){
    cout << "\nshapes.cpp program\n\n";
    Circle c(20, 30, 100.0);
    Rectangle r(110, 220);
    Triangle t(123, 456);
    BasicShape *s1 = &c;
    BasicShape *s2 = &r;
    BasicShape *s3 = &t;
    cout << "circle area:    " << s1->getArea() << endl;
    cout << "rectangle area: " << s2->getArea() << endl;
    cout << "triangle area: " << s3->getArea() << endl;
    cout << endl;
    return 0;
}


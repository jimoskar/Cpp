#include "std_lib_facilities.h"

class Rectangle {
protected:
    int height, width;
public:
    Rectangle() : height{0}, width{0} {}
    Rectangle(int height, int width) : height{height}, width {width} {}
    int area() {return height*width;}
    int circumference() {return 2*height+2*width;}
    void info() { cout << area() << "," <<circumference() << endl;}

};

class Square : public Rectangle {
    Square(int side) : Rectangle{side,side} {}
    
    void info() {
        
    }
};

class MyShape {
public:
    virtual int area() = 0;
    virtual int circumference() = 0;
    
};

class MyRectangle : public MyShape {
    int w, h;
public:
    MyRectangle(int w, int h) : w{w}, h{h} {}
    virtual int area() {return h*w;}
    virtual int circumference() { return 2*h+2*w;}
};

int main(){
    
    
    
    return 0;
}

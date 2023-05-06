#include <iostream>
#include "point.h"
#include "shape.h"
#include "rectangle.h"

using namespace std;

void testpoint();

void testshape();

void testrectangle();

int main() {
    testpoint();
    
    testshape();

    testrectangle();

    return 0;
}

void testpoint() {
    try {
        Point point0;
        Point point1(1, 1);
        if (!(point1.getx() == 1 && point1.gety() == 1)) throw 1;
        cout << point1 << endl;
        point1.setx(3).sety(4);
        if (!(point1.getx() == 3 && point1.gety() == 4)) throw 1;
        cout << point1 << endl;
        if (!(point0.distance(point1) == 5)) throw 1;
        point1.setx(0).sety(0);
        if (!(point0 == point1 && !(point0 != point1))) throw 1;
        point1.setx(3).sety(0);
        if (!(!(point0 == point1) && point0 != point1)) throw 1;
        point1.setx(0).sety(4);
        if (!(!(point0 == point1) && point0 != point1)) throw 1;
        point1.setx(3).sety(4);
        if (!(!(point0 == point1) && point0 != point1)) throw 1;
        cout << "test point: ok" << endl;
    }
    catch (...) {
        cout << "test point: failed" << endl;
    }
}

void testshape() {
    try {
        Point point0;
        Point point1(3, 4);
        Shape shape0(point0);
        if (!(shape0.getcenter() == point0)) throw 1;
        shape0.setcenter(point1);
        if (!(shape0.getcenter() == point1)) throw 1;
        cout << "test shape: ok" << endl;
    }
    catch (...) {
        cout << "test shape: failed" << endl;
    }    
}

void testrectangle() {
    try {
        Point point0;
        Point point1(3, 4);
        Rectangle rectangle0(point0);
        if (!(rectangle0.getcenter() == point0 && rectangle0.getheight() == 1 && rectangle0.getwidth() == 3)) throw 1;
        rectangle0.setcenter(point1);
        rectangle0.setheight(3);
        rectangle0.setwidth(1);
        if (!(rectangle0.getcenter() == point1 && rectangle0.getheight() == 3 && rectangle0.getwidth() == 1)) throw 1;
        cout << "test rectangle: ok" << endl;
    }
    catch (...) {
        cout << "test rectangle: failed" << endl;
    }    
}

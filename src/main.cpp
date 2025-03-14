#include <iostream>
#include "point.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;

void testpoint();

void outputshape(const Shape &);
void modifyshape(Shape &);
void testshape();

void testrectangle();

void testcircle();

void testsquare();

int main() {
    testpoint();
    
    testshape();

    testrectangle();

    testcircle();

    testsquare();

    return 0;
}

void testpoint() {
    try {
        Point point0;
        Point point1(1, 1);
        if (!(point1.getx() == 1 &&
                point1.gety() == 1)) throw 1;
        cout << point1 << endl;
        point1.setx(3).sety(4);
        if (!(point1.getx() == 3 &&
                point1.gety() == 4)) throw 1;
        cout << point1 << endl;
        if (!(point0.distance(point1) == 5)) throw 1;
        point1.setx(0).sety(0);
        if (!(point0 == point1 &&
                !(point0 != point1))) throw 1;
        point1.setx(3).sety(0);
        if (!(!(point0 == point1) &&
                point0 != point1)) throw 1;
        point1.setx(0).sety(4);
        if (!(!(point0 == point1) &&
                point0 != point1)) throw 1;
        point1.setx(3).sety(4);
        if (!(!(point0 == point1) &&
                point0 != point1)) throw 1;
        cout << "test point: ok" << endl;
    }
    catch (...) {
        cout << "test point: failed" << endl;
    }
}

void outputshape(const Shape & shape) {
    cout << "(" << shape.getcenter() << ")" << endl;
}

void modifyshape(Shape & shape) {
    shape.getcenter().setx(3);
    shape.getcenter().sety(4);
}

void testshape() {
    try {
        Point point;
        Shape shape(point);
        if (!(shape.getcenter() == point)) throw 1;
        outputshape(shape);
        modifyshape(shape);
        if (!(shape.getcenter().getx() == 3 &&
                shape.getcenter().gety() == 4)) throw 1;
        outputshape(shape);
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
        Rectangle rectangle(point0);
        if (!(rectangle.getcenter() == point0 &&
                rectangle.getheight() == 1 &&
                rectangle.getwidth() == 3)) throw 1;
        rectangle.setcenter(point1);
        rectangle.setheight(3);
        rectangle.setwidth(1);
        if (!(rectangle.getcenter() == point1 &&
                rectangle.getheight() == 3 &&
                rectangle.getwidth() == 1)) throw 1;
        cout << "test rectangle: ok" << endl;
    }
    catch (...) {
        cout << "test rectangle: failed" << endl;
    }    
}

void testcircle() {
    try {
        Point point0;
        Point point1(3, 4);
        Circle circle(point0);
        if (!(circle.getcenter() == point0 &&
                circle.getradius() == 1)) throw 1;
        circle.setcenter(point1);
        circle.setradius(3);
        if (!(circle.getcenter() == point1 &&
                circle.getradius() == 3)) throw 1;
        cout << "test circle: ok" << endl;
    }
    catch (...) {
        cout << "test circle: failed" << endl;
    }    
}

void testsquare() {
    try {
        Point point0;
        Point point1(3, 4);
        Square square(point0);
        if (!(square.getcenter() == point0 &&
                square.getheight() == 1 &&
                square.getwidth() == 1)) throw 1;
        square.setcenter(point1);
        square.setheight(3);
        if (!(square.getcenter() == point1 &&
                square.getheight() == 3 &&
                square.getwidth() == 3)) throw 1;
        square.setwidth(4);
        if (!(square.getheight() == 4 &&
                square.getwidth() == 4)) throw 1;
        Rectangle * prectangle = new Square(point0);
        if (!(prectangle->getcenter() == point0 &&
                prectangle->getheight() == 1 &&
                prectangle->getwidth() == 1)) throw 1;
        prectangle->setcenter(point1);
        prectangle->setheight(3);
        if (!(prectangle->getcenter() == point1 &&
                prectangle->getheight() == 3 &&
                prectangle->getwidth() == 3)) throw 1;
        prectangle->setwidth(4);
        if (!(prectangle->getheight() == 4 &&
                prectangle->getwidth() == 4)) throw 1;
        delete prectangle;
        cout << "test square: ok" << endl;
    }
    catch (...) {
        cout << "test square: failed" << endl;
    }    
}

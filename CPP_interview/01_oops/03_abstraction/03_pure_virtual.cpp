
#include <iostream>
using namespace std;

// Abstract class (implemented using pure 
// virtual function and can't be instantiated)

class Shape {

protected:
    int height;
    int width;

public:
    void setDimesnion(int h, int w) {
        height = h;
        width = w;
    }

    virtual int calculateArea() = 0;
};

class Rectangle : public Shape {

public:
    void setDimesnion(int h, int w) {
        height = h;
        width = w;
    }

    int calculateArea() {
        return (height * width);
    }
};

class Triangle : public Shape {

public:
    void setDimesnion(int h, int w) {
        height = h;
        width = w;
    }

    int calculateArea() {
        return ((int)(height * width * 0.5));
    }
};

void print(Shape *sh) {
    cout << "Area of shape is : " << sh->calculateArea() << endl;
}

int main()
{
    Triangle T;
    Rectangle R;

    R.setDimesnion(3,4);
    int rectArea = R.calculateArea();

    T.setDimesnion(3,4);
    int triArea = T.calculateArea();

    cout << "Rect area : " << rectArea << endl << "Triangle area : " << triArea << endl;

    cout << " ****************************** " << endl;

    //Shape* shp1 = new Shape();  // -> cant instantiate abstract class
    Shape* rec1 = new Rectangle(); 
    Shape* tri1 = new Triangle();

    rec1->setDimesnion(3,4);
    tri1->setDimesnion(3,4);

    print(rec1);
    print(tri1);
}
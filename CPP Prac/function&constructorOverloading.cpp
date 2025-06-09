#include <iostream>
using namespace std;

class Rectangle {
    int width;
    int height;

public:
    // Default constructor
    Rectangle() {
        width = 0;
        height = 0;
    }

    // Constructor for square
    Rectangle(int side) {
        width = side;
        height = side;
    }

    // Constructor for rectangle
    Rectangle(int h, int w) {
        width = w;
        height = h;
    }

    // Member function to return area using internal values
    int area() {
        return width * height;
    }

    // Overloaded function to calculate area from given dimensions
    int area(int h, int w) {
        return h * w;
    }
};

int main() {
    Rectangle r1;             // 0 x 0
    Rectangle r2(5);          // 5 x 5 square
    Rectangle r3(4, 6);       // 4 x 6 rectangle

    cout << "r1 area (obj): " << r1.area() << endl;
    cout << "r2 area (obj): " << r2.area() << endl;
    cout << "r3 area (obj): " << r3.area() << endl;

    // Using overloaded area with parameters
    cout << "area(3, 7): " << r3.area(3, 7) << endl;

    return 0;
}

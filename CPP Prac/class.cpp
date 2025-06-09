#include <iostream>
using namespace std;
class Car {
  public:
    string brand;
    int speed;

    // Parameterized Constructor
    Car(string b, int s) {
        brand = b;
        speed = s;
        cout << "Constructor called for " << brand << endl;
    }

    void show() {
        cout << brand << " is going at " << speed << " km/h\n";
    }
};

int main() {
    Car c1("BMW", 120);  // constructor runs
    c1.show();
}



#include <iostream>
using namespace std;

class myClass {
public:
    void myFunction() {
        cout << "Some content in parent class." << endl;
    }
};
class myChild: public myClass {
};
class vehicle {
public:
    string brand = "Ford";
    void honk() {
        cout << "Tuut, tuut!" << endl;
    }
};
class car: public vehicle {
public:
    string model = "Mustang";
};
class MyGrandChild : public myChild, public vehicle {
};
int main() {
    car myCar;
    myCar.honk();
    cout << myCar.brand + " " + myCar.model << endl;
    MyGrandChild myObj;
    myObj.myFunction();
    myObj.honk();
    return 0;
}
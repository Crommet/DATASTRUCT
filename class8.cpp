#include <iostream>
using namespace std;

class Test1;
class Test2 {
    int x;
public:
    void set_data(int a){
        x = a;
    }
    friend void max(Test2, Test1);
    friend void min(Test2, Test1);
};
class Test1 {
    int y;
public:
    void set_data(int a){
        y = a;
    }
    friend void max(Test2, Test1);
    friend void min(Test2, Test1);
};
void max(Test2 t2, Test1 t1){
    if (t2.x > t1.y)
        cout << t2.x << " is maximum" << endl;
    else
        cout << t1.y << " is maximum" << endl;
}
void min(Test2 t2, Test1 t1){
    if (t2.x < t1.y)
        cout << t2.x << " is minimum" << endl;
    else
        cout << t1.y << " is minimum" << endl;
}
int main() {
    Test1 t1;
    Test2 t2;
    t1.set_data(10);
    t2.set_data(20);
    max(t2, t1);
    min(t2, t1);
    return 0;
}

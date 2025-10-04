#include <iostream>
using namespace std;

class MyClass {
public:
    int x;
    MyClass(int val) : x(val) { cout << "Ctor " << x << endl; }
    ~MyClass() { cout << "Dtor " << x << endl; }
};

void baz(MyClass* obj) { 
    obj->x += 5; 
    cout << "baz " << obj->x << endl; 
}

int main() {
    MyClass* a = new MyClass(10);
    baz(a);
    cout << "main " << a->x << endl;
    delete a;
}

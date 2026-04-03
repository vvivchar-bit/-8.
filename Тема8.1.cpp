#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {
        cout << "Singleton constructor" << endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void showMessage() {
        cout << "Meyers Singleton works" << endl;
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.showMessage();
    s2.showMessage();

    cout << "Address of s1: " << &s1 << endl;
    cout << "Address of s2: " << &s2 << endl;

    if (&s1 == &s2) {
        cout << "Same object" << endl;
    }

    return 0;
}

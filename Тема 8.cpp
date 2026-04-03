#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* p_instance;

    Singleton() {
        cout << "Singleton constructor" << endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance() {
        if (!p_instance) {
            p_instance = new Singleton();
        }
        return p_instance;
    }

    void showMessage() {
        cout << "This is the only instance" << endl;
    }
};

Singleton* Singleton::p_instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->showMessage();
    s2->showMessage();

    cout << "Address of s1: " << s1 << endl;
    cout << "Address of s2: " << s2 << endl;

    if (s1 == s2) {
        cout << "Same object" << endl;
    }

    delete s1;
    return 0;
}
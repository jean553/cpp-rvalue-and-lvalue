#include <iostream>

class MyClass {

public:

    MyClass() {
        std::cout << "constructor" << std::endl;
    }

    MyClass(const MyClass&) {
        std::cout << "copy" << std::endl;
    }

    MyClass(MyClass&&) {
        std::cout << "move" << std::endl;
    }

    MyClass& operator=(MyClass&&) {
        std::cout << "move operator" << std::endl;
    }
};

MyClass get() {
    MyClass a;
    return a;
}

int main() {

    MyClass a;
    a = get();

    return EXIT_SUCCESS;
}

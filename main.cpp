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

void set(MyClass&& obj) {
}

int main() {

    MyClass a;
    set(std::move(a));
    set(get());

    return EXIT_SUCCESS;
}

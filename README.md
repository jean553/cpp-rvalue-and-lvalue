# cpp-rvalue-and-lvalue

We use the following code for our examples:

```cpp
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
```

## `std::move`

`std::move` is a function template that simply converts its parameter into a `rvalue`.

## When is called the move constructor `for sure` ?

### `std::move` to create an object

`std::move` returns a rvalue, so the move constructor is called:

```cpp
MyClass a;
MyClass b = std::move(a);
```

Output:

```
constructor
move
```

### Get value from a function and assign it

NOTE: this code calls the move operator override with `assignation`,
not with variable `initialization`.

```cpp
MyClass get() {
    MyClass a;
    return a;
}

MyClass a;
a = get();
```

Output:

```
constructor
constructor
move operator
```

## When may be called the move constructor ?

In the following cases, there is no guarantee that move semantics will be used.
The compiler may simply directly set the expected content into the targetted variable,
depends if this content has to be used elsewhere or not.

### Temporary object initializer

```cpp
MyClass a = get();
```

### Use a temporary object as a function parameter

```cpp
void set(MyClass&& obj) {
}

MyClass a;
set(std::move(a));
set(get());
```

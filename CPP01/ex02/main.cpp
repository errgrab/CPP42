#include <iostream>

int main(void) {
    std::string var = "HI THIS IS BRAIN";
    std::string *ptr = &var;
    std::string &ref = var;

    std::cout << "Variable address: " << &var << std::endl;
    std::cout << "Pointer address: " << &ptr << std::endl;
    std::cout << "Reference address: " << &ref << std::endl;

    std::cout << "Variable value: " << var << std::endl;
    std::cout << "Pointer value: " << ptr << std::endl;
    std::cout << "Reference value: " << ref << std::endl;
    return 0;
}
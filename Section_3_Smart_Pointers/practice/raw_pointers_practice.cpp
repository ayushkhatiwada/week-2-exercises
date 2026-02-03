#include <iostream>

int main() {
    int x = 10;
    int* pX = &x;

    // pointer to const data cannot change the data stored at that address
    const int* const_data = &x;

    // const pointer cannot change the address it points to
    int* const const_ptr = &x;

    // const pointer to const data. Pointer and data both cannot be modified. 
    const int* const const_everything = &x;

    //

    // Using new to allocate data on the heap
    int *p = new int(10);
    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    // Deallocate object and set pointer to null
    delete p;
    p = nullptr;

    return 0;
}

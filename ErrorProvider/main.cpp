#include "Base/ClassBase.hpp"
#include <iostream>

int main()
{
    std::cout << "Creating ClassBase object..." << std::endl;
    {
        ClassBase obj(10);
        std::cout << "ClassBase object created successfully." << std::endl;
    }
    std::cout << "ClassBase object destructed." << std::endl;
    return 0;
}
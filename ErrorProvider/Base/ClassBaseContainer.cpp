#include <iostream>
#include "Base/ClassBaseContainer.hpp"
#include "Base/ClassBaseContainer.hpp"

ClassBaseContainer::ClassBaseContainer(int size)
{
    ConstructClassBaseContainer(size);
}

void ClassBaseContainer::ConstructClassBaseContainer(int size)
{
    std::cout << "Construct ClassBaseContainer" << std::endl;
    m_Buffer = new char[size];
}

ClassBaseContainer::~ClassBaseContainer()
{
    std::cout << "Deconstruct ClassbaseContainer" << std::endl;
    if (m_Buffer != nullptr)
        delete[] m_Buffer;
}

#include <iostream>
#include "Base/ClassBaseContainer.hpp"
#include "Base/ClassBaseContainer.hpp"
#include "ClassBaseContainer.hpp"

ClassBaseContainer::ClassBaseContainer(int size)
{
    ConstructClassBaseContainer(size);
}

void ClassBaseContainer::ConstructClassBaseContainer(int size)
{
    std::cout << "ClassBaseContainer Construct" << std::endl;
    m_Buffer = new char[size];
}

ClassBaseContainer::~ClassBaseContainer()
{
    DestructClassBaseContainer();
}

void ClassBaseContainer::DestructClassBaseContainer()
{
    std::cout << "ClassBaseContainer Destruct" << std::endl;
    if (m_Buffer != nullptr)
        delete[] m_Buffer;
}

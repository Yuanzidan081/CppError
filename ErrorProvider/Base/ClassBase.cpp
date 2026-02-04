#include "Base/ClassBase.hpp"
#include <iostream>
#include "ClassBase.hpp"
ClassBase::ClassBase(int size) : m_classBaseContainer(size)
{
    ConstructClassBase();
}

void ClassBase::ConstructClassBase()
{
    std::cout << "ClassBase Construct" << std::endl;
}

ClassBase::~ClassBase()
{
    DestructClassBase();
}
void ClassBase::DestructClassBase()
{
    std::cout << "ClassBase Destruct" << std::endl;
}
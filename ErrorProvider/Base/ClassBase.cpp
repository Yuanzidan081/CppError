#include "Base/ClassBase.hpp"
#include <iostream>
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
    std::cout << "ClassBase Destruct" << std::endl;
}
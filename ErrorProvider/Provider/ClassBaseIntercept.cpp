#include "Provider/IClassBaseService.hpp"
#include "Provider/ModuleServiceRegistry/ModuleServiceRegistry.hpp"
#include "Base/ClassBase.hpp"
#include <iostream>
using namespace MY;
ClassBase::ClassBase(int size) : m_classBaseContainer(size)
{
    std::cout << "ClassBaseIntercept ClassBase " << std::endl;
    auto service = GetServiceOrDefault<IClassBaseService>();
    service->Construct_ClassBaseService(this);
}

ClassBase::~ClassBase()
{
    std::cout << "ClassBaseIntercept ~ClassBase " << std::endl;
    auto service = GetServiceOrDefault<IClassBaseService>();
    service->Deconstruct_ClassBaseService(this);
}
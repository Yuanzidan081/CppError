#include "Provider/IClassBaseContainerService.hpp"
#include "Provider/ModuleServiceRegistry/ModuleServiceRegistry.hpp"
#include "Base/ClassBaseContainer.hpp"
#include <iostream>
using namespace MY;
ClassBaseContainer::ClassBaseContainer(int size)
{
    std::cout << "ClassBaseContainerIntercept ClassBaseContainer" << std::endl;
    auto service = GetServiceOrDefault<IClassBaseContainerService>();
    service->Construct_ClassBaseContainerService(this, size);
}

ClassBaseContainer::~ClassBaseContainer()
{
    std::cout << "ClassBaseContainerIntercept ~ClassBaseContainer" << std::endl;
    auto service = GetServiceOrDefault<IClassBaseContainerService>();
    service->Destruct_ClassBaseContainerService(this);
}
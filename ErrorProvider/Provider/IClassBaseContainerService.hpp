#pragma once
#include "Provider/ModuleServiceRegistry/ModuleServiceRegistry.hpp"
#include "Base/ClassBaseContainer.hpp"
namespace MY
{
    class IClassBaseContainerService
    {
    public:
        virtual ~IClassBaseContainerService() = default;
        virtual void Construct_ClassBaseContainerService(::ClassBaseContainer *self, int size) = 0;
        virtual void Deconstruct_ClassBaseContainerService(::ClassBaseContainer *self) = 0;
    };
}
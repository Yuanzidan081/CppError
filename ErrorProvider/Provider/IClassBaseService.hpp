#pragma once
#include "ModuleServiceRegistry/ModuleServiceRegistry.hpp"
#include "Base/ClassBase.hpp"
namespace MY
{
    class IClassBaseService
    {
    public:
        virtual ~IClassBaseService() = default;
        virtual void Construct_ClassBaseService(ClassBase *self) = 0;
        virtual void Destruct_ClassBaseService(ClassBase *self) = 0;
    };
}
#include "Provider/IClassBaseService.hpp"
#include "Base/ClassBase.hpp"
#include <iostream>
namespace MY
{
    class ClassBaseProvider : public IClassBaseService
    {
    public:
        virtual void Construct_ClassBaseService(::ClassBase *self) override
        {
            std::cout << "ClassBaseProvider Construct_ClassBaseService" << std::endl;
            self->ConstructClassBase();
        }
        virtual void Deconstruct_ClassBaseService(::ClassBase *self) override
        {
            std::cout << "ClassBaseProvider Deconstruct_ClassBaseService" << std::endl;
            self->~ClassBase();
        }
    };

    AUTO_REGISTER_SERVICE(IClassBaseService, ClassBaseProvider)
}
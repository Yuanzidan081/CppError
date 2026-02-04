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
        virtual void Destruct_ClassBaseService(::ClassBase *self) override
        {
            std::cout << "ClassBaseProvider Destruct_ClassBaseService" << std::endl;
            self->DestructClassBase();
        }
    };

    AUTO_REGISTER_SERVICE(IClassBaseService, ClassBaseProvider)
}
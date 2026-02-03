#include "Provider/IClassBaseContainerService.hpp"
#include "Base/ClassBaseContainer.hpp"
#include <iostream>
namespace MY
{
    class ClassBaseContainerProvider : public IClassBaseContainerService
    {
    public:
        virtual void Construct_ClassBaseContainerService(::ClassBaseContainer *self, int size) override
        {
            std::cout << "ClassBaseContainerProvider Construct_ClassBaseContainerService" << std::endl;
            self->ConstructClassBaseContainer(size);
        }
        virtual void Deconstruct_ClassBaseContainerService(::ClassBaseContainer *self) override
        {
            std::cout << "ClassBaseContainerProvider Deconstruct_ClassBaseContainerService" << std::endl;
            self->~ClassBaseContainer();
        }
    };

    AUTO_REGISTER_SERVICE(IClassBaseContainerService, ClassBaseContainerProvider)
}
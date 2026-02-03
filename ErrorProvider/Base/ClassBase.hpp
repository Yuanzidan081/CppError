#pragma once
#include "Base/ClassBaseContainer.hpp"
namespace MY
{
    class ClassbaseProvider;
}
class ClassBase
{
    friend class MY::ClassbaseProvider;

public:
    ClassBase(int size);
    void ConstructClassBase();
    ~ClassBase();

private:
    ClassBaseContainer m_classBaseContainer;
};
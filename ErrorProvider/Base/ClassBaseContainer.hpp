#pragma once
namespace MY
{
    class ClassBaseContainerProvider;
}
class ClassBaseContainer
{
    friend class MY::ClassBaseContainerProvider;

public:
    ClassBaseContainer(int size);
    void ConstructClassBaseContainer(int size);
    ~ClassBaseContainer();

    void DestructClassBaseContainer();

private:
    char *m_Buffer;
};
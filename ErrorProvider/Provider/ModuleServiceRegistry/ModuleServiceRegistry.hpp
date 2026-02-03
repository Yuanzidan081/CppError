#pragma once
#include <memory>

#if defined(_MSC_VER) // MSVC
#define CURRENT_FUNCTION_NAME __FUNCSIG__
#elif defined(__GNUC__) || defined(__clang__) // GCC / Clang
#define CURRENT_FUNCTION_NAME __PRETTY_FUNCTION__
#else
#define CURRENT_FUNCTION_NAME __FUNCTIONW__
#endif
namespace MY
{
#ifndef MODULE_SERVICE_API
#define MODULE_SERVICE_API
#endif
    extern "C"
    {
        MODULE_SERVICE_API void *GetGlobalServiceByTypeID(const char *typeID);
        MODULE_SERVICE_API void RegisterGlobalServiceByTypeID(const char *typeID, void *service);
        MODULE_SERVICE_API void UnRegisterGlobalServiceByTypeID(const char *typeID);
    }

    template <typename T>
    struct TypeID
    {
        static const char *GetID()
        {
            return CURRENT_FUNCTION_NAME;
        }
    };
    template <typename TInterface>
    struct ServiceHolder
    {
        static std::shared_ptr<TInterface> instance;
        static void EnsureInitialized()
        {
            if (!instance)
            {
                InitService();
            }
        }
        static void InitService()
        {
            void *globalService = GetGlobalServiceByTypeID(TypeID<TInterface>::GetID());
            if (globalService)
            {
                instance = *static_cast<std::shared_ptr<TInterface> *>(globalService);
            }
        }

        static bool IsServiceRegistered()
        {
            return instance != nullptr;
        }
    };
    template <typename TInterface, typename TImplementation>
    void RegisterService()
    {
        auto service_Impl = std::make_shared<TImplementation>();
        ServiceHolder<TInterface>::instance = service_Impl;
        auto *globalPtr = new std::shared_ptr<TInterface>(service_Impl);
        RegisterGlobalServiceByTypeID(TypeID<TInterface>::GetID(), globalPtr);
    }

    template <typename TInterface>
    std::shared_ptr<TInterface> GetService()
    {
        ServiceHolder<TInterface>::EnsureInitialized();
        return ServiceHolder<TInterface>::instance;
    }
    template <typename TInterface>
    std::shared_ptr<TInterface> GetServiceOrDefault()
    {
        ServiceHolder<TInterface>::EnsureInitialized();
        return ServiceHolder<TInterface>::instance;
    }
    template <typename TInterface>
    bool IsRegistered()
    {
        ServiceHolder<TInterface>::EnsureInitialized();
        return ServiceHolder<TInterface>::instance != nullptr;
    }
    template <typename TInterface>
    void UnRegister()
    {
        ServiceHolder<TInterface>::EnsureInitialized();
        UnRegisterGlobalServiceByTypeID(TypeID<TInterface>::GetID());
        ServiceHolder<TInterface>::instance = nullptr;
    }
}

namespace MY
{
    namespace Internal
    {
        template <typename TInterface, typename TImplementation>
        struct ServiceRegistrar
        {
            ServiceRegistrar()
            {
                MY::RegisterService<TInterface, TImplementation>();
            }
        };
    }
}
#define AUTO_REGISTER_SERVICE(Interface, Implementation)                         \
    namespace                                                                    \
    {                                                                            \
        static const ::MY::Internal::ServiceRegistrar<Interface, Implementation> \
            auto_registrar_##Interface##_##Implementation;                       \
    }

template <typename TInterface>
std::shared_ptr<TInterface> MY::ServiceHolder<TInterface>::instance = nullptr;
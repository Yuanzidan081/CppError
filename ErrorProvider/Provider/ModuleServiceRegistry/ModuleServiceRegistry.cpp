#include "ModuleServiceRegistry.hpp"
#include <unordered_map>
#include <string>
#include <mutex>

namespace
{
    std::unordered_map<std::string, void *> globalServices;
    std::mutex registryMutex;
}

extern "C"
{
    MODULE_SERVICE_API void *GetGlobalServiceByTypeID(const char *typeID)
    {
        if (!typeID)
            return nullptr;
        std::lock_guard<std::mutex> lock(registryMutex);
        auto it = globalServices.find(typeID);
        return (it != globalServices.end()) ? it->second : nullptr;
    }

    MODULE_SERVICE_API void RegisterGlobalServiceByTypeID(const char *typeID, void *service)
    {
        if (!typeID || !service)
            return;
        std::lock_guard<std::mutex> lock(registryMutex);
        globalServices[typeID] = service;
    }

    MODULE_SERVICE_API void UnRegisterGlobalServiceByTypeID(const char *typeID)
    {
        if (!typeID)
            return;
        std::lock_guard<std::mutex> lock(registryMutex);
        auto it = globalServices.find(typeID);
        if (it != globalServices.end())
        {
            delete static_cast<std::shared_ptr<void> *>(it->second); // 假设service是指向shared_ptr的指针
            globalServices.erase(it);
        }
    }
}
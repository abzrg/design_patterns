#include "Factory.hpp"

// Initialize our static
GameObjectFactory::CallBackMap GameObjectFactory::s_objects;

void GameObjectFactory::RegisterObject(std::string const &type, CreateObjectCallback cb)
{
    s_objects[type] = cb;
}

// Unregister a user-created object type
// Remove from our map
void GameObjectFactory::UnregisterObject(std::string const &type)
{
    s_objects.erase(type);
}

// Our previous factory method
std::shared_ptr<IGameObject> GameObjectFactory::CreateSingleObject(std::string const &type)
{
    auto it = s_objects.find(type);

    if (it != s_objects.end())
    {
        // Call the callback function
        return (it->second)();
    }

    // TODO: err-handling here
    return nullptr;
}

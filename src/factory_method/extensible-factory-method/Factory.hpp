#pragma once

#include <map> // IWYU pragma: keep
#include <memory>
#include <string>

// Forward declarations
class IGameObject;

// One change is that I have removed our "enum class"
// This is because during run-time I want to be able to create different types
class GameObjectFactory
{
private:
    // Callback function to creating an object
    // typedef IGameObject *(*CreateObjectCallback)();
    using CreateObjectCallback = std::shared_ptr<IGameObject> (*)();

public:
    // Register a new user created object type
    // Again, we also have to pass in how to "create" an object
    static void RegisterObject(std::string const &type, CreateObjectCallback cb);

    // Unregister a user created object type
    // Remove from our map
    static void UnregisterObject(std::string const &type);

    // Our previous "Factory Method"
    static std::shared_ptr<IGameObject> CreateSingleObject(std::string const &type);

private:
    // Convinience typedef
    // typedef std::map<std::string, CreateObjectCallback> CallBackMap;
    using CallBackMap = std::map<std::string, CreateObjectCallback>;

    // Map of all the different obejcts that we can create
    static CallBackMap s_objects;
};

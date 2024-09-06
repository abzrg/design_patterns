#include <iostream>
#include <memory>

class IGameObject
{
public:
    IGameObject() = default;
    IGameObject(IGameObject const &) = default;
    IGameObject(IGameObject &&) = delete;
    IGameObject &operator=(IGameObject const &) = default;
    IGameObject &operator=(IGameObject &&) = delete;

    virtual ~IGameObject() = default;

    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Plane : public IGameObject
{
public:
    Plane()
    {
        std::cout << "Plane constructed.\n";
    };

    void Update() override {}
    void Render() override {}
};

class Boat : public IGameObject
{
public:
    Boat()
    {
        std::cout << "Boat constructed.\n";
    };

    void Update() override {}
    void Render() override {}
};

enum class ObjectType { PLANE, BOAT };

std::shared_ptr<IGameObject> MakeGameObjectFactory(ObjectType type)
{
    if (type == ObjectType::PLANE)
    {
        return std::make_shared<Plane>();
    }
    else if (type == ObjectType::BOAT)
    {
        return std::make_shared<Boat>();
    }
    return nullptr;
}

int main()
{
    std::shared_ptr<IGameObject> myObject = MakeGameObjectFactory(ObjectType::PLANE);
    std::shared_ptr<IGameObject> myAnotherObject = MakeGameObjectFactory(ObjectType::BOAT);

    return 0;
}

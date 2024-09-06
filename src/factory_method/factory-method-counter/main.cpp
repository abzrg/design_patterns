#include <iostream>

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

class FactoryGameObject
{
public:
    FactoryGameObject() = delete;
    FactoryGameObject(FactoryGameObject const &) = delete;
    FactoryGameObject(FactoryGameObject &&) = delete;
    FactoryGameObject &operator=(FactoryGameObject const &) = delete;
    FactoryGameObject &operator=(FactoryGameObject &&) = delete;
    ~FactoryGameObject() = delete;

    static void PrintCounts()
    {
        std::cout << "Number of Boats:  " << s_boatCount << std::endl;
        std::cout << "Number of Planes: " << s_planeCount << std::endl;
    }

    static std::shared_ptr<IGameObject> CreateObject(ObjectType type)
    {
        if (type == ObjectType::PLANE)
        {
            s_planeCount++;
            return std::make_shared<Plane>();
        }
        else if (type == ObjectType::BOAT)
        {
            s_boatCount++;
            return std::make_shared<Boat>();
        }

        return nullptr;
    }

private:
    static unsigned int s_planeCount;
    static unsigned int s_boatCount;
};

unsigned int FactoryGameObject::s_planeCount = 0;
unsigned int FactoryGameObject::s_boatCount = 0;

int main()
{
    std::shared_ptr<IGameObject> myPlane1 = FactoryGameObject::CreateObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> myPlane2 = FactoryGameObject::CreateObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> myBoat1 = FactoryGameObject::CreateObject(ObjectType::BOAT);
    std::shared_ptr<IGameObject> myBoat2 = FactoryGameObject::CreateObject(ObjectType::BOAT);
    FactoryGameObject::PrintCounts();

    return 0;
}

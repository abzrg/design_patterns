#pragma once

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
    // Ensure derived classes call
    // the correct destructor (i.e., top of the chain)
    virtual ~IGameObject() = default;

    // Pure virtual functions that must be
    // implmented by derived class
    virtual void ObjectPlayDefaultAnimation() = 0;
    virtual void ObjectMoveInGame() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Plane : public IGameObject
{
public:
    Plane(int /*x*/, int /*y*/)
    {
        s_objectsCreated++;
        std::cout << "Plane Created." << std::endl;
    }

    // Pure virtual functions that must be
    // implmented by derived class
    void ObjectPlayDefaultAnimation() override { /* ... */ }
    void ObjectMoveInGame() override { /* ... */ }
    void Update() override { /* ... */ }
    void Render() override { /* ... */ }

    static std::shared_ptr<IGameObject> Create() { return std::make_shared<Plane>(0, 0); }

private:
    static unsigned int s_objectsCreated;
};

class Boat : public IGameObject
{
public:
    Boat(int /*x*/, int /*y*/)
    {
        s_objectsCreated++;
        std::cout << "Boat Created." << std::endl;
    }

    // Pure virtual functions that must be
    // implmented by derived class
    void ObjectPlayDefaultAnimation() override { /* ... */ }
    void ObjectMoveInGame() override { /* ... */ }
    void Update() override { /* ... */ }
    void Render() override { /* ... */ }

    static std::shared_ptr<IGameObject> Create() { return std::make_shared<Boat>(0, 0); }

private:
    static unsigned int s_objectsCreated;
};

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "Factory.hpp"
#include "GameObject.hpp"

// For fun create a new type
// Sort of giving the user the ability to implements its own "plugin"/"extension"
class Ant : public IGameObject
{
public:
    Ant(int m_x, int m_y) : x{m_x}, y{m_y}
    {
        s_ObjectsCreated++;
        std::cout << "Ant Created." << std::endl;
    }

    void ObjectPlayDefaultAnimation() override { /* ... */ }
    void ObjectMoveInGame() override { /* ... */ }
    void Update() override { /* ... */ }
    void Render() override { /* ... */ }

    static std::shared_ptr<IGameObject> Create() { return std::make_shared<Ant>(0, 0); }

private:
    static unsigned int s_ObjectsCreated;
    int x{};
    int y{};
};

unsigned int Ant::s_ObjectsCreated = 0;

int main()
{
    // Register different types
    GameObjectFactory::RegisterObject("plane", Plane::Create);
    GameObjectFactory::RegisterObject("boat", Boat::Create);
    GameObjectFactory::RegisterObject("ant", Ant::Create);

    std::vector<std::shared_ptr<IGameObject>> gameObjectCollection;

    // Add the correct object to our collection based on a .txt file
    std::string line;
    std::ifstream myFile("level1.txt");

    if (myFile.is_open())
    {
        while (std::getline(myFile, line))
        {
            // For each line that is read in, then create a game object for that type
            std::shared_ptr<IGameObject> object = GameObjectFactory::CreateSingleObject(line);
            // Add the object to the collection
            gameObjectCollection.push_back(object);
        }
    }
    else
    {
        std::cerr << "Could not open the file." << std::endl;
        return 0;
    }

    // Run our game...
    while (true)
    {
        for (auto &e : gameObjectCollection)
        {
            e->Update();
            e->Render();
        }
    }

    return 0;
}

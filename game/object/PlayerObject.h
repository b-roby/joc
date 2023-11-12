#ifndef UNTITLED_PLAYEROBJECT_H
#define UNTITLED_PLAYEROBJECT_H

#include "GameObject.h"
#include <random>

class PlayerObject : public GameObject {
    using GameObject::GameObject;

public:

    void update();

    bool canShoot = false;

private:

    std::uniform_int_distribution<> spawnDistance{-10, 10};
    std::uniform_int_distribution<> engineParticle{0, 4};

    void spawnEngineParticles();

    int speed = 5;
    int health = 10;

    int particleDelay = 50;
    int particleSize = 15;

    int shootingPlaceholder = 0;
    int particleSpawningPlaceholder = 0;

};


#endif //UNTITLED_PLAYEROBJECT_H

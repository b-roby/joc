#ifndef UNTITLED_ENEMYOBJECT_H
#define UNTITLED_ENEMYOBJECT_H

#include "GameObject.h"

class Game;

class EnemyObject : public GameObject {

    using GameObject::GameObject;

public:

    void update();

    int health = 1;
    int shootingPlaceholder = 0;

};


#endif

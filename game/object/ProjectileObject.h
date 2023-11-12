#ifndef UNTITLED_PROJECTILEOBJECT_H
#define UNTITLED_PROJECTILEOBJECT_H


#include "GameObject.h"

class ProjectileObject : public GameObject {

    using GameObject::GameObject;

public:

    GameObject* shooter = nullptr;

    bool isCollidingWithShooter(GameObject* shooter);
    void update();

};


#endif //UNTITLED_PROJECTILEOBJECT_H

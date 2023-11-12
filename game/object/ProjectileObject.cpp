#include "ProjectileObject.h"
#include "../Game.h"


void ProjectileObject::update() {
    if(position.y < 0) {
        game->removeGameObject(this);
        return;
    }

    position.y -= 5;
}

bool ProjectileObject::isCollidingWithShooter(GameObject* shooter) {
    if(this->shooter == shooter) return true;
    return false;
}

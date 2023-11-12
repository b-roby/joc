#include <iostream>
#include "EnemyObject.h"
#include "../Game.h"


void EnemyObject::update() {
    if(game->getTime().hasPassed(shootingPlaceholder, 1000, true))
        game->spawnProjectile(this, position.x, position.y);


}
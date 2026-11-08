#pragma once
#include "ECS.h"


class MovementSystem : public System
{
public:
    MovementSystem()
    {
        // TODO :
        // check only ones with required component like transform physics etc.(i.e. RequiredComponent<T>())

    }

    void Update(float deltaTime)
    {
        // TODO:
        // loop over all the entities and just get the transform Component and add the physics and update the transform

    }
};
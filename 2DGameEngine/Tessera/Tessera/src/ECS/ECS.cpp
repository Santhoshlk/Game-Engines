#include "ECS.h"

int Entity::GetEntityId() const
{
    return  id;
}

Entity::~Entity()
{
    id = -1;
}

void System::PushEntity(const Entity& e)
{
}

void System::PopEntity(const Entity& e)
{
}

Signature System::GetSignature() const
{
    return SystemSignature;
}

std::vector<Entity>& System::GetSysteemEntities() 
{
    return Entities;
}

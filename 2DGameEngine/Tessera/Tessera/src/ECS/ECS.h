#pragma once
#include <bitset>
#include <vector>

constexpr unsigned int Max_Components = 32;

typedef std::bitset<Max_Components> Signature;

class Entity
{
    int id;
public:
    Entity(int eid) : id(eid) {}

    int GetEntityId() const;


    ~Entity();

};



class Component
{
    
};

class System
{
private:
    Signature SystemSignature;
    std::vector<Entity> Entities;

public:
    System(const Signature& signature) : SystemSignature(signature) {}
    System() = default;

    void PushEntity(const Entity& e);
    void PopEntity(const Entity& e);
    Signature GetSignature() const;
    std::vector<Entity>& GetSysteemEntities();

    ~System() = default;

    
};

class Registry
{
    
};
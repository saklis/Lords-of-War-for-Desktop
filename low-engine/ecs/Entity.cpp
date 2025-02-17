#include "Entity.h"
#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"

// initialize default value to static field
uint32_t LowEngine::ECS::Entity::_nextId = 0;

LowEngine::ECS::Entity::Entity() {
    this->Id = _nextId++; // assign current value to this instance and then increment
}

void LowEngine::ECS::Entity::InitAsDefault() {
    this->Name = "Default";
    this->Active = true;
}

void LowEngine::ECS::Entity::Activate(const std::string& name) {
    this->Name = name + "_" + std::to_string(this->Id);
    this->Active = true;
}

void LowEngine::ECS::Entity::AddComponent(const std::string& typeName, uint32_t componentId) {
    this->_components[typeName].push_back(componentId);
}

uint32_t LowEngine::ECS::Entity::GetComponent(const std::string& typeName) {
    return this->_components[typeName][0];
}

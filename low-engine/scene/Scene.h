#pragma once

#include <string>

#include "memory/Memory.h"

namespace LowEngine {
    class Scene {
    public:
        bool Active = false;
        std::string Name;

        Scene() = default;
        explicit Scene(const std::string& name);
        void InitAsDefault();

        void Update(float deltaTime);
        void Draw(sf::RenderWindow& window);

        uint32_t AddEntity(const std::string& name = "Entity");

        template<typename T, typename ... Args>
        T* AddComponent(uint32_t entityId, Args&&... args) {
            return _memory.CreateComponent<T>(entityId, std::forward<Args>(args)...);
        }

        template<typename T>
        T* GetComponent(uint32_t entityId) {
            return _memory.GetComponent<T>(entityId);
        }

        void Destroy();

    protected:
        Memory::Memory _memory;
    };
}

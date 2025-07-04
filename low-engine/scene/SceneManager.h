#pragma once

#include <string>
#include <vector>
#include <cstdint>

#include "scene/Scene.h"

namespace LowEngine {
    class Game;

    /**
     * @brief Scene Manager keeps a list of all existing scenes, alloes creation of new onse and switching between them.
     */
    class SceneManager {
    public:
        SceneManager();

        ~SceneManager() = default;

        /**
         * @brief Create new scene.
         *
         * New scene will not be automatically set as active scene.
         * @param name Name of the new scene.
         * @return Pointer to the new scene. Returns nullptr in case of error.
         */
        Scene* CreateScene(const std::string& name);

        /**
         * @brief Create a deep copy of current scene.
         * @param nameSufix Suffix that will be added to the scene's Name.
         * @return Id of the new scene.
         */
        size_t CreateCopySceneFromCurrent(const std::string& nameSufix);

        /**
         * @brief Set scene with provided Id as 'current'
         * @param index Id of the scene.
         * @return True if current scene was changed. Returns false in case of error.
         */
        bool SelectScene(size_t index);

        /**
         * @brief Set scene with provided name as 'current'
         * @param name Name of the scene.
         * @return True if current scene was changed. Returns false in case of error.
         */
        bool SelectScene(const std::string& name);

        /**
         * @brief Set refered scene as 'current'.
         * @param scene Reference to the scene.
         * @return True if current scene was changed. Returns false in case of error.
         */
        bool SelectScene(const LowEngine::Scene& scene);

        /**
         * @brief Retrieve pointer to scene that is marked as 'current'.
         * @return Pointer to scene. Returns nullptr in case of error.
         */
        Scene* GetCurrentScene();

        /**
         * @brief Retrieve const reference to the scene that is marked as 'current'.
         *
         *
         * @return
         */
        const Scene& GetCurrentScene() const;

        /**
         * @brief Destroy current scene.
         *
         * Scene lower on the "stack" will be marked as current.
         */
        void DestroyCurrentScene();

        /**
         * @brief Destroy all scenes.
         */
        void DestroyAll();

    protected:
        std::vector<std::unique_ptr<Scene>> _scenes;
        size_t _currentSceneIndex;
    };
}

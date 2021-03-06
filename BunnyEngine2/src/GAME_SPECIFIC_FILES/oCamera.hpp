#pragma once

#include <BaseStage.hpp>
#include <Utilities/TimerManager.hpp>
#include <WIP/Keyboard.hpp>

#include <GAME_SPECIFIC_FILES/Objects.hpp>
namespace
{


}

namespace Stage
{

    //!  The game's Camera class 
    /*!
    This class is in charge of controling the camera in our game.
    */
    class oCamera
    {
    public:
        oCamera(BE::Actor* rhs = nullptr);
        ~oCamera() = default;


        void Update(float dt_);
        void setActor(BE::Actor* rhs_);
        void setPosition(glm::vec2 pos_);
        void setCameraShake(int time_, glm::vec2 strength_, int maxValue_);
        void cameraShake(int x_, int y_);
    private:
        BE::Actor* cameraActor;
        glm::vec2 positionOffset;
        glm::vec2 currentPosition;
        glm::vec2 moveToPosition;

        int shakeTime;
        glm::vec2 shakeStrength;
        int shakeMaxValue;
    };
}

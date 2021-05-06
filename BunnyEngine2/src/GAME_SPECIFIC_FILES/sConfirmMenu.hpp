#pragma once

#include <BunnyEngine.hpp>
#include <BaseStage.hpp>
#include <Utilities/TimerManager.hpp>

namespace Stage
{
    //!  The sConfirmMenu class. 
    /*!
    The sConfirmMenu class is a Stage.
    It contains its own vector of Actors and its own update function.
    It is used as a popup when trying to do a destructive action (quitting game, returning to menu)
    NOTE: Currently, there is no way of knowing what the "result" of the ActionConfirm was. So that will need to be adressed
    */
    class sConfirmMenu : public BE::Stage::BaseStage
    {
    public:
        sConfirmMenu();
        ~sConfirmMenu() = default;

        BaseStage*  cpy() final
        {
            return (new sConfirmMenu());
        }

        void    start(std::string fileName_ = "") final;

        void    resume() final;
        void    pause() final;

        void    update(float dt_) final;
    protected:
        //
    private:
        //

    public:
        //
    protected:
        //
    private:
		    BE::PropManager::propNamePair* sndBackground;
        float       _elapsedTime;   /*!< [TEMPORARY] Used for testing purposes, to check if state stacking works.*/
		
    };
}
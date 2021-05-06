#pragma once

#include <BunnyEngine.hpp>
#include <BaseStage.hpp>
#include <Utilities/TimerManager.hpp>

namespace Stage
{
    //!  The sCredit class. 
    /*!
     The sCredit class is a Stage.
     It contains its own vector of Actors and its own update function.
     It is used as a popup when trying to do a destructive action (quitting game, returning to menu)
     NOTE: Currently, there is no way of knowing what the "result" of the ActionConfirm was. So that will need to be adressed
    */
    class sCredit : public BE::Stage::BaseStage
    {
    public:
		sCredit();
        ~sCredit() = default;

        BaseStage*  cpy() final
        {
            return (new sCredit());
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
        //
    };
}
#pragma once

#include <BaseStage.hpp>
#include <Utilities/TimerManager.hpp>

namespace Stage
{
    //!  The sPokemon class. 
    /*!
    The sPokemon class is a Stage.
    It contains its own vector of Actors and its own update function.
    At the moment it does not serve any purpose other than to be used to test out the engine
    */
    class sPokemon : public BE::Stage::BaseStage
    {
    public:
        sPokemon();
        ~sPokemon() override final;

        BaseStage*  cpy() final
        {
            return (new sPokemon());
        }

        void    start(std::string fileName_ = "") final;

        void    resume() final;
        void    pause() final;

        void    update(float dt_) final;
    protected:
        //
    private:
        void healthBarReduction(float dt_);

    public:
        //
    protected:
        //
    private:
        //
        BE::Actor*  _poke1;
        BE::Actor*  _poke2;
        BE::Actor*  _poke2HP;
        int       _currentPoke2HP;
        std::vector<BE::Actor*> _tmpActorVec;
        BE::Actor* _selectedActor;
        bool    btlStartPlay;
        bool    btlEndPlay;
        BE::PropManager::propNamePair* _battleStart;
        BE::PropManager::propNamePair* _battleEnd;
        BE::PropManager::propNamePair* _tackle;
        float   _cooldownTimer;
        std::vector<glm::vec4>   _hPColors;
    };
}


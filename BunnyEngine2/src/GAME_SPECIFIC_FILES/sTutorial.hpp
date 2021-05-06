#pragma once

#include <BaseStage.hpp>
#include <Utilities/TimerManager.hpp>
#include <WIP/Keyboard.hpp>
#include <GAME_SPECIFIC_FILES\LevelSetting.hpp>
#include <GAME_SPECIFIC_FILES\oPlayer.hpp>
#include <GAME_SPECIFIC_FILES\oEnemy.hpp>
#include <GAME_SPECIFIC_FILES\oPlanet.hpp>


namespace
{

}

namespace Stage
{
    //!  The sTutorial class. 
    /*!
     The sTutorial class is a Stage.
     It contains its own vector of Actors and its own update function.
     At the moment it does not serve any purpose other than to be used to test out the engine
    */
	class sTutorial : public BE::Stage::BaseStage
    {
    public:
        sTutorial();
        ~sTutorial() = default;

        BaseStage*  cpy() final
        {
            return (new sTutorial());
        }

        void    start(std::string fileName_ = "") final;

        void    resume() final;
        void    pause() final;

		float pointObj(BE::Actor * act1, BE::Actor * act2);

        void    update(float dt_) final;
		void		WinCondition(LevelSetting levelSetting);
		void    LoseCondition(LevelSetting levelSetting);

		void  ControlHelper(void); // show the control info
		void  CreateButton(float dt);

		void ShootPlayer(float dt);

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
		BE::Actor*  _player;
		BE::Actor*  _camera;
		BE::Actor*  _backStar;
		BE::Actor*  _1to3Button;
		BE::Actor*  _3to5Button;
		BE::Actor* hud;
		BE::Actor* _superstandHUD;
		BE::Actor* _FinalDestination;

		//BE::Actor* _LightHud1;
		//BE::Actor* _LightHud2;
		//BE::Actor* _LightHud3;

		Player m_player;
		
		LevelSetting LevelSetting1;
		float winTimer;
		float loseTimer;

	};


}

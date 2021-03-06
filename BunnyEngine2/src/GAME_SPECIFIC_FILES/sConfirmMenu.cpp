#include <GAME_SPECIFIC_FILES/sConfirmMenu.hpp>
#include <GAME_SPECIFIC_FILES/sLegacyMenu.hpp>
#include <GAME_SPECIFIC_FILES/inputAbstraction.hh>
#include <WIP/PropManager.hpp>
#include <WIP/Keyboard.hpp>



Stage::sConfirmMenu::sConfirmMenu()
    : BaseStage("sConfirmMenu.stg")
{
    // Setting up the core config, by default everything is set to false
    {
        _stageLoadCoreConf.drawCore = true; // We want the draw core to keep drawing whatever was present while we display the confirm action pop up
    }
}

void
Stage::sConfirmMenu::start(std::string fileName_)
{
    loadProps(fileName_);
    loadStageFile(fileName_);

	//Init Sounds
	sndBackground = BE::PropManager::instance()->lookupValue("sndBG1");

}

void
Stage::sConfirmMenu::resume()
{
}

void
Stage::sConfirmMenu::pause()
{
}

void
Stage::sConfirmMenu::update(float /*dt_*/)
{
    if (Input::isTriggered(Input::JUMP) || Input::isTriggered(Input::LEFT))
    {
			//Stop Background sound
			if (sndBackground->second->type == BE::Prop::AUDIO) {
				static_cast<BE::Prop::Audio*>(sndBackground->second)->stop();
			}
        BE::Engine::BunnyEngine::instance()->flushStages();
        BE::Engine::BunnyEngine::instance()->pushActiveStage(new sLegacyMenu);
        return;
    }
    else if (Input::isTriggered(Input::NEG_ACTION) || Input::isTriggered(Input::RIGHT) || BE::Input::Keyboard::instance()->IsTriggered(BE::KB::KEY_ESCAPE))
    {
        BE::Engine::BunnyEngine::instance()->popActiveStage();
        return;
    }
}

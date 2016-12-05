#include "ICClient.h"

#include "mcpe/client/MinecraftClient.h"

#include <stdlib.h>

ICClient ICClient::mInstance;

ICClient::ICClient()
{
	mcClient=0;
	currentLevel=0;
	clientRandom=ICRandom((unsigned int)time(0));
}
ICRandom& ICClient::getRandom()
{
	return clientRandom;
}
ICOptions& ICClient::getOptions()
{
	return icOptions;
}
UIScreenChooser* ICClient::getScreenChooser()
{
	return &chooser;
}
ICBlockEntityManager& ICClient::getBlockEntityManager()
{
	return currentICBlockEntityManager;
}
std::string ICClient::getCurrentLevelFolder()
{
	return currentLevelFolder;
}
Level* ICClient::getCurrentLevel()
{
	return currentLevel;
}
MinecraftClient* ICClient::getMinecraftClient()
{
	return mcClient;
}
void ICClient::createBlockEntityManager()
{
	currentICBlockEntityManager=ICBlockEntityManager();
}
void ICClient::setLevelFolder(std::string const&name)
{
	currentLevelFolder=name;
}
void ICClient::setCurrentLevel(Level*l)
{
	currentLevel=l;
}
void ICClient::setMinecraftClient(MinecraftClient*c)
{
	mcClient=c;
	chooser=UIScreenChooser(*c);
}

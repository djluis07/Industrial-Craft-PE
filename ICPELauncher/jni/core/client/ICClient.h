#pragma once

#include <string>

#include "blocks/blockentity/ICBlockEntityManager.h"
#include "util/ICRandom.h"
#include "client/ICOptions.h"
#include "ui/UIScreenChooser.h"

class MinecraftClient;
class Level;

class ICClient
{
protected:
	MinecraftClient*mcClient;
	Level*currentLevel;
	std::string currentLevelFolder;
	ICBlockEntityManager currentICBlockEntityManager;
	ICOptions icOptions;
	ICRandom clientRandom;
	UIScreenChooser chooser;
public:
	static ICClient mInstance;
public:
	ICClient();
	~ICClient()=default;
public:
	ICRandom& getRandom();
	ICOptions& getOptions();
	UIScreenChooser* getScreenChooser();
	ICBlockEntityManager& getBlockEntityManager();
	std::string getCurrentLevelFolder();
	Level* getCurrentLevel();
	MinecraftClient* getMinecraftClient();
public:
	void createBlockEntityManager();
	void setLevelFolder(std::string const&);
	void setCurrentLevel(Level*);
	void setMinecraftClient(MinecraftClient*);
};

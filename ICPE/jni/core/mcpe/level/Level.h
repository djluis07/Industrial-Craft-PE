#pragma once
#include <unordered_set>
#include "LevelStorage.h"
#include "ParticleType.h"
#include "../util/BlockPos.h"
#include "BlockSourceListener.h"
#include "GeneratorType.h"
#include "storage/LevelData.h"
#include "../entity/Entity.h"
#include "../client/AppPlatformListener.h"
#include "../util/Random.h"
#include "../entity/player/LocalPlayer.h"
class Player;
class Random;
class MobFactory;
class SoundPlayer;
class ChangeDimensionRequest;
class BlockSource;
class FullBlock;
class Difficulty;
class EntityDamageSource;
class LightLayer;
class LevelChunk;
class Vec3;
class AABB;
class Material;
typedef int EntityUniqueID;
class LevelListener;
class LevelEvent;
class LevelSettings;
typedef int StorageVersion;
// Size : 2996
class Level : public BlockSourceListener, public AppPlatformListener
{
public:
	//void **vtable;						// 4
	char filler1[4];						// 8
	bool isRemote;							// 12
	//std::unordered_set<Player *> players;	// 60
	char filler2[80];						// 16
	//Random random;						// 96 + (SIZE??)
	char filler3[2664];						// 96
	LevelData worldInfo;					// 2760
	char filler4[32];						// 2868
	MobFactory *mobFactory;					// 2900
	char filler5[4];						// 2904
	BlockSource *tileSource;				// 2908
	char filler6[84];						// 2912
public:
	Level(SoundPlayer &, std::unique_ptr<LevelStorage>, std::string const &, LevelSettings const &, bool);
	virtual ~Level();
	virtual void onSourceCreated(BlockSource &);
	virtual void onSourceDestroyed(BlockSource &);
	virtual void onBlockChanged(BlockSource &, BlockPos const &, FullBlock, FullBlock, int);
	virtual void addEntity(std::unique_ptr<Entity>&);
	virtual void addPlayer(std::unique_ptr<Player>);
	virtual void addGlobalEntity(std::unique_ptr<Entity>);
	virtual void onPlayerDeath(Player &, EntityDamageSource const &);
	virtual void tick();
	virtual void directTickEntities(BlockSource &);
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(Difficulty);
	virtual void runLightUpdates(BlockSource &, LightLayer const &, BlockPos const &, BlockPos const &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void removeEntity(std::unique_ptr<Entity> &, bool);
	virtual void removeEntity(Entity &, bool);
	virtual void onAppSuspended();
	void _backgroundTickSeasons();
	void _chunkDirty(BlockSource *, LevelChunk *);
	void _cleanupDisconnectedPlayers();
	void _destroyEffect(BlockPos const &, FullBlock, Vec3 const &, float);
	void _handleChangeDimensionRequests();
	void _playerChangeDimension(Player *, ChangeDimensionRequest &);
	void _removeAllPlayers();
	void _saveSomeDirtyChunks();
	void _syncTime(int);
	void _tickTemporaryPointers();
	void addListener(LevelListener &);
	void addParticle(ParticleType, Vec3 const &, Vec3 const &, int);
	void animateTick(Entity &);
	void broadcastDimensionEvent(BlockSource &, LevelEvent, Vec3 const &, int, Player *);
	void broadcastEntityEvent(Entity *, EntityEvent);
	void broadcastLevelEvent(LevelEvent, Vec3 const &, int, Player *);
	void createDimension(DimensionId);
	void destroyBlock(BlockSource &, BlockPos const &, bool);
	void destroyEffect(BlockSource &, int, int, int, Vec3 const &, float);
	void entityChangeDimension(Entity &, DimensionId);
	void explode(BlockSource &, Entity *, Vec3 const&, float, bool);
	void extinguishFire(BlockSource &, int, int, int, signed char);
	void findPath(Entity &, Entity &, float, bool, bool, bool, bool);
	void findPath(Entity &, int, int, int, float, bool, bool, bool, bool);
	void forceRemoveEntity(Entity &);
	void getAdventureSettings();
	void getCurrentTick();
	void getDefaultSpawn();
	int getDifficulty()const;
	void getDimension(DimensionId);
	void getEntity(EntityUniqueID, bool);
	void getGlobalEntities();
	void getHitResult();
	LevelData* getLevelData();
	void getLightsToUpdate();
	LocalPlayer *getLocalPlayer() const ;
	void getMob(EntityUniqueID);
	void getMobSpawner();
	void getNearestAttackablePlayer(Entity &, float);
	void getNearestAttackablePlayer(float, float, float, float);
	void getNearestPlayer(Entity &, float);
	void getNearestPlayer(float, float, float, float);
	void getNetEventCallback();
	void getNewUniqueID();
	void getNextPlayer(EntityUniqueID const &, bool);
	void getNumRemotePlayers();
	void getPacketSender();
	void getPlayer(EntityUniqueID);
	void getPlayer(std::string const &);
	void getPlayerList();
	void getPlayerNames();
	void getPlayers();
	void getPortalForcer();
	void getPrevPlayer(EntityUniqueID const &, bool);
	void getRandom();
	void getRandomPlayer();
	void getSeaLevel();
	long getSeed();
	void getSharedSpawnPos();
	void getSpecialMultiplier(DimensionId);
	void getTearingDown();
	int getTime() const;
	void setTime(int);
	void getVillages();
	void handleLevelEvent(LevelEvent, Vec3 const &, int);
	void hasLevelStorage();
	void isClientSide();
	void isDayCycleActive();
	bool isNightMode()const;
	void isUpdatingLights();
	void loadPlayer(std::unique_ptr<Player>);
	void mayInteract(Player &, int, int, int);
	void onChunkDiscarded(LevelChunk &);
	void onChunkLoaded(LevelChunk &);
	void playSound(Entity *, std::string const &, float, float);
	void playSound(Vec3 const &, std::string const &, float, float);
	void potionSplash(Vec3 const &, int, bool);
	void removeListener(LevelListener &);
	void saveBiomeData();
	void saveDirtyChunks();
	void saveGameData();
	void saveLevelData();
	void savePlayers();
	void setDayCycleActive(bool);
	void setDefaultSpawn(BlockPos const &);
	void setIsClientSide(bool);
	void setNightMode(bool);
	void setSpawnSettings(bool, bool);
	void setStopTime(int);
	void tickEntities();
	void updateLights();
	LevelStorage* getLevelStorage();
	void upgradeStorageVersion(StorageVersion);
};

#include "Log.h"

#include <stdio.h>
#include <sys/stat.h>

std::ofstream Log::logstream(Log::init());

void Log::e(std::string const&msg)
{
	logstream<<"E-"<<msg<<std::endl;
}
void Log::p(std::string const&msg)
{
	logstream<<"P-"<<msg<<std::endl;
}
void Log::w(std::string const&msg)
{
	logstream<<"W-"<<msg<<std::endl;
}
std::string Log::getLocalPath()
{
	if(access("/mnt/sdcard/games/com.mojang"))
		return "/mnt/sdcard";
	else if(access("/mnt/external_sd/games/com.mojang"))
		return "/mnt/external_sd";
	else if(access("/storage/sdcard/games/com.mojang"))
		return "/storage/sdcard";
	else if(access("/storage/sdcard0/games/com.mojang"))
		return "/storage/sdcard0";
	else if(access("/storage/sdcard1/games/com.mojang"))
		return "/storage/sdcard1";
	else if(access("/storage/emulated/0/games/com.mojang"))
		return "/storage/emulated/0";
	else if(access("/storage/emulated/1/games/com.mojang"))
		return "/storage/emulated/1";
	else if(access("/storage/emulated/legacy/games/com.mojang"))
		return "/storage/emulated/legacy";
	else if(access("/sdcard/games/com.mojang"))
		return "/sdcard";
	return "/sdcard";
}
std::string Log::init()
{
	mkdir(((std::string)getLocalPath()+"/games/com.mojang/ICPE/").c_str(),0);
	return std::string(getLocalPath()+"/games/com.mojang/ICPE/icpe_log.txt");
}
bool Log::access(std::string const& path)
{
	std::ofstream ifs(path+"/minecraftpe/options.txt",std::ios::app);
	return ifs.is_open();
}

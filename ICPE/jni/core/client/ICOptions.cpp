#include "ICOptions.h"

#include <vector>

ICOptions::ICOptions()
{
	/*MCADataBase<bool>::DataItem dataUseLog("use_log",1);
	MCADataBase<bool>::DataItem dataReplaceLastLog("replace_last_log",0);
	MCADataBase<bool>::DataItem dataEnabled("ic_enabled",1);
	MCADataBase<bool>::DataItem dataElectricityHurt("electricity_hurt",1);
	std::vector<MCADataBase<bool>::DataItem> dataList;
	dataList.push_back(dataUseLog);
	dataList.push_back(dataReplaceLastLog);
	dataList.push_back(dataEnabled);
	dataList.push_back(dataElectricityHurt);
	dataBase=MCADataBase<bool>("/sdcard/games/com.mojang/minecraftpe/ICOptions.txt",dataList);
	
	useLog=(bool)dataBase.getData("use_log");
	replaceLastLog=(bool)dataBase.getData("replace_last_log");
	icEnabled=(bool)dataBase.getData("ic_enabled");
	electricityHurt=(bool)dataBase.getData("electricity_hurt");
*/}
bool ICOptions::getUseLog()const
{
	return useLog;
}
bool ICOptions::getReplaceLastLog()const
{
	return replaceLastLog;
}
bool ICOptions::getICEnabled()const
{
	return icEnabled;
}
bool ICOptions::getElectricityHurt()const
{
	return electricityHurt;
}
void ICOptions::setUseLog(bool b)
{
	useLog=b;
	//dataBase.setData("use_log",(short)b);
}
void ICOptions::setReplaceLastLog(bool b)
{
	replaceLastLog=b;
	//dataBase.setData("replace_last_log",(short)b);
}
void ICOptions::setICEnabled(bool b)
{
	icEnabled=b;
	//dataBase.setData("ic_enabled",(short)b);
}
void ICOptions::setElectricityHurt(bool b)
{
	icEnabled=b;
	//dataBase.setData("electricity_hurt",(short)b);
}

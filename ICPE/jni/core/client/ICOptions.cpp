#include "ICOptions.h"

#include <vector>

ICOptions::ICOptions()
{
	
}
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

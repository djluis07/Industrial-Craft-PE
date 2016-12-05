#pragma once

#include "util/MCADataBase.h"

class ICOptions
{
private:
	//MCADataBase<bool> dataBase;
	bool useLog;
	bool replaceLastLog;
	bool icEnabled;
	bool electricityHurt;
public:
	ICOptions();
	~ICOptions()=default;
public:
	bool getUseLog()const;
	bool getReplaceLastLog()const;
	bool getICEnabled()const;
	bool getElectricityHurt()const;
	bool getMachineExplodeable()const;
public:
	void setUseLog(bool);
	void setReplaceLastLog(bool);
	void setICEnabled(bool);
	void setElectricityHurt(bool);
	void setMachineExplodeable(bool);
};

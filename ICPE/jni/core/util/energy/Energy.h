#pragma once

class BlockPos;
class BlockSource;

class Energy
{
private:
	long energy;
	int voltage;
public:
	Energy()=default;
	Energy(long,int);
	~Energy()=default;
public:
	void setVoltage(int);
	void setEnergy(long);
	void addEnergy(long);
	void costEnergy(long);
	long getEnergy()const;
	int getVoltage()const;
public:
	void spread(BlockSource&,BlockPos const&);
};

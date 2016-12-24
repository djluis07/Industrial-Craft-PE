#pragma once

class BlockSource;
class BlockPos;
class Random;
class FullBlock;

namespace IC
{
class Feature
{
public:
	Feature()=default;
	~Feature()=default;
public:
	virtual bool place(BlockSource&,BlockPos const&,Random&)const=0;
public:
	void setBlock(BlockSource&,BlockPos const&,FullBlock const&)const;
	void setBlock(BlockSource&,int,int,int,FullBlock const&)const;
};
}

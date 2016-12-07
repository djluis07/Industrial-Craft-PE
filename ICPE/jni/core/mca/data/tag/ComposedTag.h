#pragma once

#include <string>

#include "ListTag.h"

namespace mca
{
class ComposedTag
{
public:
	friend class DatabaseWriter;
	friend class DatabaseReader;
protected:
	mca::ListTag<float> floatList;
	mca::ListTag<int> intList;
	mca::ListTag<std::string> strList;
	mca::ListTag<bool> boolList;
	mca::ListTag<double> doubleList;
	mca::ListTag<char> charList;
	mca::ListTag<long> longList;
	mca::ListTag<unsigned char> ucharList;
	mca::ListTag<short> shortList;
	mca::ListTag<unsigned int> uintList;
	mca::ListTag<unsigned short> ushortList;
	mca::ListTag<unsigned long> ulongList;
	std::string key;
public:
	ComposedTag(){};
	ComposedTag(std::string const&le)
	{
		key=le;
	}
	~ComposedTag()
	{
		floatList.clear();
		intList.clear();
		strList.clear();
		boolList.clear();
		doubleList.clear();
		charList.clear();
		longList.clear();
		ucharList.clear();
		shortList.clear();
		uintList.clear();
		ushortList.clear();
		ulongList.clear();
	}
public:
	void setKey(std::string const& le)
	{
		key=le;
	}
	std::string const getKey()const
	{
		return key;
	}
	void addInt(std::string const&key,int t)
	{
		intList.addElement({key,t});
	}
	void addFloat(std::string const&key,float t)
	{
		floatList.addElement({key,t});
	}
	void addUint(std::string const&key,unsigned int t)
	{
		uintList.addElement({key,t});
	}
	void addChar(std::string const&key,char t)
	{
		charList.addElement({key,t});
	}
	void addUchar(std::string const&key,unsigned char t)
	{
		ucharList.addElement({key,t});
	}
	void addShort(std::string const&key,short t)
	{
		shortList.addElement({key,t});
	}
	void addUshort(std::string const&key,unsigned short t)
	{
		ushortList.addElement({key,t});
	}
	void addLong(std::string const&key,long t)
	{
		longList.addElement({key,t});
	}
	void addUlong(std::string const&key,unsigned long t)
	{
		ulongList.addElement({key,t});
	}
	void addBool(std::string const&key,bool t)
	{
		boolList.addElement({key,t});
	}
	void addString(std::string const&key,std::string t)
	{
		strList.addElement({key,t});
	}
	void addDouble(std::string const&key,double t)
	{
		doubleList.addElement({key,t});
	}
public:
	mca::Tag<float>& getFloatTag(std::string const&key)
	{
		return floatList.read(key);
	}
	mca::Tag<double>& getDoubleTag(std::string const&key)
	{
		return doubleList.read(key);
	}
	mca::Tag<int>& getIntTag(std::string const&key)
	{
		return intList.read(key);
	}
	mca::Tag<unsigned int>& getUintTag(std::string const&key)
	{
		return uintList.read(key);
	}
	mca::Tag<short>& getShortTag(std::string const&key)
	{
		return shortList.read(key);
	}
	mca::Tag<unsigned short>& getUshortTag(std::string const&key)
	{
		return ushortList.read(key);
	}
	mca::Tag<long>& getLongTag(std::string const&key)
	{
		return longList.read(key);
	}
	mca::Tag<unsigned long>& getUlongTag(std::string const&key)
	{
		return ulongList.read(key);
	}
	mca::Tag<char>& getCharTag(std::string const&key)
	{
		return charList.read(key);
	}
	mca::Tag<unsigned char>& getUcharTag(std::string const&key)
	{
		return ucharList.read(key);
	}
	mca::Tag<bool>& getBoolTag(std::string const&key)
	{
		return boolList.read(key);
	}
	mca::Tag<std::string>& getStringTag(std::string const&key)
	{
		return strList.read(key);
	}
public:
	bool isEmpty()const
	{
		return strList.empty()&&intList.empty()&&uintList.empty()&&charList.empty()&&ucharList.empty()&&floatList.empty()&&doubleList.empty()&&boolList.empty()&&shortList.empty()&&ushortList.empty()&&longList.empty()&&ulongList.empty();
	}
};
}

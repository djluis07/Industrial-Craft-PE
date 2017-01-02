#pragma once

#include <string>

namespace mca
{
template <typename Type>
class Tag
{
protected:
	Type typeSelf;
	std::string key;
public:
	Tag()=default;
	~Tag()=default;
	Tag(std::string const&ke,Type t)
	{
		key=ke;
		typeSelf=t;
	}
	Tag(std::string const&ke)
	{
		key=ke;
	}
public:
	void reset(Type t)
	{
		typeSelf=t;
	}
	void reset(std::string const&ke,Type t)
	{
		key=ke;
		typeSelf=t;
	}
	void resetKey(std::string const& t)
	{
		key=t;
	}
	Type get()
	{
		return typeSelf;
	}
	void set(Type t)
	{
		typeSelf=t;
	}
	Type getConst()const
	{
		return typeSelf;
	}
	std::string getKey()const
	{
		return key;
	}
};
}

#pragma once

#include <vector>

#include "Tag.h"

namespace mca
{
template <typename Type>
class ListTag
{
protected:
	std::vector<mca::Tag<Type>> tagList;
public:
	ListTag()=default;
	~ListTag()
	{
		tagList.clear();
	}
public:
	void addElement(mca::Tag<Type> t)
	{
		tagList.push_back(t);
	}
	mca::Tag<Type>& read(std::string const&key)
	{
		for(mca::Tag<Type>& t : tagList)
			if(t.getKey()==key)
				return t;
		mca::Tag<Type> newTag(key);
		return newTag;
	}
	const std::vector<mca::Tag<Type>> readAll()const
	{
		return tagList;
	}
	void clear()
	{
		tagList.clear();
	}
	bool empty()const
	{
		return tagList.empty();
	}
};
}

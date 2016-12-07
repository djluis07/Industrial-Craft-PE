#pragma once

#include "DatabaseWorker.h"

namespace mca
{
class DatabaseWriter : protected DatabaseWorker
{
public:
	DatabaseWriter(std::string const&path,std::string const&key,int codeKey)
	:DatabaseWorker(path,key,codeKey){}
	~DatabaseWriter()=default;
public:
	void write(std::vector<mca::ComposedTag> tagList)
	{
		std::ofstream ostream(filePath.c_str());
		ostream<<encode(fileKey)<<std::endl;
		for(mca::ComposedTag tag:tagList)
		{
			if(tag.isEmpty())
				continue;
			ostream<<encode("tag_"+tag.getKey())<<encode(cutLine);
			for(mca::Tag<float> mTag : tag.floatList.readAll())
				ostream<<encode("float_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<int> mTag : tag.intList.readAll())
				ostream<<encode("int_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<double> mTag : tag.doubleList.readAll())
				ostream<<encode("double_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<short> mTag : tag.shortList.readAll())
				ostream<<encode("short_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<long> mTag : tag.longList.readAll())
				ostream<<encode("long_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<bool> mTag : tag.boolList.readAll())
				ostream<<encode("bool_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<char> mTag : tag.charList.readAll())
				ostream<<encode("char_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<unsigned int> mTag : tag.uintList.readAll())
				ostream<<encode("uint_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<unsigned short> mTag : tag.ushortList.readAll())
				ostream<<encode("ushort_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<unsigned long> mTag : tag.ulongList.readAll())
				ostream<<encode("ulong_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<unsigned char> mTag : tag.ucharList.readAll())
				ostream<<encode("uchar_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
			for(mca::Tag<std::string> mTag : tag.strList.readAll())
				ostream<<encode("string_")<<encode(mTag.getKey())<<encode(cutLine)<<encode(toString(mTag.getConst()))<<encode(cutLine);
		}
	}
protected:
	template<typename Type>
	std::string toString(Type t)
	{
		std::stringstream str_stream;
		str_stream<<t;
		return str_stream.str();
	}
};
}

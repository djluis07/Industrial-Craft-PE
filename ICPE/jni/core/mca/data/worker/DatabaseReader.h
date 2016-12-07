#pragma once

#include "DatabaseWorker.h"

namespace mca
{
class DatabaseReader : protected DatabaseWorker
{
public:
	DatabaseReader(std::string const&path,std::string const&key,int codeKey)
	:DatabaseWorker(path,key,codeKey){}
	~DatabaseReader()=default;
public:
	std::vector<mca::ComposedTag> read()
	{
		std::ifstream istream(filePath.c_str());
		{
			std::string wasteStr;
			getline(istream,wasteStr);
		}
		std::vector<char> fileChars;
		while(!istream.eof())
		{
			char fileChar;
			istream.get(fileChar);
			fileChars.push_back(decode(fileChar));
		}
		std::vector<std::string> cutStringResult;
		std::string bridgeString;
		for(char letter:fileChars)
		{
			if(letter==cutLine)
			{
				cutStringResult.push_back(bridgeString);
				bridgeString="";
			}
			else bridgeString+=letter;
		}
		std::vector<mca::ComposedTag> finalResult;
		for(unsigned long pos=0;pos<cutStringResult.size();++pos)
		{
			std::string strElement=cutStringResult[pos];
			
			if(getNameType(strElement)=="tag")
				finalResult.push_back(mca::ComposedTag(getValueType(strElement)));
			else if(isValidNameType(getNameType(strElement)))
				addTag(finalResult[finalResult.size()-1],strElement,cutStringResult[pos+1]);
		}
		return finalResult;
	}
protected:
	void addTag(mca::ComposedTag&tag,std::string const&key_,std::string const&value)
	{
		std::string type=getNameType(key_);
		std::string key=getValueType(key_);
		std::stringstream str_stream;
		str_stream<<value;
		
		if(type=="int")
		{
			int value_item;
			str_stream>>value_item;
			tag.addInt(key,value_item);
		}
		else if(type=="string")
		{
			std::string value_item;
			str_stream>>value_item;
			tag.addString(key,value_item);
		}
		else if(type=="uint")
		{
			unsigned int value_item;
			str_stream>>value_item;
			tag.addUint(key,value_item);
		}
		else if(type=="bool")
		{
			bool value_item;
			str_stream>>value_item;
			tag.addBool(key,value_item);
		}
		else if(type=="float")
		{
			float value_item;
			str_stream.setf(std::ios::fixed,std::ios::floatfield);
			str_stream.precision(7);
			str_stream<<value;
			str_stream>>value_item;
			tag.addFloat(key,value_item);
		}
		else if(type=="double")
		{
			double value_item;
			std::stringstream str_stream;
			str_stream.setf(std::ios::fixed,std::ios::floatfield);
			str_stream.precision(15);
			str_stream<<value;
			str_stream>>value_item;
			tag.addDouble(key,value_item);
		}
		else if(type=="short")
		{
			short value_item;
			str_stream>>value_item;
			tag.addShort(key,value_item);
		}
		else if(type=="ushort")
		{
			unsigned short value_item;
			str_stream>>value_item;
			tag.addUshort(key,value_item);
		}
		else if(type=="char")
		{
			char value_item;
			str_stream>>value_item;
			tag.addChar(key,value_item);
		}
		else if(type=="uchar")
		{
			unsigned char value_item;
			str_stream>>value_item;
			tag.addUchar(key,value_item);
		}
		else if(type=="long")
		{
			long value_item;
			str_stream>>value_item;
			tag.addLong(key,value_item);
		}
		else if(type=="ulong")
		{
			unsigned long value_item;
			str_stream>>value_item;
			tag.addUlong(key,value_item);
		}
	}
	std::string getNameType(std::string const&str)
	{
		return str.substr(0,str.find_first_of("_"));
	}
	std::string getValueType(std::string const&str)
	{
		return str.substr(str.find_first_of("_")+1,str.length());
	}
	static bool isValidNameType(std::string const&type)
	{
		return type=="int"||type=="float"||type=="uint"||type=="double"||type=="string"||type=="char"||type=="uchar"||type=="short"||type=="ushort"||type=="long"||type=="ulong"||type=="bool";
	}
};
}

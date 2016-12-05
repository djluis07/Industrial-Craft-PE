/***********************************
 * CopyRight 2016 MCAL Team
 ***********************************/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>

template<typename Type>
class MCADataBase
{
public:
	class DataItem
	{
	public:
		DataItem(std::string const&n,Type t)
		{
			name=n,data=t;
		}
		std::string name;
		Type data;
	};
private:
	std::string filePath;
	std::vector<DataItem> argumentList;
public:
	MCADataBase()=default;
	MCADataBase(std::string const&path,std::vector<DataItem>&list)
	{
		argumentList=list;
		setFilePath(path);
		if(is_open())
			upData();
		
		if(is_open())
			return;
		makeFile(path);
		setData(argumentList);
		if(is_open())
			return;
		makeDir(filePath.substr(0,filePath.find_last_of("/")));
		makeFile(path);
		setData(argumentList);
	}
	MCADataBase(char const*path,std::vector<DataItem>&list)
	{
		argumentList=list;
		setFilePath(path);
		if(is_open())
			upData();
		
		if(is_open())
			return;
		makeFile(path);
		setData(argumentList);
		if(is_open())
			return;
		makeDir(filePath.substr(0,filePath.find_last_of("/")));
		makeFile(path);
		setData(argumentList);
	}
	~MCADataBase()
	{
		argumentList.clear();
	}
public:
	void setFilePath(std::string const&p)
	{
		filePath=p;
	}
	void setFilePath(char const*p)
	{
		filePath=p;
	}
	char const* getFilePath()const
	{
		return filePath.c_str();
	}
public:
	bool is_open()
	{
		std::ifstream ifs(filePath.c_str());
		return ifs.is_open();
	}
public:
	void makeDir(char const*path)
	{
		system(((std::string)"mkdir -p "+path).c_str());
	}
	void makeDir(std::string const&path)
	{
		system(((std::string)"mkdir -p "+path).c_str());
	}
	void makeFile(char const*path)
	{
		std::ofstream ofs(path);
		ofs.close();
	}
	void makeFile(std::string const&path)
	{
		std::ofstream ofs(path.c_str());
		ofs.close();
	}
	void deleteFile(char const*path)
	{
		remove(path);
	}
	void deleteFile(std::string const&path)
	{
		remove(path.c_str());
	}
	void makeEmpty(char const*path)
	{
		std::ofstream ofs(path);
		ofs.close();
	}
	void makeEmpty(std::string const&path)
	{
		std::ofstream ofs(path.c_str());
		ofs.close();
	}
private:
	std::vector<std::string> getNameIDList(int&linesCount)
	{
		linesCount=0;
		std::string bradgeStr;
		std::vector<std::string>strList;
		std::ifstream inFileStream(filePath.c_str());
		while(!inFileStream.eof())
		{
			getline(inFileStream,bradgeStr);
			strList.push_back(bradgeStr);
			++linesCount;
		}
		--linesCount;
		inFileStream.close();
		
		for(int f=0;f<linesCount;++f)
			strList[f]=strList[f].substr(0,strList[f].find_last_of(':'));
		return strList;
	}
public:
	Type getData(std::string const&argu)
	{
		int pos=0;
		Type num;
		int lines=0;
		std::vector<std::string>strList(argumentList.size());
		std::vector<std::string>filenameIDList=getNameIDList(lines);

		std::ifstream inFileStream(filePath.c_str());
		for(int f=0;f<argumentList.size();++f)
			getline(inFileStream,strList[f]);
		while(argu!=filenameIDList[pos])
		{
			++pos;
			if(filenameIDList.size()<=pos)
				return findItemByName(argu).data;
		}
		inFileStream.close();
		
		if(strList[pos].empty())
			return findItemByName(argu).data;

		std::string numStr;
		numStr=strList[pos].substr(filenameIDList[pos].length()+1,strList[pos].length()-(filenameIDList[pos].length()+1));

		std::stringstream stm;
		stm<<numStr;
		stm>>num;
		return num;
	}
	void setData(std::string const&argu,Type data)
	{
		int pos=0;
		int lines=0;
		std::vector<std::string>strList(argumentList.size());
		std::vector<std::string>filenameIDList=getNameIDList(lines);
		
		std::ifstream iFileStream(filePath.c_str());
		while(argu!=filenameIDList[pos])
			++pos;
		for(int f=0;f<lines;++f)
			getline(iFileStream,strList[f]);
		iFileStream.close();
		std::ofstream outFileStream(filePath.c_str());
		strList[pos]=argu+":"+tostr(data);
		
		for(int f=0;f<lines;++f)
			outFileStream<<strList[f]<<std::endl;;
	}
private:
	void setData(std::vector<DataItem>&list)
	{
		std::ofstream outFileStream(filePath.c_str());
		for(int f=0;f<list.size();++f)
			outFileStream<<list[f].name+":"+tostr(list[f].data)<<std::endl;
	}
	void upData()
	{
		for(int f=0;f<argumentList.size();++f)
			argumentList[f].data=getData(argumentList[f].name);
		setData(argumentList);
	}
	std::string tostr(Type t)
	{
		std::ostringstream ostm;
		ostm<<t;
		return ostm.str();
	}
	DataItem & findItemByName(std::string const&name)
	{
		for(unsigned int pos=0;pos<argumentList.size();++pos)
			if(argumentList[pos].name==name)
				return argumentList[pos];
	}
};

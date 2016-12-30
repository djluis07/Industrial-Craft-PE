#pragma once

#include <string>
#include <fstream>

#include "mcpe/util/Util.h"

class Log
{
public:
	static std::ofstream logstream;
public:
	static void e(std::string const&);
	static void w(std::string const&);
	static void p(std::string const&);
public:
	static std::string getLocalPath();
	static std::string init();
	static bool access(std::string const&);
};

#define LOG_P(msg)\
Log::p(std::string(__FILE__)+","+std::string(Util::toString(__LINE__)+","+(msg)))

#define LOG_W(msg)\
Log::w(std::string(__FILE__)+","+std::string(Util::toString(__LINE__)+","+(msg)))

#define LOG_E(msg)\
Log::e(std::string(__FILE__)+","+std::string(Util::toString(__LINE__)+","+(msg)))

#pragma once
#include "LookupTable.h"
#include "Configuration.h"
#include <string>

//TODO: Eventually all this information needs a proper place to live.
//this is its home for the time being until the important things are done
char gXRegister = 0, gYRegister = 0;
bool registerCheckPassed = false;

LookupTable gLookup;
FunctionTable gFunctionLookup;
Configuration gConfig;


unsigned gSeed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gGenerator(gSeed);
std::uniform_int_distribution<> gDistribution(0, MAX_PROB);

struct FunctionBuildData
{
	FunctionBuildData() { ResetFunctionBuildData(); }

	std::string instructionList;
	std::string currentFunctionName;
	bool functionParseMode;

	void ResetFunctionBuildData()
	{
		instructionList = "";
		currentFunctionName = "";
		functionParseMode = false;
	}
};
FunctionBuildData functionBuild;
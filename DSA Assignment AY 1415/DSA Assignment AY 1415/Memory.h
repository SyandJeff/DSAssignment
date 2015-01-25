#ifndef MEMORY_H
#define MEMORY_H

#include <windows.h>
#include <psapi.h>

SIZE_T getMem()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T bMem;

	
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	bMem = pmc.PrivateUsage;

	return bMem;
}


#endif
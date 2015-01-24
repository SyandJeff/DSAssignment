#ifndef MEMORY_H
#define MEMORY_H

#include <windows.h>
#include <psapi.h>

SIZE_T beforeMem()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T bMem;

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	bMem = pmc.PrivateUsage;

	return bMem;
}

SIZE_T afterMem()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T aMem;

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	aMem = pmc.PrivateUsage;

	return aMem;
}

#endif
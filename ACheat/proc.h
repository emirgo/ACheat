#pragma once
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

/*
	Fetch 32bit processes, iterate over them 
	until matching procName is found, return the process id
*/
DWORD getProcId(const wchar_t* procName);

/*
	Fetch 32bit processes, iterate over them
	until matching modname is found, return the base addr
*/
uintptr_t getModuleBaseAddress(DWORD procId, const wchar_t* modName);

uintptr_t findDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int>);

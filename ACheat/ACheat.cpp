/*
 * Description: Assault Cube cheat
 */

#include <iostream>
#include "proc.h"
#include "mem.h"

enum Address { HEALTH, ASSAULT_RIFLE_AMMO, PISTOL_AMMO, GRENADE_AMMO };

int maxAmmo = 1337;

int main()
{
	HANDLE hProcess = 0;

	uintptr_t moduleBase = 0, localPlayerPtr = 0, healthAddr = 0;
	bool bHealth = false, bAmmo = false;

	const int newValue = 1337;

	DWORD procId = getProcId(L"ac_client.exe");

	if (procId)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		moduleBase = getModuleBaseAddress(procId, L"ac_client.exe");

		localPlayerPtr = moduleBase + 0x109B74;

		healthAddr = findDMAAddy(hProcess, localPlayerPtr, { 0xF8 });
	}
	else
	{
		std::cout << "Process not found.";
		return 0;
	}

	DWORD dwExit = 0;

	while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
	{
		if (GetAsyncKeyState(VK_DELETE) & 1)
		{
			bHealth = !bHealth;
		}

		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			bAmmo = !bAmmo;

			if (bAmmo)
			{
				mem::patchEx((BYTE*)(moduleBase + 0x637e9), (BYTE*)"\xFF\x06", 2, hProcess);
			}
			else
			{
				mem::patchEx((BYTE*)(moduleBase + 0x637e9), (BYTE*)"\xFF\x0E", 2, hProcess);
			}
		}
	}

	return 0;
}

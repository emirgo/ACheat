/*
 * Description: Assault Cube cheat
 */

#include <iostream>
#include "proc.h"
#include "UserSettings.h"

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
	}

	return 0;
}

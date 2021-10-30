/*
 * Description: Assault Cube cheat
 */

#include <iostream>
#include "proc.h"


int main()
{
	// get procid of the target
	DWORD procId = getProcId(L"ac_client.exe");

	// get module base addr
	uintptr_t moduleBase = getModuleBaseAddress(procId, L"ac_client.exe");

	// get handle to process
	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	// resolve base addr of the pointer chain
	uintptr_t dynamicptrBaseAddr = moduleBase + 0x109B74;

	std::cout << "DynamicPtrBaseAddr = " << "0x" << std::hex << dynamicptrBaseAddr << std::endl;

	// resolve ammo ptr chain
	std::vector<unsigned int> ammoOffsets = { 0x150 };
	uintptr_t ammoAddr = findDMAAddy(hProcess, dynamicptrBaseAddr, ammoOffsets);

	std::cout << "AmmoAddr = " << "0x" << std::hex << ammoAddr << std::endl;

	// read ammo value


	// write ammo value

	// read ammo value to confirm

	return 0;
}

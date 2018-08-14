// hidepydbg.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <windows.h>
#include "aadlib.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

//hide debugger
extern "C" __declspec(dllexport) void hide_debug(DWORD process_id)
{
    hd_NtGlobalFlags(process_id);
    hd_IsDebuggerPresent(process_id);
    hd_HeapFlagsOnPEB(process_id);

    hd_ZwQuerySystemInformation(process_id);
    hd_HookZwQueryInformationProcess(process_id);
    hd_HookZwSetInformationThread(process_id);
}

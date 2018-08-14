// $Id: aadlib.h 19 2010-12-02 15:44:48Z nahuelriva $
//#pragma comment(lib, "aadlib.lib")

// Functions that do the magic ...
BOOL __stdcall hd_GetTickCount(DWORD pid);
BOOL __stdcall hd_HeapFlagsOnPEB(DWORD pid);
BOOL __stdcall hd_NtGlobalFlags(DWORD pid);
BOOL __stdcall hd_IsDebuggerPresent(DWORD pid);
BOOL __stdcall hd_HookZwQueryInformationProcess(DWORD pid);
BOOL __stdcall hd_HookZwSetInformationThread(DWORD pid);
BOOL __stdcall hd_HookOutputDebugString(DWORD pid);
BOOL __stdcall hd_ZwQueryObject(DWORD pid);
BOOL __stdcall hd_ZwOpenProcess(DWORD DebugeePid, DWORD DbgPid);
BOOL __stdcall hd_Module32Next(DWORD pid);
BOOL __stdcall hd_Process32Next(DWORD pid);
BOOL __stdcall hd_BlockInput(DWORD pid);
BOOL __stdcall hd_SuspendThread(DWORD pid);
BOOL __stdcall hd_TerminateProcess(DWORD pid);
BOOL __stdcall hd_FindWindow(HWND hWnd, char* lpString, DWORD pid);
BOOL __stdcall hd_UnhandledExceptionFilter(DWORD pid);
BOOL __stdcall hd_ZwQuerySystemInformation(DWORD pid);

// Auxiliary functions
HANDLE __stdcall hd_GetProcHandleByPid(DWORD pid);
DWORD __stdcall hd_GetProcPidByHandle(HANDLE pHandle);
void* __stdcall hd_GetPEBAddress(DWORD pid);
BOOL __stdcall hd_DllInjector(DWORD ProcessId, char* DLLLibPath, bool WaitForResponse);

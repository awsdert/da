#ifndef INC_ODAS_RTL_PROC_PARAM
#define INC_ODAS_RTL_PROC_PARAM
#include "odas.h"
#include "odas_curdir.h"
#include "odas_rtl_drive_letter_curdir.h"
#ifndef DA_OS_MSWIN
struct odas_rtl_proc_param {
	udal_t MaximumLength;
	udal_t Length;
	udal_t Flags;
	udal_t DebugFlags;
	void *ConsoleHandle;
	udal_t ConsoleFlags;
	void *StandardInput;
	void *StandardOutput;
	void *StandardError;
	odas_curdir_t CurrentDirectory;
	odas_ucs_t DllPath;
	odas_ucs_t ImagePathName;
	odas_ucs_t CommandLine;
	void *Environment;
	udal_t StartingX;
	udal_t StartingY;
	udal_t CountX;
	udal_t CountY;
	udal_t CountCharsX;
	udal_t CountCharsY;
	udal_t FillAttribute;
	udal_t WindowFlags;
	udal_t ShowWindowFlags;
	odas_ucs_t WindowTitle;
	odas_ucs_t DesktopInfo;
	odas_ucs_t ShellInfo;
	odas_ucs_t RuntimeData;
	odas_rtl_drive_letter_curdir_t CurrentDirectores[32];
	udal_t EnvironmentSize;
};
#endif
#endif

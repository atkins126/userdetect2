#ifndef _UD2_API_H_
#define _UD2_API_H_

#include <windows.h>

const char UD2_MULTIPLE_ITEMS_DELIMITER = 0x10;

#include "ud2_guid.h"
#include "ud2_status.h"
#include "ud2_utils.h"

#ifdef BUILDING_DLL
#define UD2_API extern "C" __cdecl __declspec(dllexport)
#else
#define UD2_API extern "C" __cdecl __declspec(dllimport)
#endif

UD2_API GUID PluginIdentifier();
UD2_API UD2_STATUS PluginNameW(LPWSTR lpPluginName, DWORD cchSize, LANGID wLangID);
UD2_API UD2_STATUS PluginVersionW(LPWSTR lpPluginVersion, DWORD cchSize, LANGID wLangID);
UD2_API UD2_STATUS PluginVendorW(LPWSTR lpPluginVendor, DWORD cchSize, LANGID wLangID);
UD2_API UD2_STATUS CheckLicense(LPVOID lpReserved);
UD2_API UD2_STATUS IdentificationMethodNameW(LPWSTR lpIdentificationMethodName, DWORD cchSize);
UD2_API UD2_STATUS IdentificationStringW(LPWSTR lpIdentifier, DWORD cchSize);
UD2_API BOOL DescribeOwnStatusCodeW(LPWSTR lpErrorDescription, DWORD cchSize, UD2_STATUS statusCode, LANGID wLangID);

#ifdef UD2_DYNAMIC_PLUGIN
// Extension of the plugin API starting with version v2.2.
// We don't assign a new PluginIdentifier GUID since the methods of the old API
// are still valid, so an UserDetect2 v2.0/v2.1 plugin can be still used with UserDetect2 v2.2.
// Therefore, this function *MUST* be optional and therefore it may only be imported dynamically.
UD2_API UD2_STATUS DynamicIdentificationStringW(LPWSTR lpIdentifier, DWORD cchSize, LPWSTR lpDynamicData);
#endif

const GUID GUID_USERDETECT2_IDPLUGIN_V1 = __GUID("{6C26245E-F79A-416C-8C73-BEA3EC18BB6E}");
#ifdef BUILDING_DLL
UD2_API GUID PluginInterfaceID() {
	return GUID_USERDETECT2_IDPLUGIN_V1;	
}
#else
UD2_API GUID PluginInterfaceID();
#endif

#endif

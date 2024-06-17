#pragma once

#ifdef JG_PLATFORM_WINDOWS
    #ifdef JG_BUILD_DLL
        #define JAGAT_API __declspec(dllexport)
    #else
        #define JAGAT_API __declspec(dllimport)
    #endif
#else
    #error Jagat only supports Windows!
#endif

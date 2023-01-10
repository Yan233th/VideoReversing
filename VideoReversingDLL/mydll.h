#pragma once

#ifdef BUILD_MYDLL
#define API_SYMBOL __declspec (dllexport)
#else
#define API_SYMBOL __declspec (dllimport)
#endif

//extern "C" API_SYMBOL char* GetFileName (char* input);
//extern "C" API_SYMBOL char* GetFilePath (char* input);
extern "C" API_SYMBOL void VideoReverse (char* input, void (*CallBack) (bool status));
//extern "C" API_SYMBOL void ReturnValue (void (*CallBack) (bool status), bool status);
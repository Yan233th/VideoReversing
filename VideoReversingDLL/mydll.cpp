#define BUILD_MYDLL

#include "pch.h"
#include "mydll.h"

#include <iostream>
#include <string>

using namespace std;

//char* Legalization (char* input)
//{
//    string str = input;
//    int length = str.size ();
//    while (str.find ('"') != string::npos) str = str.replace (str.find ('"'), 1, "\\\"");
//    char* output = (char*) str.c_str ();
//    return output;
//}

string GetFileName (string input)
{
    int length = input.size ();
    int begin = 0;
    if (input.rfind ('/') != string::npos)
        begin = input.rfind ('/') + 1;
    string fileName = input.substr (begin, length - begin);
    return fileName;
}

string GetFilePath (string input)
{
    int length = input.size ();
    int end = 0;
    if (input.rfind ('/') != string::npos)
        end = input.rfind ('/');
    string filePath = input.substr (0, end + 1);
    return filePath;
}

//void ReturnValue (void (*CallBack) (bool status), bool status)
//{
//    CallBack (status);
//    return;
//}

void VideoReverse (char* input, void (*CallBack) (bool status))
{
    string path = input;
    string command = "ffmpeg.exe -y -i " + path + " -vf reverse -af areverse " + GetFilePath (path) + "reversed.mp4";
    bool status = system (command.c_str ());
    CallBack (status);
    return;
}
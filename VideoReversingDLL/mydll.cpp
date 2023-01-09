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
//
//char* GetFileName (char* input)
//{
//    string path = input;
//    int length = path.size ();
//    int begin = 0;
//    if (path.rfind ('/') != string::npos) begin = path.rfind ('/') + 1;
//    string fileName = path.substr (begin, length - begin);
//    char temp[2333] = {0};
//    strcpy_s (temp, fileName.c_str ());
//    char* output = temp;
//    return output;
//}
//
//char* GetFilePath (char* input)
//{
//    string path = input;
//    int length = path.size ();
//    int end = 0;
//    if (path.rfind ('/') != string::npos) end = path.rfind ('/');
//    string filePath = path.substr (0, end + 1);
//    char temp[2333] = {0};
//    strcpy_s (temp, filePath.c_str ());
//    char* output = temp;
//    return output;
//}

string GetFileName (string input)
{
    int length = input.size ();
    int begin = 0;
    if (input.rfind ('/') != string::npos) begin = input.rfind ('/') + 1;
    string fileName = input.substr (begin, length - begin);
    return fileName;
}

string GetFilePath (string input)
{
    int length = input.size ();
    int end = 0;
    if (input.rfind ('/') != string::npos) end = input.rfind ('/');
    string filePath = input.substr (0, end + 1);
    return filePath;
}

bool VideoReverse (char* input)
{
    string path = input;
    string command = "ffmpeg.exe -y -i " + path + " -vf reverse -af areverse " + GetFilePath (path) + "reversed.mp4";
    bool status = system (command.c_str ());
    return status;
}
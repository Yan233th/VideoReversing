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

//void ReturnValue (void (*CallBack) (int status), int status)
//{
//    CallBack (status);
//    return;
//}

void VideoReverse (char* input, void (*CallBack) (int status))
{
    string path = input;
    string command = "ffmpeg.exe -y -i " + path + " -vf reverse -af areverse " + GetFilePath (path) + "reversed.mp4";
    int status = system (command.c_str ());
    CallBack (status);
    return;
}

void VideoRevCom (char* input, void (*CallBack) (int status))
{
    bool flag = false;
    string path = input;
    string filePath = GetFilePath (path);
    string command1 = "ffmpeg.exe -y -i " + path + " " + filePath + "original-temp.ts";
    int status1 = system (command1.c_str ());
    if (status1 != 0) {CallBack (-1); return;}
    string command2 = "ffmpeg.exe -y -i " + path + " -vf reverse -af areverse " + filePath + "reversed-temp.ts";
    int status2 = system (command2.c_str ());
    if (status2 != 0) {CallBack (-1); return;}
    FILE *fp = NULL;
    string txtPath = filePath + "templist.txt";
    int status3 = fopen_s (&fp, txtPath.c_str (), "w+");
    if (status3 != 0) {CallBack (-1); return;}
    string inputText = "file '" + filePath + "original-temp.ts'\nfile '" + filePath + "reversed-temp.ts'";
    fprintf (fp, inputText.c_str ());
    fclose (fp);
    string command3 = "ffmpeg.exe -y -f concat -safe 0 -i \"" + filePath + "templist.txt\" \"" + filePath + "output.mp4\"";
    int status4 = system (command3.c_str ());
    if (status4 != 0) {CallBack (-1); return;}
    remove ((filePath + "original-temp.ts").c_str ());
    remove ((filePath + "reversed-temp.ts").c_str ());
    remove ((filePath + "templist.txt").c_str ());
    CallBack (0);
    return;
}
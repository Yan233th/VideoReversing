#define BUILD_MYDLL

#include "pch.h"
#include "mydll.h"

#include <iostream>
#include <string>

using namespace std;

char* Legalization (char* input)
{
    string str = input;
    int length = str.size ();
    while (str.find ('\\') != string::npos) str = str.replace (str.find ('\\'), 1, "/");
    while (str.find ('"') != string::npos) str = str.replace (str.find ('"'), 1, "\\\"");
    char* output = (char*) str.c_str ();
    return output;
}

char* GetFileName (char* input)
{
    string path = input;
    int length = path.size ();
    int begin = 0;
    if (path.rfind ('/') != string::npos) begin = path.rfind ('/');
    string fileName = path.substr (begin, length - begin);
    char* output = (char*) fileName.c_str ();
    return output;
}

bool Edit ()
{
    
    return status;
}
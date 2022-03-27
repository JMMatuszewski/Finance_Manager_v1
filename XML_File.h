#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XML_File
{
    const string FILE_NAME;

public:
    XML_File(string fileName) : FILE_NAME(fileName){}

    string getFileName();
};

#endif;

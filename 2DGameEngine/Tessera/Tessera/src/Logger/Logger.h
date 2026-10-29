#pragma once
#include <string>
#include <iostream>
#include <fstream>

enum class LogType : uint8_t
{
    Info = 1,
    Warning = 2,
    Error = 3
};

class Logger
{
     static bool bSavefileSet;
    static std::string filename;
    static std::ofstream savefile;
public:

    // log which takes in a message a type of error 
    // saves it to a file 
    // flushes it out every time u open

    Logger();

    static void SetSavefile(const std::string& savefilename);
    static void Log(const LogType &type, const std::string& message);
    static void LogRefresh();
};

#include "Logger.h"
#include <chrono>
#include <format>

std::string Logger::filename = "Logs.txt";
std::ofstream Logger::savefile;


Logger::Logger()
{
}

void Logger::SetSavefile(const std::string& savefilename)
{
    filename = savefilename;
}

void Logger::Log(const LogType&type, const std::string& message)
{
    // have 3 types :
    // //1) Error 
    // 2) Info
    //3) Warning
    
    savefile.open(filename,std::ios::app);

    if (!savefile.is_open())
    {
        std::cout << "The file has failed to open " << std::endl;
        return;
    }

    std::string timestamp = std::format("{:%H:%M:%S}", std::chrono::floor<std::chrono::seconds>(std::chrono::current_zone()->to_local(std::chrono::system_clock::now())));
    
    std::string pass;
    std::string consoleLog;

    switch (type)
    {
    case LogType::Info :
       
        pass = "Log | " + timestamp + message + "\n";
        consoleLog = "\033[32m" + pass;

        break;
    case LogType::Warning :
        pass = "Warning |" + timestamp + message + "\n";
        consoleLog = "\033[33m" + pass;
        break;
    case LogType::Error :
        pass = "Error |" + timestamp + message + "\n";
        consoleLog = "\033[31m" + pass;
        break;
    default:
        break;
    }

    savefile << pass.c_str();

    savefile.close();
    std::cout<<consoleLog<< "\033[0m";
}

void Logger::LogRefresh()
{
    savefile.open(filename, std::ios::trunc);
}

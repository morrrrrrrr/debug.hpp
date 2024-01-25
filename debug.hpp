#pragma once

#include <string>
#include <fstream>

#include <ctime>
#include <chrono>

namespace Debug {
    static void clear() {
        #ifdef _DEBUG
        std::ofstream file("debug_log.txt", std::ios::out | std::ios::trunc);
        file.close();
        #endif   
    }

    #ifdef _DEBUG
    static void logRaw(const std::string& msg) {
        std::ofstream file("debug_log.txt", std::ios::out | std::ios::app);
        file << msg;
        file.close();
    }
    #endif
    static void log(const std::string& msg) {
        #ifdef _DEBUG
        // Get the current time using std::chrono and std::time
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        // Convert the current time to a string representation
        char timeStr[100]; // Allocate a buffer for the time string
        std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));

        logRaw(std::string(timeStr) + ": " + msg + "\n");
        #endif
    }

    static void logMessage(const std::string& msg) {
        #ifdef _DEBUG
        log(msg);
        #endif
    }
    static void logWarning(const std::string& msg) {
        #ifdef _DEBUG
        log("Warning: " + msg);
        #endif
    }
    static void logError(const std::string& msg) {
        #ifdef _DEBUG
        log("Error: " + msg);
        #endif
    }

    static void pause() {
        #ifdef _DEBUG
        system("pause");
        #endif
    }

    static void logCriticalError(const std::string& msg) {
        #ifdef _DEBUG
        logError(msg);
        std::cerr << msg << "\n";
        pause();
        #endif
        std::exit(-1);
    }
}

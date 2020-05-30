//
// Created by kvxmmu on 5/29/20.
//

#ifndef DARKPROJECT_LOGGER_HPP
#define DARKPROJECT_LOGGER_HPP

#include <iostream>

#define WARNING 0b0001u
#define DEBUG 0b0010u
#define INFO 0b0100u
#define ERROR 0b1000u

#define INFO_CAPTION "Information"
#define ERROR_CAPTION "Error"
#define DEBUG_CAPTION "Debug"
#define WARNING_CAPTION "Warning"

typedef struct {
    char zeros[8];
} _endl;

class Logger;

class LogStreamer {
public:
    uint8_t log_flag;
    Logger &logger;

    std::string caption;
    std::string buffer;

    LogStreamer(uint8_t _log_flag, Logger &lg, std::string _caption);

    void write_buffer(const std::string &expr);
    void write(const std::string &text);
    void flush() const;

    friend LogStreamer &operator<<(LogStreamer &stream, const std::string &string);
    friend LogStreamer &operator<<(LogStreamer &stream, const float &point);
    friend LogStreamer &operator<<(LogStreamer &stream, const int &integer);
    friend LogStreamer &operator<<(LogStreamer &stream, const char &let);
    friend LogStreamer &operator<<(LogStreamer &stream, const _endl &os);
};

class Logger {
public:
    uint8_t flags;
    std::string app_name;

    // streamers
    LogStreamer error;
    LogStreamer info;
    LogStreamer warning;
    LogStreamer debug;

    constexpr const static _endl endl = {};

    Logger(std::string _app_name, uint8_t _flags);

    void _log(const std::string &text,
            const std::string &caption) const;
};

using lg = Logger;


#endif //DARKPROJECT_LOGGER_HPP

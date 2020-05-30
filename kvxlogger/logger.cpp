//
// Created by kvxmmu on 5/29/20.
//

#include "logger.hpp"

// LogStreamer

LogStreamer::LogStreamer(uint8_t _log_flag, Logger &lg,
        std::string _caption) : log_flag(_log_flag), logger(lg), caption(std::move(_caption)) {

}

LogStreamer &operator<<(LogStreamer &stream, const std::string &string) {
    stream.write(string);

    return stream;
}

void LogStreamer::write(const std::string &text) {
    if ((this->logger.flags & this->log_flag) != this->log_flag) {
        return;
    }

    this->write_buffer(text);
}

void LogStreamer::write_buffer(const std::string &expr) {
    this->buffer += expr;
}

void LogStreamer::flush() const {
    this->logger._log(this->buffer, this->caption);
}

LogStreamer &operator<<(LogStreamer &stream, const float &point) {
    stream.write(std::to_string(point));

    return stream;
}

LogStreamer &operator<<(LogStreamer &stream, const int &integer) {
    stream.write(std::to_string(integer));

    return stream;
}

LogStreamer &operator<<(LogStreamer &stream, const char &let) {
    std::string write_string(&let, 1);

    stream.write(write_string);

    return stream;
}

LogStreamer &operator<<(LogStreamer &stream, const _endl &os) {

    if ((stream.logger.flags & stream.log_flag) != stream.log_flag) {
        return stream;
    }

    stream.flush();
    stream.buffer.clear();

    return stream;
}

// Logger

Logger::Logger(std::string _app_name,
        uint8_t _flags) : app_name(std::move(_app_name)), flags(_flags),
        error(ERROR, *this, ERROR_CAPTION), info(INFO, *this, INFO_CAPTION),
        warning(WARNING, *this, WARNING_CAPTION), debug(DEBUG, *this, DEBUG_CAPTION) {

}


void Logger::_log(const std::string &text,
        const std::string &caption) const {

    std::cout << '[' << this->app_name << "]:" << caption << "> " << text << std::endl;
}



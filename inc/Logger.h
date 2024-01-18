//
// Created by 14621 on 2024/1/18.
//

#ifndef PADDEMO_LOGGER_H
#define PADDEMO_LOGGER_H
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/initializer.h>
#include <log4cplus/configurator.h>
#include <iostream>

using namespace std;
using namespace log4cplus;
enum MyLogLevel{
    E_LOG_TRACE = 0,
    E_LOG_DEBUG,
    E_LOG_INFO,
    E_LOG_WARN,
    E_LOG_ERROR,
    E_LOG_FATAL,
};

class MyLogger{
public:
    /**
     * @brief:      Construction func.
     * @param[in]:  None.
     * @return:     None.
     * */
    explicit MyLogger();
    /**
     * @brief:      Destroy func.
     * @param[in]:  None.
     * @return:     None.
     * */
    ~MyLogger();
    /**
     * @brief:      record msg log.
     * @param[in]:  logLevel -- set Log level.
     * @param[in]:  msg -- the log msg want to write.
     * @return:     None.
     * */
     void LoggerRecord(MyLogLevel logLevel, string msg);

private:
    Logger m_logger;
};
extern MyLogger myLogger;

#endif //PADDEMO_LOGGER_H

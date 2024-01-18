//
// Created by 14621 on 2024/1/18.
//

#include "Logger.h"

MyLogger::MyLogger() {
    system("mkdir ../log");
    Logger root = Logger::getRoot();
    m_logger = Logger::getInstance(LOG4CPLUS_TEXT("MyLogger"));
    /* 使用一个线程去监控配置文件实现动态配置，时间间隔单位为ms，默认为60*1000 */
    ConfigureAndWatchThread configureThread("../config/log4cplus.properties", 5 * 1000);
}

MyLogger::~MyLogger() {

}

void MyLogger::LoggerRecord(MyLogLevel logLevel, string msg) {
    switch (logLevel) {
        case E_LOG_TRACE:
            LOG4CPLUS_TRACE(m_logger, LOG4CPLUS_TEXT(msg));
            return;
        case E_LOG_DEBUG:
            LOG4CPLUS_DEBUG(m_logger, LOG4CPLUS_TEXT(msg));
            return;
        case E_LOG_INFO:
            LOG4CPLUS_INFO(m_logger, LOG4CPLUS_TEXT(msg));
            return;
        case E_LOG_WARN:
            LOG4CPLUS_WARN(m_logger, LOG4CPLUS_TEXT(msg));
            return;
        case E_LOG_ERROR:
            LOG4CPLUS_ERROR(m_logger, LOG4CPLUS_TEXT(msg));
            return;
        case E_LOG_FATAL:
            LOG4CPLUS_FATAL(m_logger, LOG4CPLUS_TEXT(msg));
            return;
        default:
            break;
    }
    cout << "log failed! check log level" <<endl;
    return;
}

MyLogger myLogger;
/**
 * @file        Utils/Utils.h
 * @author      Yasir Hassan <yasir.hassan1993@hotmail.com>
 * @date        October 2020
 */

#ifndef UTILS_H_
#define UTILS_H_

#define VERSION         MBED_CONF_APP_VERSION

#ifdef MBED_CONF_APP_DEBUG
#define LOG_DEBUG(x, ...) printf("[DEBUG: %s:%d] " x "\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define LOG_INFO(x, ...) printf("[INFO: %s:%d] " x "\r\n ", __FILE__, __LINE__,##__VA_ARGS__);
#define LOG_WARN(x, ...) printf("[WARN: %s:%d] " x "\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define LOG_ERROR(x, ...) printf("[ERROR: %s:%d] " x "\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#else
#define LOG_DEBUG(x, ...) do {} while(0);
#define LOG_INFO(x, ...) do {} while(0);
#define LOG_WARN(x, ...) do {} while(0);
#define LOG_ERROR(x, ...) do {} while(0);
#endif

#endif
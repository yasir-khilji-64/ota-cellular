/**
 * @file        main.cpp
 * @author      Yasir Hassan <yasir.hassan1993@hotmail.com>
 * @date        October 2020
 */

#include "mbed.h"
#include "Utils/Utils.h"

int main() {
    LOG_DEBUG("Firmware Version: %s", VERSION);
    LOG_DEBUG("Built on: %s %s", __DATE__, __TIME__);

    return 0;
}
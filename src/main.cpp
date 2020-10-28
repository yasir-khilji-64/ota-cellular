/**
 * @file        main.cpp
 * @author      Yasir Hassan <yasir.hassan1993@hotmail.com>
 * @date        October 2020
 */

#include "mbed.h"
#include "mbed-trace/mbed_trace.h"
#include "Utils/Utils.h"
#include "Network/Network.h"
#include "HTTPClient/HTTPClient.h"

NetworkInterface* net;
Network nwk;

int main() {
    LOG_DEBUG("Firmware Version: %s", VERSION);
    LOG_DEBUG("Built on: %s %s", __DATE__, __TIME__);

    mbed_trace_init();

    net = nwk.begin();

    if (nwk.connect() != NSAPI_ERROR_OK) {
        LOG_ERROR("Error establishing connection");
        delete net;
        mbed_trace_free();

        return -1;
    } else {
        LOG_INFO("Connected");
    }

    HTTPClient _client;
    int status = _client.getRequest(net, "http://httpbin.org/status/418");
    LOG_DEBUG("Status code for Get Request: %d", status);

    if (nwk.disconnect() == NSAPI_ERROR_OK) {
        LOG_DEBUG("Disconnected");
    }

    return 0;
}
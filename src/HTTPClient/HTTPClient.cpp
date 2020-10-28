/**
 * @file        HTTPClient/HTTPClient.cpp
 * @author      Yasir Hassan <yasir.hassan1993@hotmail.com>
 * @date        October 2020
 */

#include "mbed.h"
#include "Utils/Utils.h"
#include "Network/Network.h"
#include "HTTPClient/HTTPClient.h"

HTTPClient::HTTPClient() {
    // this->request = NULL;
}

HTTPClient::~HTTPClient() {
    // if (this->request != NULL) {
    //     delete this->request;
    // }
}

int HTTPClient::getRequest(NetworkInterface* _iface, const char* _url, Callback<void(const char* buff, uint32_t sz)> _cb) {
    HttpRequest* request;
    request = new HttpRequest(_iface, HTTP_GET, _url);

    HttpResponse* response = request->send();
    if (!response) {
        LOG_ERROR("HTTP Request Failed with error: %d", request->get_error());
        delete request;
        return -1;
    }

    LOG_DEBUG("HTTP GET Response");
    LOG_DEBUG("Status: %d - %s", response->get_status_code(), response->get_status_message().c_str());
    int _status = response->get_status_code();
    delete request;

    return _status;
}
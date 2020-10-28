/**
 * @file        HTTPClient/HTTPClient.h
 * @author      Yasir Hassan <yasir.hassan1993@hotmail.com>
 * @date        October 2020
 */

#ifndef HTTPCLEINT_H_
#define HTTPCLIENT_H_

#include "NetworkInterface.h"
#include "http_request.h"

class HTTPClient
{
private:
public:
    HTTPClient();
    ~HTTPClient();

    int getRequest(NetworkInterface* _iface, const char* url, Callback<void(const char* buff, uint32_t sz)> _cb=0);
};

#endif
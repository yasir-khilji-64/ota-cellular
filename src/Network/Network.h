/**
 * @file        Network/Network.h
 * @author      Yasir Hassan <yasir.hassan1993@hotmail.com>
 * @date        October 2020
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include "NetworkInterface.h"

class Network
{
private:
    NetworkInterface* _iface;
public:
    Network();
    ~Network();

    NetworkInterface* begin();
    nsapi_error_t connect();
    nsapi_error_t disconnect();
    bool isConnected();
};

#endif
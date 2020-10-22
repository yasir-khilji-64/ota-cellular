/**
 * @file        Network/Network.cpp
 * @author      Yasir Hassan <yasir.hassan1993@hotmail.com>
 * @date        October 2020
 */

#include "mbed.h"
#include "Utils/Utils.h"
#include "Network/Network.h"

Network::Network(){
    this->_iface = NULL;
}

Network::~Network() {
    delete this->_iface;
}

NetworkInterface* Network::begin() {
    this->_iface = NetworkInterface::get_default_instance();
    MBED_ASSERT(this->_iface != NULL);
    this->_iface->set_default_parameters();

    return this->_iface;
}

nsapi_error_t Network::connect() {
    nsapi_error_t ret = NSAPI_ERROR_OK;
    uint8_t retryCount = 0;

    while (this->_iface->get_connection_status() != NSAPI_STATUS_GLOBAL_UP) {
        ret = this->_iface->connect();
        if (ret == NSAPI_ERROR_AUTH_FAILURE) {
            LOG_ERROR("Authentication Failed.");
        } else if (ret == NSAPI_ERROR_OK) {
            LOG_INFO("Connection Established.");
        } else if (retryCount > 5) {
            LOG_ERROR("Fatal Connection Failure: %d", ret);
        } else {
            LOG_ERROR("Couldn't Connect: %d, Retrying.", ret);
            retryCount++;
            continue;
        }
        break;
    }
    return ret;
}

nsapi_error_t Network::disconnect() {
    return this->_iface->disconnect();
}

bool Network::isConnected() {
    if (this->_iface->get_connection_status() != NSAPI_STATUS_GLOBAL_UP) {
        return false;
    }
    return true;
}
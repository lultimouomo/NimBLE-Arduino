/*
 * NimBLEService.h
 *
 *  Created: on March 2, 2020
 *      Author H2zero
 *
 * Originally:
 *
 * BLEService.h
 *
 *  Created on: Mar 25, 2017
 *      Author: kolban
 */

#ifndef MAIN_NIMBLESERVICE_H_
#define MAIN_NIMBLESERVICE_H_
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include "nimconfig.h"
#if defined(CONFIG_BT_NIMBLE_ROLE_PERIPHERAL)

#include "NimBLECharacteristic.h"
#include "NimBLEServer.h"
#include "NimBLEUUID.h"
#include "FreeRTOS.h"


class NimBLEServer;
class NimBLECharacteristic;


/**
 * @brief The model of a %BLE service.
 *
 */
class NimBLEService {
public:
    NimBLECharacteristic* createCharacteristic(const char* uuid,
                        uint32_t properties = NIMBLE_PROPERTY::READ |
                                              NIMBLE_PROPERTY::WRITE);

    NimBLECharacteristic* createCharacteristic(const NimBLEUUID &uuid,
                        uint32_t properties = NIMBLE_PROPERTY::READ |
                                              NIMBLE_PROPERTY::WRITE);

    void                  dump();
    NimBLECharacteristic* getCharacteristic(const char* uuid);
    NimBLECharacteristic* getCharacteristic(const NimBLEUUID &uuid);
    NimBLEUUID            getUUID();
    NimBLEServer*         getServer();
    bool                  start();
    std::string           toString();
    uint16_t              getHandle();

private:
    NimBLEService(const char* uuid, uint16_t numHandles, NimBLEServer* pServer);
    NimBLEService(const NimBLEUUID &uuid, uint16_t numHandles, NimBLEServer* pServer);
    friend class NimBLEServer;
    friend class NimBLEDevice;

    uint16_t                m_handle;
    NimBLEServer*           m_pServer;
    NimBLEUUID              m_uuid;
    uint16_t                m_numHandles;

    std::vector<NimBLECharacteristic*> m_chrVec;

}; // NimBLEService


#endif // #if defined(CONFIG_BT_NIMBLE_ROLE_PERIPHERAL)
#endif // CONFIG_BT_ENABLED
#endif /* MAIN_NIMBLESERVICE_H_ */

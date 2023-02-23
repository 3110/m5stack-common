#include <M5Stack.h>

#include "Debug.h"

#ifdef ENABLE_SERIAL_MONITOR
uint8_t mac[ETH_ALEN] = {0};
#endif

void setup(void) {
    M5.begin();
    esp_read_mac(mac, ESP_MAC_WIFI_STA);
    SERIAL_PRINT("MAC: ");
    SERIAL_MAC_ADDRESS_PRINTLN(mac);
    SERIAL_PRINT("Dump: ");
    SERIAL_DUMP(mac, sizeof(mac));
}

void loop(void) {
    M5.update();
    if (M5.BtnA.wasPressed()) {
        SERIAL_PRINTLN("Button A was pressed.");
    }
    if (M5.BtnB.wasPressed()) {
        SERIAL_PRINTLN("Button B was pressed.");
    }
    if (M5.BtnC.wasPressed()) {
        SERIAL_PRINTLN("Button C was pressed.");
    }
}
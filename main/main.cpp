// #include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "gpioHandler.hpp"

#define OUTPUT "OUTPUT"
#define INPUT "INPUT"

#define HIGH "HIGH"
#define LOW "LOW"

#define lED_PIN GPIO_NUM_12
#define lED_PIN_2 GPIO_NUM_14

#define TAG "GPIO_TEST"

extern "C" void app_main(void)
{
    gpioHandler gpioHandle;
    gpioHandle.pinMode(lED_PIN, OUTPUT);
    gpioHandle.pinMode(lED_PIN_2, OUTPUT);
    ESP_LOGI(TAG, "pins initialization successfull");

    while (1) {
        gpioHandle.digitalWrite(lED_PIN, HIGH);
        gpioHandle.digitalWrite(lED_PIN_2, HIGH);
        vTaskDelay(pdMS_TO_TICKS(1000));

        gpioHandle.digitalWrite(lED_PIN, LOW);
        gpioHandle.digitalWrite(lED_PIN_2, LOW);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
}
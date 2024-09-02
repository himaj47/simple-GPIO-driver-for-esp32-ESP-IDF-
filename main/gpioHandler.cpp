#include "gpioHandler.hpp"
#include "esp_log.h"

#define TAG "GPIO_HANDLER"

gpioHandler::gpioHandler() {
    opcfg.pin_bit_mask = (uint64_t)(0);
    opcfg.pull_down_en = GPIO_PULLDOWN_DISABLE;
    opcfg.pull_up_en = GPIO_PULLUP_DISABLE;
    opcfg.mode = GPIO_MODE_OUTPUT;

    ipcfg.pin_bit_mask = (uint64_t)(0);
    ipcfg.pull_down_en = GPIO_PULLDOWN_DISABLE;
    ipcfg.pull_up_en = GPIO_PULLUP_DISABLE;
    ipcfg.mode = GPIO_MODE_INPUT;
};

void gpioHandler::pinMode(gpio_num_t gpio_num, std::string mode) {
    if (mode == "OUTPUT") {
        opcfg.pin_bit_mask |= (uint64_t)(1 << gpio_num);
        gpio_config(&opcfg);
        // gpio_set_direction(gpio_num, GPIO_MODE_OUTPUT);
    }

    else if (mode == "INPUT") {
        ipcfg.pin_bit_mask |= (uint64_t)(1 << gpio_num);
        gpio_config(&ipcfg);
        // gpio_set_direction(gpio_num, GPIO_MODE_INPUT);
    }
}

void gpioHandler::digitalWrite(gpio_num_t gpio_num, std::string level) {
    if (level == "HIGH") {
        gpio_set_level(gpio_num, 1);
    }

    else if (level == "LOW") {
        gpio_set_level(gpio_num, 0);
    }
}

int gpioHandler::get_gpio_level(gpio_num_t gpio_num) {
    return gpio_get_level(gpio_num);
}
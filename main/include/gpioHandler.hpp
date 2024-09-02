#ifndef GPIO_HANDLER
#define GPIO_HANDLER

#include <driver/gpio.h>
#include <iostream>

class gpioHandler {

public:
    gpioHandler();

    void pinMode(gpio_num_t gpio_num, std::string mode);
    void digitalWrite(gpio_num_t gpio_num, std::string level);
    int get_gpio_level(gpio_num_t gpio_num);

private:
    gpio_config_t opcfg;
    gpio_config_t ipcfg;
};


#endif
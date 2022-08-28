#include <stdio.h>
#include "pico/stdlib.h"
#include "distance_sensor.h"

int main() {
    stdio_init_all();

    DistanceSensor hcsr04{pio0, 0, 0};

    while (true) {
        hcsr04.TriggerRead();
        while (hcsr04.is_sensing) {
            sleep_us(10);
        }
        printf("Reading: %d cm\n", hcsr04.distance);
        sleep_ms(1000);
    }
}


#include "../include/car.h"

int main() {
    car v1{"Vectra"};
    v1.show_car_name();

    car v2 {"Insignia"};
    v2.show_car_name();

    v1 = v2;
    v1.show_car_name();

    car v3(v1);
    v3.show_car_name();
}
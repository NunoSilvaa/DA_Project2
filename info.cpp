//
// Created by nmls1 on 22/05/2022.
//

#include "info.h"

info::info() {}

int info::getOrigin() {
    return this->origin;
}

int info::getDestiny() {
    return this->duration;
}

int info::getCapacity() {
    return this->capacity;
}

int info::getDuration() {
    return this->duration;
}

void info::setOrigin(int origin) {
    this->origin = origin;
}

void info::setDestiny(int destiny) {
    this->destiny = destiny;
}
void info::setCapacity(int capacity) {
    this->capacity = capacity;
}
void info::setDuration(int duration) {
    this->duration = duration;
}
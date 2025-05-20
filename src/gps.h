#ifndef GPS_H
#define GPS_H
#include <Arduino.h>
#include "variable.h"
// coming soon
// currently returning coordinates of Sevastopol Ukraine

String updateCoordinates(String *lot, String *lat)
{
    *lot = "44.62336736580267";
    *lat = "33.51391959994705";

    return *lat + "," + *lot;
}

#endif
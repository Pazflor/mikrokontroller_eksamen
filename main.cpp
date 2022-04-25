#include <iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include <string>

using namespace std;

string createAlarm();
void snooze();

struct Clock {
    string long_time;
    string short_time;
    string alarm = "";
};

int main ()
{
    return 0;
}

void createAlarm(Clock clock) {
    char buffer[50];

    int h = 0;
    int m = 0;
    int i = 0;

    // variablen c tar input som placeholder for knapper
    // 1 = inkrementere gjeldene tall
    // 0 = gå til neste tall
    int c;
    while (true) {
        cin >> c;

        if (i == 0 && c == 1) {
            if (h == 23)
                h = -1;
            h++;
        } else if (i == 0 && c == 0) {
            i++;
        } else if (i == 1 && c == 1) {
            if (m == 59)
                m = -1;
            m++;
        } else if (i == 1 && c == 0) {
            i++;
        }

        if (i == 2) {
            break;
        }
        sprintf(buffer, "%.2d:%.2d", h, m);
    }
    clock.alarm = buffer;
}

void snooze(Clock clock) {
    cout << "Snoozed for 5 minutes" << endl;
    sleep(300);
    clock.alarm = clock.short_time;
}

void removeAlarm(Clock clock) {
    clock.alarm = "";
}

// MBED JSON WEATHER PARSING
/* ****************************************
#include "mbed.h"
#include <json.hpp>

using json = nlohmann::json;

struct Weather {
    string desc;
    float celsius;
};

Weather currWeather;

void parse_json_data(char *input_data) {
    json obj = json::parse(input_data, nullptr, false);

    if (obj["weather"]["description"].is_string()) {
        currWeather.desc = obj["weather"]["description"];
    }

    if (obj["main"]["temp"].is_number()) {
        currWeather.celsius = 273.15 - obj["main"]["temp"];
    }
}
*/
// ****************************************
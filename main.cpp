#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <string>

#include "json_parse.h"
#include "rss_reader.h"

using namespace std;

struct Clock {
    string long_time;
    string short_time;
    string alarm;
};

void createAlarm(Clock clock);
void removeAlarm(Clock clock);
void snooze();

int main ()
{
    /*
    json_parse jp;
    jp.parser();
     */

    rss_reader r;
    r.read();

    /*
    Clock clock;

    createAlarm(clock);

    sleep(3);

    removeAlarm(clock);
     */

    return 0;
}

void createAlarm(Clock clock) {
    char buffer[50];
    int h = 0;
    int m = 0;
    int i = 0;

    cout << "00:00" << endl;

    // variablen c tar input som placeholder for knapper
    // 1 = inkrementere gjeldende tall
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
        cout << buffer << endl;
    }
    clock.alarm = buffer;
    cout << "Alarm set at " << clock.alarm << endl;
}

void removeAlarm(Clock clock) {
    clock.alarm = "";
    cout << "Alarm removed" << endl;
}

void snooze(Clock clock) {
    cout << "Snoozed for 5 minutes" << endl;
    sleep(300);
    clock.alarm = clock.short_time;
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
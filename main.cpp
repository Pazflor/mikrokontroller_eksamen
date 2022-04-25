#include <iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include <string>

using namespace std;

void startClock();
bool checkAlarm();
string createAlarm(char extraMinutes);
void triggerAlarm();
void snooze();

struct Clock {
    bool alarmEnabled;
    bool alarmRinging;
};

int main ()
{
    setenv("TZ", "UTC-2", 1);
    tzset();

    startClock();

    // string alarm = createAlarm();

    return 0;
}

// Replace with API
time_t epoch = 1650701756;
struct tm ts;
char buf[80];
char fakeAlarm[] = "Sat 23 Apr 10:16:00";

/* For Mbed OS
 * set_time(epoch);
 *
 * while (true) {
 *     time_t seconds = time(NULL);
 *     char buffer[80];
 *     strftime(buf, sizeof(buf), "%a %d %b %H:%M:%S", localtime(&seconds));
 *     printf("\n%s", buf);
 * }
 */

void startClock() {
    while (true) {
        if (checkAlarm()) {
            triggerAlarm();
        }
        epoch++;
        ts = *localtime(&epoch);
        strftime(buf, sizeof(buf), "%a %d %b %H:%M:%S", &ts);
        printf("%s\n", buf);
        sleep(1);
    }
}

bool checkAlarm() {
    if (!(strcmp(buf, fakeAlarm))) {
        return true;
    }
}

string createAlarm(char extraMinutes) {
    char buffer[50];

    int h = 0;
    int m = 0;
    int i = 0;

    cout << "00:00" << endl;

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


        buffer[strlen(buffer) - 1] = extraMinutes;
        cout << buffer << endl;
    }
    return buffer;
}

string removeAlarm() {
    return "";
}

void snooze() {
    cout << "Snoozed for 5 minutes" << endl;
    createAlarm(5);
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
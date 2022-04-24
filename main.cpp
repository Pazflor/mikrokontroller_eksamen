#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string>

using namespace std;

void startClock();
bool checkAlarm();

int main ()
{
    setenv("TZ", "UTC-2", 1);
    tzset();

    startClock();

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
            break;
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
        cout << "Ring ring ring" << endl;
        return true;
    }
}
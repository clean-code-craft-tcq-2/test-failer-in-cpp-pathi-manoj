#include <iostream>
#include <assert.h>
#define CELSIUS_THRESHOLD_ALERT = 200;
int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if( celsius < CELSIUS_THRESHOLD_ALERT)
    {
       // Return 200 for ok
       return 200;
    }
    else
    {
       // Return 500 for not-ok
       return 500;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is alert!
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == 0);
    std::cout << "All is well (maybe!)\n";
    return 0;
}

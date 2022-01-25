#include <iostream>
#include <assert.h>
#define CELCIUS_THRESHOLD_ALERT 200.0f
int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if( celcius < CELCIUS_THRESHOLD_ALERT)
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

float farenheitToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}
void alertInCelcius(float farenheit) {
    float celcius = farenheitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is alert!
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5); // ALERT
    alertInCelcius(303.6); // NO ALERT
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == 0);
    std::cout << "All is well (maybe!)\n";
    return 0;
}

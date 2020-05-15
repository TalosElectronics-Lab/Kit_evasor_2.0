#include "Evasor.hpp"

Evasor robot_1;
void setup()
{
    robot_1.init();
    Serial.begin(9600);
}

void loop()
{
    robot_1.Modo_evasor(15,60);
}
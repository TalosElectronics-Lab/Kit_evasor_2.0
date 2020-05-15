#include "Robot.hpp"

Robot robot_1;
void setup()
{
    robot_1.Motores_init();
    robot_1.Motores_mv(100, -100);
}

void loop()
{
    
}
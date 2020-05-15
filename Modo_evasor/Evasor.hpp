#include "Robot.hpp"
#include <Servo.h>

//Clase evasor que hereda todos los metodos public de la clase Robot
class Evasor : public Robot
{
private:
    /* data */
    const uint8_t Echo = 11;
    const uint8_t Trigger = 10;
    const uint8_t Servo_pin = 13;
    uint8_t Angulo_min = 0;
    uint8_t Angulo_max = 180;
    Servo servo_1;
    float distancia;

public:
    Evasor(/* args */);
    ~Evasor();
    void init();
    void Modo_evasor(int Distancia, uint8_t velocidad);
    float Obtener_distancia();
};


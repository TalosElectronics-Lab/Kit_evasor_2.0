#include "Evasor.hpp"

void Evasor::Modo_evasor(int Distancia, uint8_t velocidad)
{
    float Distancia_izq, Distancia_der;

    Motores_mv(velocidad,velocidad);
    if (Obtener_distancia()<= Distancia)
    {
        Motores_mv(-80,-80);
        delay(250);
        Motores_mv(0,0);

        //Barrido de servo de derecha a izquierda
        for (size_t i = 90; i < Angulo_max; i++)
        {
            servo_1.write(i);
            delay(5);
        }
        Distancia_izq = Obtener_distancia();
        delay(300);
        

        for (size_t i = Angulo_max; i > Angulo_min; i--)
        {
            servo_1.write(i);
            delay(5);
        }
        Distancia_der = Obtener_distancia();
        delay(300);
        

        for (size_t i = Angulo_min; i < 90; i++)
        {
            servo_1.write(i);
            delay(5);
        }
        delay(250);

        if(Distancia_izq<Distancia_der)
        {
            //Obstaculo detectado en el lado izquierdo, debe girar a la derecha
            Motores_mv(50, -50);
            delay(500);
            Motores_mv(velocidad, velocidad);
        }
        else
        {
            //Obstaculo detectado en el lado derecho por lo que debe girar a la izquierda
            Motores_mv(-50, 50);
            delay(500);
            Motores_mv(velocidad, velocidad);
        }
        
    }
    
}

float Evasor::Obtener_distancia()
{
    long lduration;
    long ldistance;

    //Se manda un pulso por el pin Trigger
    digitalWrite(Trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);

    //Se mide cuanto tiempo tardo en us
    //Ecuación d = l_distancia/2 * velocidad cm/us
    lduration = pulseIn(Echo, HIGH);
    ldistance = (lduration / 2) / 29.1;
    return ldistance;
}

void Evasor::init()
{
    Motores_init();
    pinMode(Trigger, OUTPUT);
    pinMode(Echo, INPUT);
    servo_1.attach(Servo_pin);
    servo_1.write(90);
}

Evasor::Evasor() : Robot::Robot()
{
}
Evasor::~Evasor()
{
}

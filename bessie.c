#include <kipr/wombat.h>

//Moves wheels at speed for certain times//
void drive(int leftSpeed, int rightSpeed, int time)
{  
    motor(1, leftSpeed);
    motor(0, rightSpeed);
    msleep(time);
}


int main()
{
    //Gets the bot ready to move//
    set_servo_position(1, 1869);
    set_servo_position(2, 761);
    enable_servos();
    printf("Hello World\n");
    //drive(50, 50, 1500);//
   
    while(analog(5)<2000)
    {
        //uses a light sensor to move until it hits the black line//
        motor(1, 50);
        motor(0, 50);
    }
   
    drive(-50, -25, 300);
   
    while(analog(5)<2000)
    {
        //Uses light sensor to move the bot until it sees black//
        motor(1,-50);
        motor(0, -25);
    }
   
    while(analog(5)>2000)
    {
        //Moves it back until it sees white again//
        motor(1,-50);
        motor(0, -25);
    }
   
    //Shuts down all motors and makes it stop for 3 seconds//
    ao();
    msleep(3000);
   
    //Sets the servos to prepare to get the noodles//
    set_servo_position(1, 560);
    msleep(500);
    drive(50, 50, 600);
    set_servo_position(2, 993);

    //Moves forward until it sees white//
    while(analog(5)>2000)
    {
        motor(1,50);
        motor(0, 25);
    }
   
    disable_servos();
    return 0;
}
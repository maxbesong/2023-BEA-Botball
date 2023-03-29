#include <kipr/wombat.h>

#include "math.h"

//Makes robot drive with a specificed speed for each wheel, for a specified time//
void drive(int leftSpeed, int rightSpeed, int time)
{
    create_drive_direct(leftSpeed, rightSpeed*323.0/350.0);
    msleep(time);
}

//Makes robot turn for a specified angle//
void turn(int angle)
{
    int time= (abs(angle) * 2000.0 / 180.0);
    if(angle<0)
        drive(200, -200, time);
    else
        drive(-200, 200, time);
}

int main()
{
    printf("HELLO");
   
    //connects to roomba and sets servos//
    create_connect();
    printf("SECOND");
    set_servo_position(0, 100);
    enable_servos();
    printf("THIRD");
    wait_for_milliseconds(600);
   
    //Turns and knocks over rings//
    turn(-30);
    drive(200, 200, 90);
    printf("Hello World\n");
    set_servo_position(0,1500);
    wait_for_milliseconds(600);
    set_servo_position(0,100);
    wait_for_milliseconds(600);
   
    //Follows line until bumber is hit//
    printf("Hello World\n");
    int threshold = 2200;
    int speed = 250;
    create_full();
    turn(-30);
    printf( "Follow the non-yellow brick road!/n");
    while ((get_create_lbump() == 0) && (get_create_rbump() ==0))
    {
       
        if(get_create_lfcliff_amt() < threshold)
        {
            printf("turning left %d\n", get_create_lfcliff_amt());
            create_drive_direct(0.15*speed, speed);
        }
        else
        {
            printf("turning right %d\n", get_create_lfcliff_amt());
        create_drive_direct(speed, 0.5*speed);
        }
    }
    disable_servos();
   
    return 0;
}

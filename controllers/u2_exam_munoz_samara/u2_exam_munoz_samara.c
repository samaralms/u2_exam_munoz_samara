/*
 * File:          u2_exam_munoz_samara.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <webots/robot.h>
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/position_sensor.h>
#include <webots/distance_sensor.h>
#include <webots/keyboard.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();
    
  
   WbDeviceTag wheel_1 = wb_robot_get_device("wheel1");
   WbDeviceTag wheel_2 = wb_robot_get_device("wheel2");
   WbDeviceTag wheel_3 = wb_robot_get_device("wheel3");
   
   WbDeviceTag ds_left = wb_robot_get_device("ds_left");
   WbDeviceTag ds_right = wb_robot_get_device("ds_right");
   
   WbDeviceTag ps_1 = wb_robot_get_device("ps_1");
   WbDeviceTag ps_2 = wb_robot_get_device("ps_2");
   WbDeviceTag ps_3 = wb_robot_get_device("ps_3");

   
   wb_distance_sensor_enable(ds_left);
   wb_distance_sensor_enable(ds_right);

   
   wb_position_sensor_enable(ps_1,TIME_STEP);
   wb_position_sensor_enable(ps_2,TIME_STEP);
   wb_position_sensor_enable(ps_3,TIME_STEP);
   

    
   
  

  
   
  while (wb_robot_step(TIME_STEP) != -1) {
  
  double speed = -1.5;
  
  wb_motor_set_position(wheel_1, INFINITY);
  wb_motor_set_velocity(wheel_1, speed);
  
  wb_motor_set_position(wheel_2, INFINITY);
  wb_motor_set_velocity(wheel_2, speed);
  
  wb_motor_set_position(wheel_3, INFINITY);
  wb_motor_set_velocity(wheel_3 speed);

  
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}

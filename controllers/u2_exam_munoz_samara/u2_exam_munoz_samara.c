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
#include <webots/motor.h>
#include <webots/position_sensor.h>
#include <webots/distance_sensor.h>
#include <webots/keyboard.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIME_STEP 64


int disleft_value; 
int disright_value;

int vel = 3;
int turn_left = 0;
int turn_right = 0;

int gir_r = 0;
int gir_l = 0;

float dis_ml=0;
float dis_mr=0;

float pos1_value=0;
float pos2_value=0;
float pos3_value=0;

float posfinal = 0;

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
   
   WbDeviceTag disleft = wb_robot_get_device("ds_left");
   WbDeviceTag disright = wb_robot_get_device("ds_right");
   
   WbDeviceTag pos1 = wb_robot_get_device("ps_1");
   WbDeviceTag pos2 = wb_robot_get_device("ps_2");
   WbDeviceTag pos3 = wb_robot_get_device("ps_3");

   
   wb_distance_sensor_enable(disleft,TIME_STEP);
   wb_distance_sensor_enable(disright,TIME_STEP);

   
   wb_position_sensor_enable(pos1,TIME_STEP);
   wb_position_sensor_enable(pos2,TIME_STEP);
   wb_position_sensor_enable(pos3,TIME_STEP);
   
   wb_motor_set_position(wheel_1,INFINITY);
   wb_motor_set_position(wheel_2,INFINITY);
   wb_motor_set_position(wheel_3,INFINITY);

   
   
  while (wb_robot_step(TIME_STEP) != -1) {

/////////////////////CON DISTANCE SENSOR/////////////////////  
  
  disleft_value = wb_distance_sensor_get_value(disleft);
  disright_value = wb_distance_sensor_get_value(disright);
  
  wb_motor_set_velocity(wheel_1,-vel);
  wb_motor_set_velocity(wheel_2,vel);
  wb_motor_set_velocity(wheel_3,0);  
  
  dis_ml = (disleft_value)*(.2) / 65535; //distance measure left
  dis_mr = (disright_value)*(.2) / 65535; //distance measure right
  
  printf("Distance Value Left: %i\t",disleft_value);
  printf("dis_ml: %f \t",dis_ml);
  printf("dis_mr %f \t",dis_mr);
  printf("posfinal: %f",posfinal);
  
  
  
    ///////////////////////CON POSITION SENSOR////////////////

  pos1_value = wb_position_sensor_get_value(pos1);
  pos2_value = wb_position_sensor_get_value(pos2);
  pos3_value = wb_position_sensor_get_value(pos3);
  
  
  
  printf("pos1_Val:  %f\n",pos1_value);
  
  
  if(dis_ml <= 0.17 && dis_ml > dis_mr && turn_right == 0) {
    posfinal = pos1_value - 3.1416;
    turn_right = 1; 
    }
    
  if(turn_right == 1){
    if(pos1_value > posfinal){
     wb_motor_set_velocity(wheel_1,-vel);
     wb_motor_set_velocity(wheel_2,-vel);
     wb_motor_set_velocity(wheel_3,-vel);    
    }
    else{
    turn_right = 0;    
    }
    
  }
  
  
 
 
    
    
  
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}

//********************************************
// Draw bot for art drawing implemenation 
// consist of for loops which have fine tuned motor control
// motors contained in a specified header file
//****************************************************
#include "stm32l1xx.h"
#include "math.h"
#include "motor_header.h"
#include "system_clock.h"    


int main(void)
{  
	 uint16_t i=0,j=0;
	 uint16_t motor_delay=5;
	 uint16_t motor_delay_draw=10;
	
	//variables used to make it easier to change the amount of 
	// corner lenght , line length , or geometry of the shape being drawn
   uint16_t straight=300;
	 uint16_t straight_less = 200;
	 uint16_t r_big = 100;
	 uint16_t r_little = 50;
	 uint16_t turn=220;
	 uint16_t less_90 =200;
	 uint16_t more_90 =300;
	
  Motor motor_right; //RIGHT MOTOR
	Motor motor_left; //LEFT MOTOR


	if (SysTick_Config(SystemCoreClock / 1000)) { // SysTick 1 msec interrupts  
   while (1);                                  // Capture error              
 }

 	Motor_Init();  // initilozing the PB AND PC PINS FOR MOTOR
	motor_right.step = 0;        // right motor
	motor_right.totalSteps = 0;  //right motor
	
	motor_left.step = 0;        // left motor
	motor_left.totalSteps = 0;  //left motor
 
//****************************************************
// uncomment the below code between the /* */ to draw a perfect BOX
//******************************************
/* while (1)
	 {
				 for(i=0; i< straight; i++)
				 {
				 StepMotor_half_right(&motor_right); // half step stepper motor left
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); // half step stepper motor left
				 Delay (motor_delay); 
				 }
				 for(i=0; i<turn; i++)
				 {
				 StepMotor_half_right(&motor_right); // half step stepper motor left
				 Delay (motor_delay);
				 StepMotor_half_left_reverse(&motor_left); // half step stepper motor left
				 Delay (motor_delay); 
				 }
				  for(i=0; i<straight; i++)
				 {
				 StepMotor_half_right(&motor_right); // half step stepper motor left
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); // half step stepper motor left
				 Delay (motor_delay); 
				 }
				  for(i=0; i<turn; i++)
				 {
				 StepMotor_half_right(&motor_right); // half step stepper motor left
				 Delay (motor_delay);
				 StepMotor_half_left_reverse(&motor_left); // half step stepper motor left
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight; i++)
				 {
				 StepMotor_half_right(&motor_right); // half step stepper motor left
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); // half step stepper motor left
				 Delay (motor_delay); 
				 }
				 for(i=0; i<turn; i++)
				 {
				 StepMotor_half_right(&motor_right); // half step stepper motor left
				 Delay (motor_delay);
				 StepMotor_half_left_reverse(&motor_left); // half step stepper motor left
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight; i++)
				 {
				 StepMotor_half_right(&motor_right); // half step stepper motor left
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); // half step stepper motor left
				 Delay (motor_delay); 
				 }
				 break;
	 }// end of while loop */
	 
//******************************************************************
//** By changing the timings you can draw any shape one desires
// and adding more for loops 
// as it stand it draws a ballon
//**********************************************************
	 while (1)
	 {
		   for(i=0; i<2190; i++)
				 {
				 StepMotor_half_right(&motor_right); // BIG PERFECT CIRCLE 
				 Delay (motor_delay_draw);
				 }
				 for(i=0; i<turn; i++)    
				 {
				 StepMotor_half_right_reverse(&motor_right);   //90 after circle 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight_less; i++)
				 {
				 StepMotor_half_right(&motor_right);  //straight A
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<turn; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);   // 90 turn at A 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight_less; i++)
				 {
				 StepMotor_half_right(&motor_right);   // a - b 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<less_90; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);   // a - b 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight_less; i++) 
				 {
				 StepMotor_half_right_reverse(&motor_right);   // b- c
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<less_90; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);    //   1 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<r_little; i++)
				 {
				 StepMotor_half_right(&motor_right);   // r little 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<more_90; i++)
				 {
				 StepMotor_half_right(&motor_right);    //   2 
				 Delay (motor_delay);
				 StepMotor_half_left_reverse(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<r_big; i++)
				 {
				 StepMotor_half_right(&motor_right);   // r big 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<more_90; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);    //  3
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				  for(i=0; i<r_big; i++)
				 {
				 StepMotor_half_right(&motor_right);   // r big 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<more_90; i++)
				 {
				 StepMotor_half_right(&motor_right);    //   4
				 Delay (motor_delay);
				 StepMotor_half_left_reverse(&motor_left); 
				 Delay (motor_delay); 
				 }
				   for(i=0; i<r_big; i++)
				 {
				 StepMotor_half_right(&motor_right);   // r big 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<more_90; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);    //   5
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
			  	for( i=0; i<r_little; i++)
				 {
				 StepMotor_half_right(&motor_right);   // r big 
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<less_90; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);    //   5
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight_less; i++)
				 {
				 StepMotor_half_right(&motor_right);    //   5
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<turn; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);    // 90
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight; i++)
				 {
				 StepMotor_half_right(&motor_right);    //  5
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<turn; i++)
				 {
				 StepMotor_half_right_reverse(&motor_right);    //  straight90
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }
				 for(i=0; i<straight_less; i++)
				 {
				 StepMotor_half_right(&motor_right);    // straight  5
				 Delay (motor_delay);
				 StepMotor_half_left(&motor_left); 
				 Delay (motor_delay); 
				 }

				 
		break;
	 }
	 
	 
	 
	 
	 
	 
} //end main


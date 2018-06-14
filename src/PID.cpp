#include "PID.h"
#include<iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}


void PID::Init(double Kp_, double Ki_, double Kd_)
{
  /*
  * Initialize PID.
  */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_; 

  p_error = 0;
  i_error = 0;
  d_error = 0; 
}


void PID::UpdateError(double cte)
{
  /*
  * Update the PID error variables given cross track error.
  */

  // Derivative Error
  d_error = cte - p_error;

  // Proportional Error
  p_error = cte;

  // Integral Error
  i_error += cte;

  //cout<<p_error<<" , "<<i_error<<" , "<<d_error;
}


/*
* Calculate the total PID error.
*/
double PID::TotalError()
{
  return ((-Kp) * p_error) - (Ki * i_error) - (Kd * d_error);
}


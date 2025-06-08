#ifndef _MOVE_H_
#define _MOVE_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "pros/motor_group.hpp"

enum MotorPort {
    LF = 2,
    LM = -4,
    LL = 9,
    RF = 3,
    RM = -5,
    RL = -10,
};

void moveForward(int vel); 

#endif // _MOVE_H_
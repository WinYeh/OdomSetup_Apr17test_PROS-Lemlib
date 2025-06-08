#include "move.h"

pros::MotorGroup left_mg({LF, LM, LL});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup right_mg({RF, RM, RL});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

void moveForward(int vel) {
    pros::MotorGroup left_mg({LF, LM, LL});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
    pros::MotorGroup right_mg({RF, RM, RL});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

    left_mg.move_velocity(vel);
    right_mg.move_velocity(vel);
}
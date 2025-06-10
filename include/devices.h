#ifndef _DEVICES_H_
#define _DEVICES_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "pros/imu.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
// Add other PROS headers as needed for your devices

// ...existing code...

enum devicesports
{
    // Chassis Motors
    Chassis_LF = 2,
    Chassis_LM = -4,
    Chassis_LL = 9,
    Chassis_RF = 3,
    Chassis_RM = -5,
    Chassis_RL = -10,
    
    // Intake Motors
    Intake_Upper = 4, 
    Intake_Lower = -6, 
    Intake_Mid = 4,
};

enum buttonMap
{
    // Controller Buttons
    Button_A = pros::E_CONTROLLER_DIGITAL_A,
    Button_B = pros::E_CONTROLLER_DIGITAL_B,
    Button_X = pros::E_CONTROLLER_DIGITAL_X,
    Button_Y = pros::E_CONTROLLER_DIGITAL_Y,
    Button_L1 = pros::E_CONTROLLER_DIGITAL_L1,
    Button_L2 = pros::E_CONTROLLER_DIGITAL_L2,
    Button_R1 = pros::E_CONTROLLER_DIGITAL_R1,
    Button_R2 = pros::E_CONTROLLER_DIGITAL_R2,
    Button_Up = pros::E_CONTROLLER_DIGITAL_UP,
    Button_Down = pros::E_CONTROLLER_DIGITAL_DOWN,
    Button_Left = pros::E_CONTROLLER_DIGITAL_LEFT,
    Button_Right = pros::E_CONTROLLER_DIGITAL_RIGHT,   
};

// learn prama region from https://learn.microsoft.com/en-us/cpp/preprocessor/region-endregion?view=msvc-170

#pragma region Essential Devices
    extern pros::Controller master; // Controller instance
#pragma endregion deviceMap

#pragma region Drivetrain
    extern pros::Motor left_m1;    // Creates Left motor1
    extern pros::Motor left_m2;    // Creates Left motor2
    extern pros::Motor left_m3;    // Creates Left motor3
    extern pros::Motor right_m1;   // Creates Right motor1
    extern pros::Motor right_m2;   // CreatesRight motor2
    extern pros::Motor right_m3;   // Creates Right motor3

    extern pros::MotorGroup left_mg;    // Creates left motor group
    extern pros::MotorGroup right_mg;   // Creates right motor group
#pragma endreigion Drivetrain

#pragma region OdomSetpUp

    // drivetrain settings
    extern lemlib::Drivetrain drivetrain; // Drivetrain instance

    // Odom Sensors 
    extern pros::Imu imu1;  // Creates an IMU on port 3
    extern pros::Rotation vertic_encoder; // Vertical encoder
    extern pros::Rotation horiz_encoder;  // Horizontal encoder
    extern lemlib::TrackingWheel horizontal_track; // Horizontal tracking wheel
    extern lemlib::TrackingWheel vertical_track;   // Vertical tracking wheel
    extern lemlib::OdomSensors sensors; // Odom sensors instance

    extern lemlib::Chassis chassis; // Chassis instance

#pragma endregion OdomSetpUp

#endif // _DEVICES_H_ 
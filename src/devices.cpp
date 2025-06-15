#include "devices.h"
#include "pros/abstract_motor.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep

#pragma region Essential Devices
pros::Controller master(pros::E_CONTROLLER_MASTER); // Controller instance  
#pragma endregion Essential Devices

#pragma region Drivetrain   
pros::Motor left_m1(Chassis_LF);    // Left motor1
pros::Motor left_m2(Chassis_LM);   // Left motor2
pros::Motor left_m3(Chassis_LL);    // Left motor3
pros::Motor right_m1(Chassis_RF);   // Right motor1
pros::Motor right_m2(Chassis_RM);  // Right motor2
pros::Motor right_m3(Chassis_RL);   // Right motor3

pros::MotorGroup left_mg({Chassis_LF, Chassis_LM, Chassis_LL}
                        , pros::MotorGearset::blue);    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup right_mg({Chassis_RF, Chassis_RM, Chassis_RL}
                        , pros::MotorGearset::blue);  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

#pragma endregion Drivetrain

#pragma region Intake
pros::Motor intake_upper(Intake_Upper, pros::MotorGearset::blue); // Upper intake motor
pros::Motor intake_lower(Intake_Lower, pros::MotorGearset::blue); // Lower intake motor
pros::Motor intake_roller(Intake_Mid, pros::MotorGearset::blue); // Mid intake motor
#pragma endregion Intake


#pragma region LemlibSetUp 

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_mg, // left motor group
	&right_mg, // right motor group
	10.9, // 10.9 inch track width
	lemlib::Omniwheel::NEW_325, // using new 3"25 omnis
	450, // drivetrain rpm is 360
	2 // horizontal drift is 2 
);

// Odom Sensors 
pros::Imu imu1(3);  // Creates an IMU on port 3
pros::Rotation vertic_encoder(-4);
pros::Rotation horiz_encoder(5);

lemlib::TrackingWheel horizontal_track(&horiz_encoder, lemlib::Omniwheel::NEW_2, 0.35); 
lemlib::TrackingWheel vertical_track(&vertic_encoder, lemlib::Omniwheel::NEW_2, 0.9);  
lemlib::OdomSensors sensors(&vertical_track, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_track, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu1 // inertial sensor
);


// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in degrees
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in degrees
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

#pragma endregion LemlibSetUp

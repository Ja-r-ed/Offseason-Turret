// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "utilities/ICSparkMax.h"
#include "Constants.h"
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>

class SubShooter : public frc2::SubsystemBase {
 public:
  SubShooter();

  frc2::CommandPtr SetShooterSpeed(double speed);
  frc2::CommandPtr SpinUpShooter;
  frc2::CommandPtr StopShooter;

  

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  constexpr double GEAR_RATIO = 1/2;
  ICSparkMax _shooterMotor1{canid::SHOOTER_MOTOR_1, 30_A};
  ICSparkMax _shooterMotor2{canid::SHOOTER_MOTOR_2, 30_A};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

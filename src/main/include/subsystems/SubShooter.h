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
  static SubShooter& GetInstance() {
    static SubShooter inst;
    return inst;
  }
  frc2::CommandPtr SetShooterSpeed(units::turns_per_second_t speed);
  frc2::CommandPtr SpinUpShooter();
  frc2::CommandPtr StopShooter();

  

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  double GEAR_RATIO = 1/2;
  ICSparkMax _shooterMotor1{canid::SHOOTER_MOTOR_1, 30_A};
  ICSparkMax _shooterMotor2{canid::SHOOTER_MOTOR_2, 30_A};

  double P = 0;
  double I = 0;
  double D = 0;
  units::turns_per_second_t SHOOTER_SPEED = 1_tps;

  rev::spark::SparkBaseConfig _shooterMotor1Config;
  rev::spark::SparkBaseConfig _shooterMotor2Config;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

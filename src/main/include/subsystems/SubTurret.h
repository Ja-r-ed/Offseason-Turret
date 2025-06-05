// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "utilities/ICSparkMax.h"
#include "Constants.h"

class SubTurret : public frc2::SubsystemBase {
 public:
  SubTurret();
  static SubTurret& GetInstance() {
    static SubTurret inst;
    return inst;
  }

  double GetTurretAngle(double encoder1, double encoder2);



  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  ICSparkMax _turretMotor{canid::TURRET_MOTOR, 30_A};
  rev::spark::SparkBaseConfig _turretMotorConfig;

  double P = 0;
  double I = 0;
  double D = 0;
  
  static constexpr double ENCODER1_RATIO = 0.17391304347; //20/115
  static constexpr double ENCODER2_RATIO = 0.19130434782; //22/115
  static constexpr double GEAR_RATIO = 0.02173913043; //1/46
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

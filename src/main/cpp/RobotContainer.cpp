// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/Commands.h>
#include "subsystems/SubVision.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Filesystem.h>
#include <wpinet/WebServer.h>
#include "subsystems/SubShooter.h"
#include "subsystems/SubHood.h"
RobotContainer::RobotContainer() {
  wpi::WebServer::GetInstance().Start(5800, frc::filesystem::GetDeployDirectory());
  SubVision::GetInstance();

  // Trigger Bindings
  ConfigureBindings();

}

void RobotContainer::ConfigureBindings() {
  _driverController.A().OnTrue(SubShooter::GetInstance().SpinUpShooter());
  _driverController.B().OnTrue(SubShooter::GetInstance().StopShooter());
  _driverController.X().OnTrue(SubHood::GetInstance().StowHood());
  _driverController.Y().OnTrue(SubHood::GetInstance().SetHoodPosition(90_deg));
}

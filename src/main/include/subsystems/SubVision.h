
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Pose3d.h>
#include <frc/geometry/Transform3d.h>
#include <frc/apriltag/AprilTagFieldLayout.h>
#include <frc/apriltag/AprilTagFields.h>
#include <photon/PhotonCamera.h>
#include <photon/simulation/VisionSystemSim.h>
#include <photon/PhotonPoseEstimator.h>
#include <frc/Filesystem.h>
#include <wpi/interpolating_map.h>

class SubVision : public frc2::SubsystemBase {
public:
  SubVision();
  static SubVision& GetInstance() {
    static SubVision inst;
    return inst;
  }

  void Periodic() override;

  void SimulationPeriodic() override;

 private:
 
};

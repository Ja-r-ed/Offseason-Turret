#pragma once
#include <frc2/command/Commands.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <units/angle.h>

namespace cmd {
    frc2::CommandPtr AimTurret(units::degree_t TurretAngle, units::degree_t HoodAngle);
    frc2::CommandPtr AimAndShoot(units::degree_t TurretAngle, units::degree_t HoodAngle);
}
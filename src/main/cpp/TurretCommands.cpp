
#include "TurretCommands.h"
#include "subsystems/SubHood.h"
#include "subsystems/SubShooter.h"
#include "subsystems/SubTurret.h"

namespace cmd {
    frc2::CommandPtr AimTurret(units::degree_t TurretAngle, units::degree_t HoodAngle) {
        return SubTurret::GetInstance().SetTurretAngle(TurretAngle)
        .AndThen(SubHood::GetInstance().SetHoodPosition(HoodAngle));
    }

    frc2::CommandPtr AimAndShoot(units::degree_t TurretAngle, units::degree_t HoodAngle) {
        return SubShooter::GetInstance().SpinUpShooter()
        .AndThen(AimTurret(TurretAngle, HoodAngle)).Until([] {return SubShooter::GetInstance().IsAtSpeed();});
        // .AndThen(Shoot)????????????? dont know if there is a feeder
    }
}
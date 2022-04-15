#pragma once

class Constants
{
    public:
        static const int FLM = 2;   
        static const int RLM = 1;
        static const int FRM = 4;
        static const int RRM = 3;

        static const int shooterLeft = 5;
        static const int shooterRight = 6;

        static const int bigMeteringWheel = 14;

        static const int intakeMotor = 7;

        static const int PH = 30;

        static const int intakeForwardRight = 0;
        static const int intakeBackwardRight = 1;

        static const int intakeForwardLeft = 2;
        static const int intakeBackwardLeft = 3;

        static const int meterMotorRight = 12;
        static const int meterMotorLeft = 9;

        static const int staticPort = 10; // static is reserved word...
        static const int dynamicPort = 11;

        static const int climberPneumaticUp = 4;
        static const int climberPneumaticDown = 5;

        static constexpr double horizontalLimeMax = 6;
        static constexpr double horizontalLimeMin = -6;
        static constexpr double verticalLimeMax = 10;
        static constexpr double verticalLimeMin = 0;

        static constexpr double shooterP = 15e-5;
        static constexpr double shooterI = 1e-6;
        static constexpr double shooterD = 10;
        static constexpr double shooterFF = .000015;

        // left p = .1058
        // these should all be doubles...
        // but need to test what happens when they are doubles, so Mat is not changing now

        //Luke's new PID constants
        double leftP = 6e-5;
        double leftI = 1e-6;
        double leftD = 0;
        double leftIz = 0;
        double leftFF = 0.000015;
        double leftMaxOutput = 1.0;
        double leftMinOutput = -1.0;

        const double leftMaxRPM = 5700;

        double rightP = 6e-5;
        double rightI = 1e-6;
        double rightD = 0;
        double rightIz = 0;
        double rightFF = .000015;
        double rightMaxOutput = 1.0;
        double rightMinOutput = -1.0;

        const double rightMaxRPM = 5700;

        //luke's new new PID constants for Smart Motion
        double leftP = 5e-5;
        double leftI = 1e-6;
        double leftD = 0;
        double leftIz = 0;
        double leftFF = 0.000156;
        double leftMaxOutput = 1.0;
        double leftMinOutput = -1.0;

        //constants for Smart Motion
        double leftMaxVel = 2000;
        double leftMinVel = 0;
        double leftMaxAcc = 1500;
        double leftAllErr = 0;

        const double leftMaxRPM = 5700;

        double rightP = 6e-5;
        double rightI = 1e-6;
        double rightD = 0;
        double rightIz = 0;
        double rightFF = .000015;
        double rightMaxOutput = 1.0;
        double rightMinOutput = -1.0;

        //constants for Smart Motion
        double rightMaxVel = 2000;
        double rightMinVel = 0;
        double rightMaxAcc = 1500;
        double rightAllErr = 0;

        const double rightMaxRPM = 5700;

};
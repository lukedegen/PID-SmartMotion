#include "DriveTrain.h"

DriveTrain::DriveTrain()
{
    m_FLM.RestoreFactoryDefaults();
    m_FRM.RestoreFactoryDefaults();
    m_RLM.RestoreFactoryDefaults();
    m_RRM.RestoreFactoryDefaults();

    m_FLM.SetInverted(true);

    m_RRM.Follow(m_FRM);
    m_RLM.Follow(m_FLM);

    //Luke's new PID code for drivetrain
    m_FLMPID.SetP(Constants::leftP);        
    m_FLMPID.SetI(Constants::leftI);
    m_FLMPID.SetD(Constants::leftD);
    m_FLMPID.SetIZone(Constants::leftIz);        
    m_FLMPID.SetFF(Constants::leftFF);
    m_FLMPID.SetOutputRange(Constants::leftMinOutput, Constants::leftMaxOutput);



    m_RLMPID.SetP(Constants::leftP);        
    m_RLMPID.SetI(Constants::leftI);
    m_RLMPID.SetD(Constants::leftD);
    m_RLMPID.SetIZone(Constants::rightIz);      
    m_RLMPID.SetFF(Constants::leftFF);
    m_RLMPID.SetOutputRange(Constants::rightMinOutput, Constants::rightMaxOutput);

    m_FRMPID.SetP(Constants::rightP);        
    m_FRMPID.SetI(Constants::rightI);
    m_FRMPID.SetD(Constants::rightD);
    m_FRMPID.SetIZone(Constants::leftIz);       
    m_FRMPID.SetFF(Constants::rightFF);
    m_FRMPID.SetOutputRange(Constants::leftMinOutput, Constants::leftMaxOutput);

    m_RRMPID.SetP(Constants::rightP);        
    m_RRMPID.SetI(Constants::rightI);
    m_RRMPID.SetD(Constants::rightD); 
    m_RRMPID.SetIZone(Constants::rightIz);        
    m_RRMPID.SetFF(Constants::rightFF);
    m_RRMPID.SetOutputRange(Constants::rightMinOutput, Constants::rightMaxOutput);


    //Even more janky code for Smart Motion whatever the heck that is we'll see if it works
    //Luke's new PID code for drivetrain but this one is for Smart Motion
    m_FLMPID.SetP(Constants::leftP);        
    m_FLMPID.SetI(Constants::leftI);
    m_FLMPID.SetD(Constants::leftD);
    m_FLMPID.SetIZone(Constants::leftIz);        
    m_FLMPID.SetFF(Constants::leftFF);
    m_FLMPID.SetOutputRange(Constants::leftMinOutput, Constants::leftMaxOutput);



    m_RLMPID.SetP(Constants::leftP);        
    m_RLMPID.SetI(Constants::leftI);
    m_RLMPID.SetD(Constants::leftD);
    m_RLMPID.SetIZone(Constants::rightIz);      
    m_RLMPID.SetFF(Constants::leftFF);
    m_RLMPID.SetOutputRange(Constants::rightMinOutput, Constants::rightMaxOutput);

    m_FRMPID.SetP(Constants::rightP);        
    m_FRMPID.SetI(Constants::rightI);
    m_FRMPID.SetD(Constants::rightD);
    m_FRMPID.SetIZone(Constants::leftIz);       
    m_FRMPID.SetFF(Constants::rightFF);
    m_FRMPID.SetOutputRange(Constants::leftMinOutput, Constants::leftMaxOutput);

    m_RRMPID.SetP(Constants::rightP);        
    m_RRMPID.SetI(Constants::rightI);
    m_RRMPID.SetD(Constants::rightD); 
    m_RRMPID.SetIZone(Constants::rightIz);        
    m_RRMPID.SetFF(Constants::rightFF);
    m_RRMPID.SetOutputRange(Constants::rightMinOutput, Constants::rightMaxOutput);

    //Still Smart Motion stuff that Luke has no clue what it is

    m_FLMPID.SetSmartMotionMaxVelocity(Constants::leftMaxVel);
    m_FLMPID.SetSmartMotionMinOutputVelocity(Constants::leftMinVel);
    m_FLMPID.SetSmartMotionMaxAccel(Constants::leftMaxAcc);
    m_FLMPID.SetSmartMotionAllowedClosedLoopError(Constants::leftAllErr);

    m_RLMPID.SetSmartMotionMaxVelocity(Constants::rightMaxVel);
    m_RLMPID.SetSmartMotionMinOutputVelocity(Constants::rightMinVel);
    m_RLMPID.SetSmartMotionMaxAccel(Constants::rightMaxAcc);
    m_RLMPID.SetSmartMotionAllowedClosedLoopError(Constants::rightAllErr);

    m_FRMPID.SetSmartMotionMaxVelocity(Constants::leftMaxVel);
    m_FRMPID.SetSmartMotionMinOutputVelocity(Constants::leftMinVel);
    m_FRMPID.SetSmartMotionMaxAccel(Constants::leftMaxAcc);
    m_FRMPID.SetSmartMotionAllowedClosedLoopError(Constants::leftAllErr);

    m_RRMPID.SetSmartMotionMaxVelocity(Constants::rightMaxVel);
    m_RRMPID.SetSmartMotionMinOutputVelocity(Constants::rightMinVel);
    m_RRMPID.SetSmartMotionMaxAccel(Constants::rightMaxAcc);
    m_RRMPID.SetSmartMotionAllowedClosedLoopError(Constants::rightAllErr);



    //here is some jank code Luke wrote to try and get ramp rate to work
   if( m_FRM.SetClosedLoopRampRate(0) != rev::REVLibError::kOk){
       frc::SmartDashboard::PutString("Ramp Rate", "Error");
   }
    m_FLM.SetClosedLoopRampRate(0);
    m_FRM.SetClosedLoopRampRate(0);
    m_RRM.SetClosedLoopRampRate(0);
    m_RLM.SetClosedLoopRampRate(0);
    
    //This should in theory display what the ramp rate is
    frc::SmartDashboard::PutString("Ramp Rate", m_FRM.GetClosedLoopRampRate());


    m_diffDrive.SetDeadband(.15);
}

/*DriveTrain::~DriveTrain()
{

}

void DriveTrain::drive(double a1, double a2)
{
    m_diffDrive.ArcadeDrive(a1, a2);
}

void DriveTrain::tankDrive(double leftSpeed, double rightSpeed){
    m_diffDrive.TankDrive(leftSpeed, rightSpeed);
}

double DriveTrain::getLeftEncoderValue(){
    //std::cout << m_FLMEncoder.GetPosition() << std::endl;
    return m_FLMEncoder.GetPosition();
}

double DriveTrain::getRightEncoderValue(){
   // std::cout << m_FRMEncoder.GetPosition() << std::endl;
    return m_FRMEncoder.GetPosition();
}

void DriveTrain::resetEncoder(){
    m_FLMEncoder.SetPosition(0);
    m_FRMEncoder.SetPosition(0);
    m_RLMEncoder.SetPosition(0);
    m_RRMEncoder.SetPosition(0);
}

double DriveTrain::getAverageEncoder()
{
    return (m_FLMEncoder.GetPosition() + m_FRMEncoder.GetPosition()) / 2;
}

void DriveTrain::coastMode()
{
    // set coast mode somehow
    m_FRM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_FLM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_RRM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_RLM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void DriveTrain::brakeMode()
{
    // set brake mode somehow
   m_FRM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   m_FLM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   m_RRM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   m_RLM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}*/
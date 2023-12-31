#include "RaspiSPI.h"
#include "WarpDriver.h"

#include <iostream>

int main(int argc, char *argv[]) {

  if (gpioInitialise() < 0) {
    return 1
  };

  RaspiSPI rspi = RaspiSPI(17, 22, 27);
  WarpDriver motor =
      WarpDriver(&rspi, WarpDriver::MotorType::THREE_PHASE_BLDC, 7, 100'000,
                 WarpDriver::CalibrationData{0, 0, 0});

  std::cout << "getHardwareInfo: 0x" << std::hex << motor.getHardwareInfo()
            << std::dec << std::endl;

  std::cout << "getAdcRawDataI0: " << motor.getAdcRawDataI0() << std::endl;
  std::cout << "getAdcRawDataI1: " << motor.getAdcRawDataI1() << std::endl;
  std::cout << "getAdcRawDataVM: " << motor.getAdcRawDataVM() << std::endl;
  std::cout << "getIux: " << motor.getIux() << std::endl;
  std::cout << "getIv: " << motor.getIv() << std::endl;
  std::cout << "getIwy: " << motor.getIwy() << std::endl;
  std::cout << "getTorque: " << motor.getTorque() << std::endl;
  std::cout << "getVelocity: " << motor.getVelocity() << std::endl;
  std::cout << "getPostion: " << motor.getPostion() << std::endl;
  std::cout << "getStatus: "
            << motor.getStatus(WarpDriver::StatusMask::ADC_AENC_CLIPPED)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::ADC_I_CLIPPED)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::AENC_N) << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::ENC2_N) << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::ENC_N) << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::IPARK_CIRLIM_LIMIT_U_D)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::IPARK_CIRLIM_LIMIT_U_Q)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::IPARK_CIRLIM_LIMIT_U_R)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::NOT_PLL_LOCKED)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_ID_ERRSUM_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_ID_OUTPUT_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_ID_TARGET_DDT_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_ID_TARGET_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_IQ_ERRSUM_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_IQ_OUTPUT_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_IQ_TARGET_DDT_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PID_IQ_TARGET_LIMIT)
            << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PWM_MAX) << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::PWM_MIN) << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::REF_SW_H) << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::REF_SW_L) << std::endl;
  std::cout << motor.getStatus(WarpDriver::StatusMask::REF_SW_R) << std::endl;

  gpioTerminate();

  return 0;
}

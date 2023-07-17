#include "RaspiSPI.h"
#include "WarpDriver.h"

#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {

  bcm2835_set_debug(1);
  bcm2835_init();

  bcm2835_gpio_fsel(RPiGPIOPin::RPI_BPLUS_GPIO_J8_11, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(RPiGPIOPin::RPI_BPLUS_GPIO_J8_13, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(RPiGPIOPin::RPI_BPLUS_GPIO_J8_15, BCM2835_GPIO_FSEL_OUTP);

  {
    RaspiSPI rspi = RaspiSPI(RPiGPIOPin::RPI_BPLUS_GPIO_J8_11,
                             RPiGPIOPin::RPI_BPLUS_GPIO_J8_15,
                             RPiGPIOPin::RPI_BPLUS_GPIO_J8_13);
    WarpDriver motor =
        WarpDriver(&rspi, WarpDriver::MotorType::THREE_PHASE_BLDC, 7, 100'000,
                   WarpDriver::CalibrationData{0, 0, 0});

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
    std::cout << motor.getStatus(
                     WarpDriver::StatusMask::PID_ID_TARGET_DDT_LIMIT)
              << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::PID_ID_TARGET_LIMIT)
              << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::PID_IQ_ERRSUM_LIMIT)
              << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::PID_IQ_OUTPUT_LIMIT)
              << std::endl;
    std::cout << motor.getStatus(
                     WarpDriver::StatusMask::PID_IQ_TARGET_DDT_LIMIT)
              << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::PID_IQ_TARGET_LIMIT)
              << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::PWM_MAX) << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::PWM_MIN) << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::REF_SW_H) << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::REF_SW_L) << std::endl;
    std::cout << motor.getStatus(WarpDriver::StatusMask::REF_SW_R) << std::endl;
  }
  bcm2835_close();
  return 0;
}
#include "RaspiSPI.h"
#include "WarpDriver.h"

int main(int argc, char *argv[]) {
  bcm2835_set_debug(1);
  bcm2835_init();

  RaspiSPI rspi = RaspiSPI(0, 1, 2);
  WarpDriver motor = WarpDriver(rspi, WarpDriver::MotorType::THREE_PHASE_BLDC, 7, 100'000,
                     WarpDriver::CalibrationData{0, 0, 0});
  motor.getTorque();

  bcm2835_close();
  return 0;
}
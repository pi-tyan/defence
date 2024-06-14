#include <BNO.h>
#include <Adafruit_BNO055.h>
#include <Wire.h>
#include <Ticker.h>

{
 int8_t temp = bno.getTemp();
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");

  bno.setExtCrystalUse(false);

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
  bno055ticker.attach_ms(BNO055interval, get_bno055_data);
}

void get_bno055_data(void)
{
  Possible vector values can be:
  VECTOR_ACCELEROMETER - m/s^2
  VECTOR_MAGNETOMETER  - uT
  VECTOR_GYROSCOPE     - rad/s
  VECTOR_EULER         - degrees
  VECTOR_LINEARACCEL   - m/s^2
  VECTOR_GRAVITY       - m/s^2
  
  uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  Serial.print("CALIB Sys:");
  Serial.print(system, DEC);
  Serial.print(", Gy");
  Serial.print(gyro, DEC);
  Serial.print(", Ac");
  Serial.print(accel, DEC);
  Serial.print(", Mg");
  Serial.print(mag, DEC);
  
  imu::Vector<3> gyroscope = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  Serial.print(" 　Gy_xyz:");
  Serial.print(gyroscope.x());
  Serial.print(", ");
  Serial.print(gyroscope.y());
  Serial.print(", ");
  Serial.print(gyroscope.z());
  
  imu::Vector<3> accelermetor = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  Serial.print(" 　Ac_xyz:");
  Serial.print(accelermetor.x());
  Serial.print(", ");
  Serial.print(accelermetor.y());
  Serial.print(", ");
  Serial.print(accelermetor.z());
  
  imu::Vector<3> magnetmetor = bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
  Serial.print(" 　Mg_xyz:");
  Serial.print(magnetmetor .x());
  Serial.print(", ");
  Serial.print(magnetmetor .y());
  Serial.print(", ");
  Serial.print(magnetmetor .z());
  
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  Serial.print(" 　DIR_xyz:");
  Serial.print(euler.x());
  Serial.print(", ");
  Serial.print(euler.y());
  Serial.print(", ");
  Serial.print(euler.z());

    imu::Quaternion quat = bno.getQuat();
    Serial.print("qW: ");
    Serial.print(quat.w(), 4);
    Serial.print(" qX: ");
    Serial.print(quat.x(), 4);
    Serial.print(" qY: ");
    Serial.print(quat.y(), 4);
    Serial.print(" qZ: ");
    Serial.print(quat.z(), 4);
    Serial.print("\t\t");
  

  Serial.println();
}

void loop(void)
{
}
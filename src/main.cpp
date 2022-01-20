#include <Arduino.h>
#include "CBluetoothCommunication.h"

CBluetoothCommunication mBluetoothCommunication;

void setup() {
  // start serial communication
  Serial.begin(115200);

  // initialize bluetooth communication
  mBluetoothCommunication.init();
}

void loop() {
  CSensorData mSensorData(80.0f, 125.37f, 1999.99f);
  delay(5000);

  // update sensor data if device is connected
  // the data is transferred as soon as the device requests new data
  if(mBluetoothCommunication.getConnectionState()) {
    mBluetoothCommunication.setSensorData(mSensorData);
  }
}
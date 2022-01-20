#include "CCharCallbackMachineControl.h"

// callback method: process machine control events from smartphone
void CCharCallbackMachineControl::onWrite(BLECharacteristic* pCharacteristic) {
    uint8_t* receivedByteArray = pCharacteristic->getData();

    // initialize new CMachineControlData object with receivedByteArray
    CMachineControlData mMachineControlData(receivedByteArray);

    // process transferred instruction
    switch (mMachineControlData.mInstruction)
    {
    case EInstructions::SET_SALT_CONCENTRATION:
        // new salt concentration is stored in mMachineControlData.mSaltConcentration
        Serial.print("new salt concentration: ");
        Serial.println(mMachineControlData.mSaltConcentration);
        break;

    case EInstructions::RESET_SALT_AMOUNT:
        Serial.println("reset salt amount");
        break;
    
    default:
        Serial.println("Bluetooth-Fehler: empfangene Daten nicht dekodierbar!");
        break;
    }
}
#ifndef _MAX7219_H_
#define _MAX7219_H_

#include <Arduino.h>
#include <SPI.h>

//Decode Modes
#define MAX7219_NO_DECODE 0x0
#define MAX7219_DECODE_0 0x1
#define MAX7219_DECODE_0_TO_3 0xF
#define MAX7219_DECODE_ALL 0xFF

//Scan Limits
#define MAX7219_SCAN_LIMIT_0_ONLY 0x0
#define MAX7219_SCAN_LIMIT_0_TO_1 0x1
#define MAX7219_SCAN_LIMIT_0_TO_2 0x2
#define MAX7219_SCAN_LIMIT_0_TO_3 0x3
#define MAX7219_SCAN_LIMIT_0_TO_4 0x4
#define MAX7219_SCAN_LIMIT_0_TO_5 0x5
#define MAX7219_SCAN_LIMIT_0_TO_6 0x6
#define MAX7219_SCAN_LIMIT_0_TO_7 0x7

//Intensity
#define MAX7219_INTENSITY_1_32 0x0
#define MAX7219_INTENSITY_3_32 0x1
#define MAX7219_INTENSITY_5_32 0x2
#define MAX7219_INTENSITY_7_32 0x3
#define MAX7219_INTENSITY_9_32 0x4
#define MAX7219_INTENSITY_11_32 0x5
#define MAX7219_INTENSITY_13_32 0x6
#define MAX7219_INTENSITY_15_32 0x7
#define MAX7219_INTENSITY_17_32 0x8
#define MAX7219_INTENSITY_19_32 0x9
#define MAX7219_INTENSITY_21_32 0xA
#define MAX7219_INTENSITY_23_32 0xB
#define MAX7219_INTENSITY_25_32 0xC
#define MAX7219_INTENSITY_27_32 0xD
#define MAX7219_INTENSITY_29_32 0xE
#define MAX7219_INTENSITY_31_32 0xF

//Shutdown
#define MAX7219_SHUTDOWN_ENABLED 0x0
#define MAX7219_SHUTDOWN_NORMAL_OPERATION 0x1

//Display test
#define MAX7219_DISPLAY_TEST_DISABLED 0x0
#define MAX7219_DISPLAY_TEST_ENABLED 0x1

//Digit values
#define MAX7219_DIGIT_VALUE_0 0x0
#define MAX7219_DIGIT_VALUE_1 0x1
#define MAX7219_DIGIT_VALUE_2 0x2
#define MAX7219_DIGIT_VALUE_3 0x3
#define MAX7219_DIGIT_VALUE_4 0x4
#define MAX7219_DIGIT_VALUE_5 0x5
#define MAX7219_DIGIT_VALUE_6 0x6
#define MAX7219_DIGIT_VALUE_7 0x7
#define MAX7219_DIGIT_VALUE_8 0x8
#define MAX7219_DIGIT_VALUE_9 0x9
#define MAX7219_DIGIT_VALUE_DASH 0xA
#define MAX7219_DIGIT_VALUE_E 0xB
#define MAX7219_DIGIT_VALUE_H 0xC
#define MAX7219_DIGIT_VALUE_L 0xD
#define MAX7219_DIGIT_VALUE_P 0xE
#define MAX7219_DIGIT_VALUE_BLANK 0xF

//Addresses
#define MAX7219_DIG_0_ADDR 0x1
#define MAX7219_DIG_1_ADDR 0x2
#define MAX7219_DIG_2_ADDR 0x3
#define MAX7219_DIG_3_ADDR 0x4
#define MAX7219_DECODE_MODE_ADDR 0x9
#define MAX7219_INTENSITY_ADDR 0xA
#define MAX7219_SCAN_LIMIT_ADDR 0xB
#define MAX7219_SHUTDOWN_ADDR 0xC
#define MAX7219_DISPLAY_TEST_ADDR 0xF

class MAX7219 {
  private:
    uint8_t loadPin;

    uint8_t scanLimit;
    uint8_t intensity;

    bool isShutdown;
    bool isTestModeEnabled;

    uint8_t GetDigit(uint8_t val);
    void BeginTransaction();
    void EndTransaction();
    void Write(uint8_t addr, uint8_t data);
  public:
    MAX7219(uint8_t loadPin, uint8_t scanLimit, uint8_t intensity);

    void DisableTestMode();
    void EnableTestMode();

    void Shutdown();
    void EnableNormalOperation();

    void SetScanLimit(uint8_t scanLimit);
    void SetIntensity(uint8_t intensity);

    void SetDigit(uint8_t digitAddr, uint8_t digitValue);

    bool IsTestModeEnabled() const;
    bool IsShutdown() const;

    uint8_t GetScanLimit() const;
    uint8_t GetIntensity() const;
};

#endif
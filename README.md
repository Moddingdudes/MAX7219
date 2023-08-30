# MAX7219

## A simple library to interface with the MAX7219 multiplexer and LED driver

### Constructor
```cpp
MAX7219(uint8_t loadPin, uint8_t scanLimit, uint8_t intensity);
```

### Enable/Disable Functions
```cpp
void DisableTestMode();
void EnableTestMode();
void Shutdown();
void EnableNormalOperation();
```

### Getters
```cpp
bool IsTestModeEnabled() const;
bool IsShutdown() const;
uint8_t GetScanLimit() const;
uint8_t GetIntensity() const;
```

### Setters
```cpp
void SetScanLimit(uint8_t scanLimit);
void SetIntensity(uint8_t intensity);
void SetDigit(uint8_t digitAddr, uint8_t digitValue);
```

### Defines
```cpp
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
```

### Digit Decoder Values
The MAX7219 has a built in BCD decoder. This library uses the decoder by default and you can get the digit you would like to display by using the below values. There are also defines to help with this.
| Digit | Hexadecimal | Define |
| --- | --- | --- |
| `0` | 0x0 | MAX7219_DIGIT_VALUE_0 |
| `1` | 0x1 | MAX7219_DIGIT_VALUE_1 |
| `2` | 0x2 | MAX7219_DIGIT_VALUE_2 |
| `3` | 0x3 | MAX7219_DIGIT_VALUE_3 |
| `4` | 0x4 | MAX7219_DIGIT_VALUE_4 |
| `5` | 0x5 | MAX7219_DIGIT_VALUE_5 |
| `6` | 0x6 | MAX7219_DIGIT_VALUE_6 |
| `7` | 0x7 | MAX7219_DIGIT_VALUE_7 |
| `8` | 0x8 | MAX7219_DIGIT_VALUE_8 |
| `9` | 0x9 | MAX7219_DIGIT_VALUE_9 |
| `-` | 0xA | MAX7219_DIGIT_VALUE_DASH |
| `E` | 0xB | MAX7219_DIGIT_VALUE_E |
| `H` | 0xC | MAX7219_DIGIT_VALUE_H |
| `L` | 0xD | MAX7219_DIGIT_VALUE_L |
| `P` | 0xE | MAX7219_DIGIT_VALUE_P |
| `BLANK` | 0xF | MAX7219_DIGIT_VALUE_BLANK |

*Example:*
```cpp
SetDigit(MAX7219_DIGIT_VALUE_0, MAX7219_DIGIT_VALUE_8); //Set the 0th digit to 8
SetDigit(MAX7219_DIGIT_VALUE_0, 8); //Set the 0th digit to 8
```

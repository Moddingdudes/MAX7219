#include "MAX7219.h"

MAX7219::MAX7219(uint8_t loadPin, uint8_t scanLimit, uint8_t intensity) {
  this->loadPin = loadPin;

  this->scanLimit = scanLimit;
  this->intensity = intensity;

  //Startup without display test
  this->isTestModeEnabled = MAX7219_DISPLAY_TEST_DISABLED;

  //Startup in shutdown mode
  this->isShutdown = MAX7219_SHUTDOWN_ENABLED;

  pinMode(this->loadPin, OUTPUT);

  //Enable decode all mode by default to enable BCD
  Write(MAX7219_DECODE_MODE_ADDR, MAX7219_DECODE_ALL);

  Write(MAX7219_SCAN_LIMIT_ADDR, scanLimit);
  Write(MAX7219_INTENSITY_ADDR, intensity);

  Write(MAX7219_DISPLAY_TEST_ADDR, this->isTestModeEnabled);

  Write(MAX7219_SHUTDOWN_ADDR, this->isShutdown);
}

void MAX7219::Write(uint8_t addr, uint8_t data) {
  uint16_t val = (addr << 8) | data;

  BeginTransaction();

  SPI.transfer16(val);

  //Pull LOAD high then low. This dumps register data
  digitalWrite(this->loadPin, HIGH);
  digitalWrite(this->loadPin, LOW);

  EndTransaction();
}

void MAX7219::BeginTransaction() {
  //Operate chip at 10MHz
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
}

void MAX7219::EndTransaction() {
  SPI.endTransaction();
}

void MAX7219::DisableTestMode() {
  this->isTestModeEnabled = false;
  Write(MAX7219_DISPLAY_TEST_ADDR, this->isTestModeEnabled);
}

void MAX7219::EnableTestMode() {
  this->isTestModeEnabled = true;
  Write(MAX7219_DISPLAY_TEST_ADDR, this->isTestModeEnabled);
}

void MAX7219::Shutdown() {
  this->isShutdown = true;
  Write(MAX7219_SHUTDOWN_ADDR, MAX7219_SHUTDOWN_ENABLED);
}

void MAX7219::EnableNormalOperation() {
  this->isShutdown = false;
  Write(MAX7219_SHUTDOWN_ADDR, MAX7219_SHUTDOWN_NORMAL_OPERATION);
}

void MAX7219::SetScanLimit(uint8_t scanLimit) {
  this->scanLimit = scanLimit;
  Write(MAX7219_SCAN_LIMIT_ADDR, this->scanLimit);
}

void MAX7219::SetIntensity(uint8_t intensity) {
  this->intensity = intensity;
  Write(MAX7219_INTENSITY_ADDR, this->intensity);
}

void MAX7219::SetDigit(uint8_t digitAddr, uint8_t digitValue) {
  Write(digitAddr, digitValue);
}

bool MAX7219::IsTestModeEnabled() const {
  return this->isTestModeEnabled;
}

bool MAX7219::IsShutdown() const {
  return this->isShutdown;
}

uint8_t MAX7219::GetScanLimit() const {
  return this->scanLimit;
}

uint8_t MAX7219::GetIntensity() const {
  return this->intensity;
}
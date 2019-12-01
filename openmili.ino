#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>

#include "PL1167_nRF24.h"
#include "MiLightRadio.h"

#define CE_PIN 8
#define CSN_PIN 53

RF24 radio(CE_PIN, CSN_PIN);
PL1167_nRF24 prf(radio);
MiLightRadio mlr(prf);

void setup()
{
  Serial.begin(115200);
  printf_begin();
  delay(1000);
  Serial.println("# OpenMiLight Receiver/Transmitter starting");
  mlr.begin();
}


static int dupesPrinted = 0;
static bool receiving = false;
static bool escaped = false;
static uint8_t outgoingPacket[7] = {0x07, 0xB0 , 0xF2 , 0xEA , 0x04 , 0x91 , 0x13 , 0xD3 , 0x44 , 0x99};
static uint8_t outgoingPacketPos = 0;
static uint8_t nibble;


void loop()
{
    outgoingPacket[5] = 0;
    outgoingPacket[5] = 255;
    mlr.write(outgoingPacket, sizeof(outgoingPacket));
}


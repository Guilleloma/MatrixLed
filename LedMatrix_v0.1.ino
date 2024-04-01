// This code is able to generate a heartbeat and a "Mama" text ideal for the mom's day
// Autor: Guillermo Lopez Marin

//Including library for LedControl
#include <LedControl.h>

const int DIN = 7; //Data Pin
const int CS = 6; //Chip Select Pin
const int CLK =5; // Clock Pin

//Variable to iterate through images
int i=0;



//Codigo Generado por Led Matrix Editor

// Array of images representing a beating heart, stored as 64-bit values
// Each bit represents the state of an LED (on or off) in the 8x8 matrix
const uint64_t IMAGES[] = {
  0x00183c7effff6600,
  0x0000183c7e660000,
  0x0000001818000000,
  0x0000183c7e660000,
  0x00183c7effff6600
};
const int IMAGES_LEN = sizeof(IMAGES)/8; //Calculate the quantity of images in the array

//Mama array
const uint64_t IMAGESM[] = {
  0x8080808080808000,
  0xc0c0c0c0c0c0c000,
  0x60606060e0e06000,
  0x303030b0f0703000,
  0x18181858f8b81800,
  0x8c8c8cacfcdc8c00,
  0xc6c6c6d6feeec600,
  0x6363636b7f776300,
  0x313131353f3b3100,
  0x1818181a1f1d1800,
  0x9898989a9f9d1800,
  0xcccccccdcfce8c00,
  0x666666e66767c600,
  0x333333f33333e300,
  0x999999f99999f100,
  0xccccccfccccc7800,
  0x6666667e66663c00,
  0x3333333f33331e00,
  0x9999999f99998f00,
  0xcccccccfccccc700,
  0x66666667e6e66300,
  0x333333b3f3733100,
  0x19191959f9b91800,
  0x8c8c8cacfcdc8c00,
  0xc6c6c6d6feeec600,
  0x6363636b7f776300,
  0x313131353f3b3100,
  0x9898989a9f9d1800,
  0xcccccccdcfce8c00,
  0x666666e66767c600,
  0x333333f33333e300,
  0x999999f99999f100,
  0xccccccfccccc7800,
  0x6666667e66663c00
};
const int IMAGESM_LEN = sizeof(IMAGESM)/8;


// Init. matrix led controled with the specified Pins
LedControl display = LedControl(DIN,CLK,CS);

void setup() {
  display.clearDisplay(0);
  display.shutdown (0,false);
  display.setIntensity (0,10);

}

void displayImage(uint64_t image){
  for(int i =0; i<8; i++){
    byte row = (image >> i*8) & 0xFF;
    for(int j=0;j<8;j++){
      display.setLed(0,i,j,bitRead(row,j));
    }
  }
}
void loop() {
  displayImage(IMAGES[i]);
  if(++i >= IMAGES_LEN){
    i=0;
  }
  delay(500);
}

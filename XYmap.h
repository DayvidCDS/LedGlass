const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 5;

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
#define LAST_VISIBLE_LED 67

CRGB leds[ NUM_LEDS ];

uint8_t XY( uint8_t x, uint8_t y) {
  
  if( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }
  
  const uint8_t ShadesTable[] = {
     68,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 69,
     14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
     30, 31, 32, 33, 34, 35, 36, 70, 71, 37, 38, 39, 40, 41, 42, 43,
     44, 45, 46, 47, 48, 49, 50, 72, 73, 51, 52, 53, 54, 55, 56, 57,
     74, 58, 59, 60, 61, 62, 75, 76, 77, 78, 63, 64, 65, 66, 67, 79
  };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = ShadesTable[i];
  return j;
}

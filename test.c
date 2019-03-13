#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "crc8scd30.h"

int main() {

  if (crc8scd30(NULL, 0) != 0xFF) {
    printf("crc of null input failed\n");
  } else {
    printf("crc of null input OK\n");
  }

  // from crc algorithm properties
  uint8_t beef[] = {0xBE, 0xEF};
  uint8_t crc_beef = crc8scd30(beef, 2);
  if (crc_beef != 0x92) {
    printf("crc of 0xBEEF failed\n");
  } else {
    printf("crc of 0xBEEF OK\n");
  }

  // from read firmware version command
  uint8_t fv[] = {0x03, 0x42};
  uint8_t crc_fv = crc8scd30(fv, 2);
  if (crc_fv != 0xF3) {
    printf("crc of read firmware version failed\n");
  } else {
    printf("crc of read firmware version OK\n");
  }

  return EXIT_SUCCESS;

}



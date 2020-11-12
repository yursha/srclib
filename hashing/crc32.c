#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Online CRC32 computation: https://crccalc.com/
// 
// Literature:
// - A PAINLESS GUIDE TO CRC ERROR DETECTION ALGORITHMS
//     http://chrisballance.com/wp-content/uploads/2015/10/CRC-Primer.html
//
// - CRC-32, Rosetta Code
//     https://rosettacode.org/wiki/CRC-32

uint32_t CRC_TABLE[256];

uint32_t crc32(char *bytes, size_t n_bytes) {
  uint32_t result = 0xFFFFFFFF;
  for (int i = 0; i < n_bytes; i++) {
    uint8_t octet = bytes[i];
    uint32_t lookup_index = (result & 0xFF) ^ octet;
    result = (result >> 8) ^ CRC_TABLE[lookup_index];
  }
  // reverse all bits
  return result ^ 0xFFFFFFFF;
}

void init_table() {
  for (int i = 0; i < 256; i++) {
    uint32_t rem = i;
    for (int j = 0; j < 8; j++) {
      if (rem & 1) {
        rem >>= 1;
        rem ^= 0xedb88320;
      } else {
        rem >>= 1;
      }
    }
    CRC_TABLE[i] = rem;
  }
}

int main() {
  init_table();
  printf("crc32('spaceship') = %#.8x, expected 0xaa708c8e\n",
    crc32("spaceship", strlen("spaceship")));
  printf("crc32('banana') = %#.8x, expected 0x038b67cf\n",
    crc32("banana", strlen("banana")));
  printf("crc32('plumless') = %#.8x, expected 0x4ddb0c25\n",
    crc32("plumless", strlen("plumless")));
  printf("crc32('buckeroo') = %#.8x, expected 0x4ddb0c25\n",
    crc32("buckeroo", strlen("buckeroo")));
}

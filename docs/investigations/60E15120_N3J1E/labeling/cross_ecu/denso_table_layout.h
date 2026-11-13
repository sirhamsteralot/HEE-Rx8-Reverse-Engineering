#ifndef RX8_DENSO_TABLE_LAYOUT_H
#define RX8_DENSO_TABLE_LAYOUT_H
#include <stdint.h>
#include <stddef.h>
/* File-layout documentation, NOT permission to cast a host pointer into ROM.
 * Multibyte fields are big-endian. Decode addresses and float bit patterns.
 * Layout corroborated by local lookup code and ScoobyRom Table2D/Table3D.
 * Shorter records omit the multiplier/offset pair. Type-code interpretation
 * must be verified against the target's dispatch table, not guessed by brand.
 */
typedef struct {
 uint16_t count;
 uint8_t type, reserved;
 uint32_t axis_address, data_address;
} rx8_denso_2d_base;
typedef struct {
 rx8_denso_2d_base base;
 uint32_t multiplier_binary32, offset_binary32;
} rx8_denso_2d_scaled;
typedef struct {
 uint16_t count_x, count_y;
 uint32_t axis_x_address, axis_y_address, data_address;
 uint8_t type, reserved[3];
} rx8_denso_3d_base;
typedef struct {
 rx8_denso_3d_base base;
 uint32_t multiplier_binary32, offset_binary32;
} rx8_denso_3d_scaled;
_Static_assert(sizeof(rx8_denso_2d_base)==12,"2D base layout");
_Static_assert(sizeof(rx8_denso_2d_scaled)==20,"2D scaled layout");
_Static_assert(offsetof(rx8_denso_3d_base,type)==16,"3D type offset");
_Static_assert(sizeof(rx8_denso_3d_scaled)==28,"3D scaled layout");
#endif

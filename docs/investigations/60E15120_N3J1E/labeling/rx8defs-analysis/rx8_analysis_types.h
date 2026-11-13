#ifndef RX8_ANALYSIS_TYPES_H
#define RX8_ANALYSIS_TYPES_H
#include <stdint.h>
#include <stddef.h>
/* Target-layout analysis types. Addresses are 32-bit values, not host pointers.
 * ROM fields are big-endian. Do not cast an unconverted file buffer on a LE host.
 * Tables with type zero may end before the optional scale/offset fields. */
typedef struct {
 uint16_t axis_count;
 uint8_t type_code, unknown_03;
 uint32_t axis_address, data_address;
 float multiplier, offset;
} Rx8Table2D;
typedef struct {
 uint16_t x_count, y_count;
 uint32_t x_axis_address, y_axis_address, data_address;
 int8_t type_code;
 uint8_t unknown_11[3];
 float multiplier, offset;
} Rx8Table3D;
typedef struct {
 uint16_t identifier;
 uint8_t response_length, unknown_03;
 uint16_t availability_mask, unknown_06;
 uint32_t handler_address;
} Rx8DiagnosticRecord;
typedef struct {
 uint32_t identifier;
 uint8_t unknown_04, mailbox_selector, payload_length, unknown_07;
 uint32_t payload_address, unknown_0c;
} Rx8CanMessageDescriptor;
typedef struct {
 uint16_t key;
 uint8_t payload, untouched_padding;
} Rx8KeyPayloadRecord;
#define RX8_ROM_PTR(type, address) ((const type *)(uintptr_t)(address))
typedef void (*Rx8DiagnosticHandler)(uint8_t service);
enum Rx8DiagnosticConstants {
 RX8_SERVICE_READ_DATA = 0x22,
 RX8_POSITIVE_READ_DATA_RESPONSE = 0x62,
 RX8_DIAG_IDENTIFIER_REJECTED = 0x31,
 RX8_DIAGNOSTIC_RECORD_COUNT = 99,
 RX8_DIAG_READ_HEADER_SIZE = 3
};
enum Rx8SciStatusBits { RX8_SCI_RDRF = 0x40, RX8_SCI_TDRE = 0x80 };
enum Rx8EncodedLimits { RX8_U8_MAX = 255, RX8_U16_MAX = 65535 };
_Static_assert(sizeof(Rx8Table2D)==20 && offsetof(Rx8Table2D,multiplier)==12,"2D layout");
_Static_assert(sizeof(Rx8Table3D)==28 && offsetof(Rx8Table3D,type_code)==16,"3D layout");
_Static_assert(sizeof(Rx8DiagnosticRecord)==12 && offsetof(Rx8DiagnosticRecord,handler_address)==8,"diagnostic layout");
_Static_assert(sizeof(Rx8CanMessageDescriptor)==16 && offsetof(Rx8CanMessageDescriptor,payload_address)==8,"CAN layout");
_Static_assert(sizeof(Rx8KeyPayloadRecord)==4 && offsetof(Rx8KeyPayloadRecord,payload)==2,"sort layout");
/* Analysis carriers for the nonstandard R0/FR0 and R2/R3/FR0/FR1 outputs.
 * These are not assertions about the compiler's native struct-return ABI. */
typedef struct { uint32_t index; float fraction; } Rx8AxisPosition;
typedef struct { Rx8AxisPosition x, y; } Rx8MapPosition;
/* Explicit unresolved machine operations. No generic C/FMA/FTRC equivalence
 * for exceptional inputs or target rounding is asserted. */
float rx8_sh_fmac_model(float multiplier, float value, float accumulator);
int32_t rx8_sh_ftrc_model(float value);
float rx8_unresolved_table_dispatch_2d(int type_code);
float rx8_unresolved_table_dispatch_3d(int type_code);
float lookup_2d_descriptor_scaled(float axis_value, const Rx8Table2D *table);
uint32_t rx8_lookup_2d_raw_u8(float axis_value, const Rx8Table2D *table);
uint32_t rx8_lookup_2d_raw_u16(float axis_value, const Rx8Table2D *table);
float lookup_3d_descriptor_scaled(float x_value, float y_value, const Rx8Table3D *table);
uint32_t rx8_lookup_3d_raw_u8(float x_value, float y_value, const Rx8Table3D *table);
uint32_t rx8_lookup_3d_raw_u16(float x_value, float y_value, const Rx8Table3D *table);
float rx8_interpolate_2axis_f32(uint32_t column_count, const float *values, Rx8MapPosition position);
float rx8_interpolate_2axis_s8(uint32_t column_count, const int8_t *values, Rx8MapPosition position);
float rx8_interpolate_2axis_s16(uint32_t column_count, const int16_t *values, Rx8MapPosition position);
float rx8_interpolate_2axis_u8(uint32_t column_count, const uint8_t *values, Rx8MapPosition position);
float rx8_interpolate_2axis_u16(uint32_t column_count, const uint16_t *values, Rx8MapPosition position);
Rx8AxisPosition rx8_find_axis_index_fraction(uint32_t count, const float *axis, float value);
Rx8MapPosition rx8_find_xy_axis_positions(float x_value, float y_value, const Rx8Table3D *table);
float rx8_interpolate_1d_f32(uint32_t lower_index, const float *values, float fraction);
float rx8_interpolate_1d_s16(uint32_t lower_index, const int16_t *values, float fraction);
float rx8_interpolate_1d_u8(uint32_t lower_index, const uint8_t *values, float fraction);
float rx8_interpolate_1d_u16(uint32_t lower_index, const uint16_t *values, float fraction);
float rx8_interpolate_1d_s8(uint32_t lower_index, const int8_t *values, float fraction);

#endif

/* [ADDITIONAL SOURCE REVIEW]
 * can201_encode_vehicle_speed_u16 [high]: Reads diagnostic-correlated speed 0xffffbbb4; quantization is (speed+100)/0.01 rounded and bounded to 40000, or 0xffff on fault. Result 0xffffbb00 is packed at payload bytes 4 and 5.
 * RAM 0xffffbb00 can201_encoded_vehicle_speed (uint16): (speed+100)/0.01, normal cap 40000.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): vehicle_speed_ffffbbb4; decode = raw * 0.009999999776 + (-100) [km/h]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0002927c; body bytes: 64; decompiled */

uint can201_encode_vehicle_speed_u16(void)

{
  uint uVar1;
  
  if (DAT_ffffbbbb == '\x01') {
    can201_encoded_vehicle_speed_ffffbb00 = 0xffff;
    uVar1 = 1;
  }
  else {
    uVar1 = rx8_encode_u16_affine_saturate(vehicle_speed_ffffbbb4,0x3c23d70a,0xc2c80000);
    if ((uVar1 & 0xffff) < 0x9c41) {
      can201_encoded_vehicle_speed_ffffbb00 = (undefined2)uVar1;
    }
    else {
      can201_encoded_vehicle_speed_ffffbb00 = 40000;
    }
  }
  return uVar1;
}



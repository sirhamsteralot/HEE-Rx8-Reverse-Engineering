/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffb40c; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): -DAT_ffffb414; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): DAT_ffffb414; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): DAT_ffffb594; decode = raw * 0.0003051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): uVar3; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): DAT_ffffb38c; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): uVar3; decode = raw * 0.00390625 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): engine_speed_rpm_ffffb548; decode = raw * 0.1953125 + (0) [RPM]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000244bc; body bytes: 1408; decompiled */

void FUN_000244bc(void)

{
  ushort uVar1;
  char cVar2;
  undefined4 uVar3;
  
  DAT_ffffb442 = rx8_encode_u16_affine_saturate(DAT_ffffb40c,0x3cfa0000,0);
  DAT_ffffb444 = DAT_ffffb442;
  if (DAT_ffffb414 < 0.0) {
    uVar1 = rx8_encode_u16_affine_saturate(-DAT_ffffb414,0x3cfa0000,0);
    DAT_ffffb446 = ~uVar1 + 1;
  }
  else {
    DAT_ffffb446 = rx8_encode_u16_affine_saturate(DAT_ffffb414,0x3cfa0000,0);
  }
  DAT_ffffb448 = rx8_encode_u16_affine_saturate(DAT_ffffb594,0x39a00000,0);
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff807c);
  DAT_ffffb44a = rx8_encode_u16_affine_saturate(uVar3,0x3cfa0000,0);
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff8084);
  DAT_ffffb44c = rx8_encode_u16_affine_saturate(uVar3,0x3cfa0000,0);
  DAT_ffffb44e = DAT_ffffa9c4;
  DAT_ffffb450 = DAT_ffffb51e;
  DAT_ffffb452 = DAT_ffffb520;
  DAT_ffffb454 = DAT_ffffb522;
  DAT_ffffb456 = DAT_ffffb524;
  DAT_ffffb458 = DAT_ffffcc91;
  if (DAT_ffffaa68 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 1;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xfe;
  }
  if (DAT_ffffccc1 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 2;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xfd;
  }
  if (DAT_ffffbced == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 4;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xfb;
  }
  if (DAT_ffffccc9 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 8;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xf7;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a0,0);
  if (cVar2 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x10;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xef;
  }
  if (DAT_ffffad60 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x20;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xdf;
  }
  if (DAT_ffffad62 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x40;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xbf;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8762,0);
  if (cVar2 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x80;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0x7f;
  }
  if (DAT_ffffb4df == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 1;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xfe;
  }
  if (DAT_ffffb4e0 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 2;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xfd;
  }
  if (DAT_ffffb4e1 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x10;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xef;
  }
  if (DAT_ffffb4e2 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x20;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xdf;
  }
  if (DAT_ffffb4e3 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x40;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xbf;
  }
  if (DAT_ffffb4e4 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x80;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0x7f;
  }
  if (DAT_ffffb4dc == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 1;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xfe;
  }
  if (DAT_ffffb4de == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 2;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xfd;
  }
  if (DAT_ffffb4dd == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 4;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xfb;
  }
  if (DAT_ffffb4e5 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x10;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xef;
  }
  if (DAT_ffffb4e6 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x20;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xdf;
  }
  if (DAT_ffffb4e7 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x40;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xbf;
  }
  if (DAT_ffffb4e8 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x80;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0x7f;
  }
  if (DAT_ffffb4e9 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 1;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xfe;
  }
  if (DAT_ffffb51c == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 2;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xfd;
  }
  if (DAT_ffffb4ea == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 4;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xfb;
  }
  if (DAT_ffffb2cf == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 8;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xf7;
  }
  if (DAT_ffffb2d0 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 0x10;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xef;
  }
  if (DAT_ffffb422 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 0x20;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xdf;
  }
  if (DAT_ffffc030 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 0x40;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xbf;
  }
  if (DAT_ffffad61 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 1;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xfe;
  }
  if (DAT_ffffad63 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 2;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xfd;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a2,1);
  if (cVar2 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 4;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xfb;
  }
  if (DAT_ffffccc7 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 8;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xf7;
  }
  if (DAT_ffffccbd == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x10;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xef;
  }
  if (DAT_ffffccbc == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x20;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xdf;
  }
  if (DAT_ffffb4eb == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x40;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xbf;
  }
  if (DAT_ffffccc8 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x80;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0x7f;
  }
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41a00000,&DAT_ffff8094);
  DAT_ffffb45e = rx8_encode_u16_affine_saturate(uVar3,0x3cfa0000,0);
  DAT_ffffb460 = rx8_encode_u16_affine_saturate(DAT_ffffb38c,0x3cfa0000,0);
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&DAT_ffff8068);
  DAT_ffffb462 = rx8_encode_u16_affine_saturate(uVar3,0x3b800000,0);
  DAT_ffffb464 = rx8_encode_u16_affine_saturate(engine_speed_rpm_ffffb548,0x3e480000,0);
  return;
}



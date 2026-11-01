/* ROM address: 0x00003920; body bytes: 18; decompiled */

uint FUN_00003920(uint param_1)

{
  uint uVar1;
  uint in_sr;
  
  uVar1 = in_sr & 0xf0;
  if (uVar1 < param_1) {
    return uVar1;
  }
  return uVar1;
}



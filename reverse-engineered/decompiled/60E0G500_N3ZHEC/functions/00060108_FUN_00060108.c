/* ROM address: 0x00060108; body bytes: 38; decompiled */

uint FUN_00060108(short param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0007e108)[uVar1 & 0xffff] != param_1 && ((uVar1 & 0xffff) < 0x8c));
      uVar1 = uVar1 + 1) {
  }
  return uVar1;
}



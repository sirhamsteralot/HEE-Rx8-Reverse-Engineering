/* ROM address: 0x0002aafe; body bytes: 110; decompiled */

undefined4 FUN_0002aafe(void)

{
  float fVar1;
  undefined4 uVar2;
  
  if (DAT_ffffbb8c == '\x01') {
    DAT_ffffbba6 = 0xffff;
    uVar2 = 1;
  }
  else {
    if ((DAT_ffffa428 == '\0') || (DAT_ffffb13b == '\x01')) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = DAT_ffffbd18;
      if (DAT_ffffb13a == '\x01') {
        fVar1 = DAT_ffffbd18 * 0.5;
      }
    }
    uVar2 = 0xc4000000;
    fVar1 = rx8_clamp_float(fVar1,-512.0,65022.0);
    uVar2 = FUN_00002490(fVar1,0x3f800000,uVar2);
    DAT_ffffbba6 = (undefined2)uVar2;
  }
  return uVar2;
}



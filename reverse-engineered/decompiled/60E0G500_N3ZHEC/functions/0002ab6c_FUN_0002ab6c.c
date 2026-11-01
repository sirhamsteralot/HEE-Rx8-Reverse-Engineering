/* ROM address: 0x0002ab6c; body bytes: 80; decompiled */

undefined4 FUN_0002ab6c(void)

{
  float fVar1;
  undefined4 uVar2;
  
  if (DAT_ffffbb8c == '\x01') {
    DAT_ffffbba8 = 0xffff;
    uVar2 = 1;
  }
  else if (DAT_ffffa428 == '\0') {
    DAT_ffffbba8 = 0x200;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc4000000;
    fVar1 = rx8_clamp_float(DAT_ffffbd20,-512.0,65022.0);
    uVar2 = FUN_00002490(fVar1,0x3f800000,uVar2);
    DAT_ffffbba8 = (undefined2)uVar2;
  }
  return uVar2;
}



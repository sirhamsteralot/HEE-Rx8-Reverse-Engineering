/* ROM address: 0x0000e07a; body bytes: 106; decompiled */

undefined4 FUN_0000e07a(byte param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_c;
  byte bStack_8;
  
  bStack_8 = param_1;
  FUN_00002054(&local_c,0xe0);
  if (DAT_ffffc63c == '\0') {
    DAT_ffffa415 = bStack_8;
    DAT_ffffa414 = bStack_8;
    if (5 < bStack_8) {
      if (bStack_8 < 0xc) {
        DAT_ffffa414 = bStack_8 - 6;
      }
      else {
        if (bStack_8 < 0x12) {
          cVar1 = -0xc;
        }
        else {
          cVar1 = -0x12;
        }
        DAT_ffffa414 = bStack_8 + cVar1;
      }
    }
  }
  else {
    DAT_ffffa414 = 0xff;
    DAT_ffffa415 = 0xff;
  }
  uVar2 = FUN_00002064(local_c);
  return uVar2;
}



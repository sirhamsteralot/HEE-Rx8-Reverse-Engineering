/* ROM address: 0x00007398; body bytes: 8; decompiled */

undefined2 * FUN_00007398(void)

{
  undefined4 uVar1;
  
  DAT_ffff9f76 = DAT_ffff9f1c;
  DAT_ffff9f76 = FUN_00002510(DAT_ffff9f1c,DAT_ffff9f1c,0x100);
  uVar1 = FUN_000024c0(0x38a00000,0,(int)(short)DAT_ffff9f76);
  DAT_ffff9f70 = FUN_00002068(uVar1,&DAT_00069e14);
  if (DAT_ffff9f76 < 0xfd00) {
    if (DAT_ffff9f76 < 0x9ff) {
      DAT_ffff9f74 = 2;
    }
    else {
      DAT_ffff9f74 = 0;
    }
  }
  else {
    DAT_ffff9f74 = 1;
  }
  return &DAT_0006cf52;
}



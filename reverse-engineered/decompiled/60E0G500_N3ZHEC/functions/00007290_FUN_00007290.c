/* ROM address: 0x00007290; body bytes: 8; decompiled */

undefined2 * FUN_00007290(void)

{
  undefined4 uVar1;
  
  DAT_ffff9f66 = DAT_ffff9f1e;
  DAT_ffff9f66 = FUN_00002510(DAT_ffff9f1e,DAT_ffff9f1e,0x100);
  uVar1 = FUN_000024c0(0x38a00000,0,(int)(short)DAT_ffff9f66);
  DAT_ffff9f60 = FUN_00002068(uVar1,&DAT_00069eb4);
  if (DAT_ffff9f66 < 0xf6c9) {
    if (DAT_ffff9f66 < 0x51e) {
      DAT_ffff9f64 = 2;
    }
    else {
      DAT_ffff9f64 = 0;
    }
  }
  else {
    DAT_ffff9f64 = 1;
  }
  return &DAT_0006cf46;
}



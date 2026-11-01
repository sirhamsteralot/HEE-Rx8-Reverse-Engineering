/* ROM address: 0x0000d144; body bytes: 106; decompiled */

undefined4 FUN_0000d144(void)

{
  undefined4 uVar1;
  float fVar2;
  
  DAT_ffffa3e2 = FUN_00002510(DAT_ffff9f18,DAT_ffffa3e2,0x100);
  fVar2 = (float)FUN_000024c0(0x38a00000,0,(int)(short)DAT_ffffa3e2);
  DAT_ffffa3dc = fVar2 * 25.325 + 0.0182;
  if (DAT_ffffa3e2 < 0xf5c3) {
    if (0xa3c < DAT_ffffa3e2) {
      DAT_ffffa3e0 = 0;
      return 0xa3d;
    }
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  DAT_ffffa3e0 = (char)uVar1;
  return uVar1;
}



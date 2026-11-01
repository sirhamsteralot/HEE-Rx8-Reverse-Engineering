/* ROM address: 0x00064d00; body bytes: 126; decompiled */

uint FUN_00064d00(void)

{
  uint uVar1;
  char cVar2;
  
  DAT_ffffd7ee = FUN_0006385c(1);
  uVar1 = (uint)DAT_ffff8ea4;
  if (uVar1 == 1) {
    cVar2 = FUN_00068058(0);
    if (cVar2 != '\0') {
      FUN_00062b44(0);
      FUN_00062e0c();
      FUN_00068042(0);
      FUN_00063098();
      FUN_00062f44();
    }
    uVar1 = FUN_00068058(1);
    if ((uVar1 & 0xff) != 0) {
      FUN_00062b44(1);
      FUN_00062e0c();
      FUN_00068042(0);
      FUN_00063098();
      uVar1 = FUN_00062f44();
    }
  }
  DAT_ffffd7ef = 0;
  DAT_ffffd7f0 = 0;
  return uVar1;
}



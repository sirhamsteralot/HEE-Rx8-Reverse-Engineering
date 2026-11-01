/* ROM address: 0x0002c618; body bytes: 94; decompiled */

void FUN_0002c618(void)

{
  uint uVar1;
  
  uVar1 = FUN_000070ac(1);
  if ((uVar1 & 0x20) == 0) {
    if (0xf < DAT_ffffbc70) {
      DAT_ffffbc6c = 0;
    }
    DAT_ffffbc70 = FUN_00002460((int)(short)DAT_ffffbc70,1);
    DAT_ffffbc6e = 0;
  }
  else {
    if (0xf < DAT_ffffbc6e) {
      DAT_ffffbc6c = 1;
    }
    DAT_ffffbc6e = FUN_00002460((int)(short)DAT_ffffbc6e,1);
    DAT_ffffbc70 = 0;
  }
  return;
}



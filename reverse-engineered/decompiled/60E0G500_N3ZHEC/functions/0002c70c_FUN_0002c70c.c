/* ROM address: 0x0002c70c; body bytes: 136; decompiled */

void FUN_0002c70c(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = FUN_000070ac(2);
  bVar1 = (uVar2 & 1) != 0;
  if (DAT_ffffa428 == '\0') {
    DAT_ffffbc7c = 1;
  }
  else if (bVar1) {
    if (1 < DAT_ffffbc7e) {
      DAT_ffffbc7c = 0;
    }
  }
  else if (0x270 < DAT_ffffbc80) {
    DAT_ffffbc7c = 1;
  }
  if (bVar1) {
    DAT_ffffbc7e = FUN_00002460((int)(short)DAT_ffffbc7e,1);
    DAT_ffffbc80 = 0;
  }
  else {
    DAT_ffffbc80 = FUN_00002460((int)(short)DAT_ffffbc80,1);
    DAT_ffffbc7e = 0;
  }
  return;
}



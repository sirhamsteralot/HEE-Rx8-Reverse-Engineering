/* ROM address: 0x00035c44; body bytes: 114; decompiled */

uint FUN_00035c44(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc28e;
  if (uVar1 == 3) {
    DAT_ffffc28d = 1;
    uVar1 = FUN_00035cfa();
    return uVar1;
  }
  if (uVar1 == 1) {
    uVar1 = FUN_00035e50();
    return uVar1;
  }
  if (1 < DAT_ffffc28f) {
    DAT_ffffc28f = 0;
    uVar1 = FUN_00036720(0xc6);
  }
  if (DAT_ffffc27c != 0) {
    DAT_ffffc27c = DAT_ffffc27c + -1;
  }
  if (DAT_ffffc27c == 0) {
    FUN_00036320();
    DAT_ffffc294 = 0;
    uVar1 = FUN_00036720(1);
    DAT_ffffc29a = 1;
  }
  return uVar1;
}



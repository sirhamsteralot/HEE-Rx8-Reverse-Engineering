/* ROM address: 0x000296a0; body bytes: 64; decompiled */

uint FUN_000296a0(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffbb04 = 0;
    uVar1 = 1;
  }
  else {
    if (399 < DAT_ffffbb04) {
      DAT_ffffbb04 = 0;
    }
    uVar1 = (uint)DAT_ffffb70c;
    if (uVar1 == 1) {
      uVar1 = FUN_00002460((int)(short)DAT_ffffbb04,1);
      DAT_ffffbb04 = (ushort)uVar1;
    }
  }
  return uVar1;
}



/* ROM address: 0x000296e0; body bytes: 70; decompiled */

uint FUN_000296e0(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffbb06 = 0;
    DAT_ffffbb08 = 1;
    uVar1 = 1;
  }
  else {
    if (1999 < DAT_ffffbb06) {
      DAT_ffffbb06 = 0;
    }
    uVar1 = (uint)DAT_ffffb70c;
    if (uVar1 == 1) {
      uVar1 = FUN_00002460((int)(short)DAT_ffffbb06,1);
      DAT_ffffbb06 = (ushort)uVar1;
    }
  }
  return uVar1;
}



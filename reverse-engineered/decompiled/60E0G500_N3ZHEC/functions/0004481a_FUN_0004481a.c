/* ROM address: 0x0004481a; body bytes: 66; decompiled */

uint FUN_0004481a(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffaada;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcaaf, uVar1 == 100)) {
    DAT_ffffcabf = 0;
  }
  else if ((DAT_ffffcab6 == '\0') && (uVar1 = (uint)DAT_ffffcb0b, uVar1 == 1)) {
    DAT_ffffcabf = 1;
  }
  DAT_ffffcb0b = DAT_ffffcab6;
  return uVar1;
}



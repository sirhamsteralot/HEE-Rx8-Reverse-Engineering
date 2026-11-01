/* ROM address: 0x00006b94; body bytes: 128; decompiled */

uint FUN_00006b94(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_ffff9f2b == 0) {
    return 0;
  }
  uVar1 = (uint)DAT_ffff9f2b;
  if (uVar1 == 0xc) {
    DAT_ffff9efa = DAT_fffff816;
    DAT_ffff9ef8 = DAT_fffff814;
    DAT_ffff9ef6 = DAT_fffff812;
    DAT_ffff9ef4 = DAT_fffff810;
LAB_00006be0:
    DAT_ffff9ef2 = DAT_fffff80e;
    DAT_ffff9ef0 = DAT_fffff80c;
    DAT_ffff9eee = DAT_fffff80a;
    DAT_ffff9eec = DAT_fffff808;
  }
  else {
    if (uVar1 == 8) goto LAB_00006be0;
    if (uVar1 != 4) {
      uVar2 = 1;
      if (uVar1 != 1) {
        DAT_ffff9f29 = 0;
        DAT_ffff9f2a = 0;
        return uVar1;
      }
      goto LAB_00006c0a;
    }
  }
  DAT_ffff9eea = DAT_fffff806;
  DAT_ffff9ee8 = DAT_fffff804;
  DAT_ffff9ee6 = DAT_fffff802;
  uVar2 = (uint)DAT_ffff9ee6;
LAB_00006c0a:
  DAT_ffff9ee4 = DAT_fffff800;
  DAT_ffff9f2a = 0;
  DAT_ffff9f29 = 0;
  return uVar2;
}



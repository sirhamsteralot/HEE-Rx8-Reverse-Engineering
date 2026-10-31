/* ROM address: 0x0002b816; body bytes: 170; decompiled */

uint FUN_0002b816(void)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = DAT_ffffbbf2 == -1;
  if (!bVar2) {
    DAT_ffffbbc8 = DAT_ffffbbf2;
  }
  if (DAT_ffffbbf3 == -1) {
    bVar2 = true;
  }
  else if (engine_running_ffffa428 == '\x01') {
    DAT_ffffbbc9 = DAT_ffffbbf3;
  }
  if (DAT_ffffbbf4 == -1) {
    bVar2 = true;
  }
  else if ((((DAT_ffffbb24 == '\0') && (engine_running_ffffa428 == '\x01')) && (DAT_ffffa40a == '\0')) &&
          (DAT_ffffa401 == '\0')) {
    DAT_ffffbbca = DAT_ffffbbf4;
  }
  uVar1 = (uint)bVar2;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u8_saturate((int)DAT_ffffbbc7,1);
    DAT_ffffbbc7 = (char)uVar1;
  }
  else {
    DAT_ffffbbc7 = 0;
  }
  return uVar1;
}



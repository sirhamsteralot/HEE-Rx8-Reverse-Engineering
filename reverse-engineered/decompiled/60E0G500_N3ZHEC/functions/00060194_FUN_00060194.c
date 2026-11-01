/* ROM address: 0x00060194; body bytes: 132; decompiled */

undefined4 FUN_00060194(uint param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  param_1 = param_1 & 0xffff;
  if (param_2 == '\0') {
    if ((&DAT_ffffd638)[param_1] == -0x40) {
      uVar2 = 1;
    }
  }
  else if (param_2 == '\x01') {
    cVar1 = (&DAT_ffffd638)[param_1];
    if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
      uVar2 = 1;
    }
  }
  else if (param_2 == '\x02') {
    cVar1 = FUN_000624be();
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
  }
  else if ((param_2 == '\x03') && ((&DAT_ffffd5ac)[param_1] == '\x01')) {
    uVar2 = 1;
  }
  return uVar2;
}



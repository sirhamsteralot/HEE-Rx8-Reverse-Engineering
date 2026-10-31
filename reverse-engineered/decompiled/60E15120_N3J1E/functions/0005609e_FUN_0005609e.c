/* ROM address: 0x0005609e; body bytes: 478; decompiled_with_warnings */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0005609e(uint param_1,byte *param_2,byte *param_3)

{
  int iVar1;
  char cVar2;
  char cVar3;
  byte bVar5;
  undefined4 uVar4;
  byte local_2c;
  byte local_28 [12];
  
  local_28[4] = *param_2;
  local_28[5] = param_2[1];
  local_28[6] = param_2[2];
  local_28[7] = 0x4d;
  local_28[8] = 0x61;
  local_28[9] = 0x7a;
  local_28[10] = 100;
  local_28[0xb] = 0x41;
  iVar1 = (param_1 & 0xff) * 3;
  local_28[0] = (&DAT_0005f08b)[iVar1];
  local_28[1] = (&DAT_0005f08a)[iVar1];
  local_28[2] = (&DAT_0005f089)[iVar1];
  local_2c = 0;
  do {
    bVar5 = 0;
    if ((local_28[4] & 1) == 1) {
      cVar3 = '\x01';
    }
    else {
      cVar3 = '\0';
    }
    do {
      local_28[bVar5 + 4] = local_28[bVar5 + 4] >> 1;
      if ((bVar5 < 7) && ((local_28[bVar5 + 5] & 1) == 1)) {
        local_28[bVar5 + 4] = local_28[bVar5 + 4] | 0x80;
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < 8);
    bVar5 = 0;
    if ((local_28[0] & 1) == 1) {
      cVar2 = '\x01';
    }
    else {
      cVar2 = '\0';
    }
    do {
      local_28[bVar5] = local_28[bVar5] >> 1;
      if ((bVar5 < 2) && ((local_28[bVar5 + 1] & 1) == 1)) {
        local_28[bVar5] = local_28[bVar5] | 0x80;
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < 3);
    if (cVar3 != cVar2) {
      local_28[0] = local_28[0] ^ 0x28;
      local_28[1] = local_28[1] ^ 0x90;
      local_28[2] = (local_28[2] | 0x80) ^ 0x10;
    }
    local_2c = local_2c + 1;
  } while (local_2c < 0x40);
  if ((((((int)(char)local_28[1] & 0xfU) << 4 | ((int)(char)local_28[0] & 0xf0U) >> 4) ==
        (uint)*param_3) &&
      ((byte)(local_28[1] & 0xf0 | (byte)(((int)(char)local_28[2] & 0xf0U) >> 4)) == param_3[1])) &&
     (((int)(char)local_28[2] & 0xfU | ((int)(char)local_28[0] & 0xfU) << 4) == (uint)param_3[2])) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}



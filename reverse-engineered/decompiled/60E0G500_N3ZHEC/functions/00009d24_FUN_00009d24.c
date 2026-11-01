/* ROM address: 0x00009d24; body bytes: 216; decompiled */

void FUN_00009d24(uint param_1,ushort param_2,undefined1 param_3,char param_4,uint param_5,
                 byte param_6,ushort *param_7,ushort *param_8,undefined1 *param_9,
                 undefined1 *param_10)

{
  ushort uVar2;
  int iVar1;
  uint uVar4;
  short sVar3;
  
  sVar3 = 1;
  uVar2 = 1;
  for (uVar4 = (param_1 & 0xff) + 8 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
    sVar3 = sVar3 << 1;
    uVar2 = uVar2 << 1;
  }
  *param_7 = ~uVar2 & *param_7 | (param_2 & 0xff) * sVar3;
  *param_8 = *param_8 & ~uVar2 | param_6 * uVar2;
  *param_10 = param_3;
  if (param_4 == '\0') {
    param_10[4] = (char)param_5 * ' ';
    param_10[5] = (char)(param_5 >> 3);
  }
  else {
    param_10[4] = ((byte)(param_5 >> 0x10) & 3) + (char)(param_5 >> 0x12) * ' ' + param_4 * '\b';
    param_10[5] = (char)(param_5 >> 0x15);
    param_10[6] = (char)param_5;
    param_10[7] = (char)(param_5 >> 8);
  }
  iVar1 = 8;
  do {
    iVar1 = iVar1 + -1;
    *param_9 = 0;
    param_9 = param_9 + 1;
  } while (iVar1 != 0);
  return;
}



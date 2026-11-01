/* ROM address: 0x00038e8c; body bytes: 76; decompiled */

void FUN_00038e8c(uint param_1,byte *param_2,char param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = FUN_00003920(0x10);
  for (; param_3 != '\0'; param_3 = param_3 + -1) {
    uVar3 = param_1 & 0xffff;
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    (&DAT_ffffc2fe)[uVar3] = bVar1;
    param_1 = param_1 + 1;
    (&DAT_ffffc3fe)[uVar3] = ~(&DAT_ffffc2fe)[uVar3];
  }
  FUN_00003934(uVar2);
  return;
}



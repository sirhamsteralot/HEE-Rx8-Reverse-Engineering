/* ROM address: 0x00038ed8; body bytes: 190; decompiled */

undefined1 FUN_00038ed8(uint param_1,byte *param_2,char param_3)

{
  undefined4 uVar1;
  char cVar3;
  uint uVar2;
  byte *pbVar4;
  uint uVar5;
  undefined1 uStack_24;
  
  uVar1 = FUN_00003920(0x10);
  uStack_24 = 0;
  for (; param_3 != '\0'; param_3 = param_3 + -1) {
    uVar5 = param_1 & 0xffff;
    if ((&DAT_ffffc2fe)[uVar5] == (undefined1)~(&DAT_ffffc3fe)[uVar5]) {
      *param_2 = (&DAT_ffffc2fe)[uVar5];
    }
    else {
      cVar3 = FUN_0000bed8();
      if (cVar3 == '\0') {
        uVar2 = FUN_0000bdfa(((int)(param_1 & 0xffff) >> 1 & 0xffU) * 0x10000 + 0x6000000);
        if ((param_1 & 1) == 0) {
          uVar2 = (uVar2 & 0xffff) >> 8;
        }
        pbVar4 = &DAT_ffffc2fe + uVar5;
        *pbVar4 = (byte)uVar2;
        (&DAT_ffffc3fe)[uVar5] = ~*pbVar4;
        *param_2 = *pbVar4;
      }
      else {
        uStack_24 = 1;
      }
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  FUN_00003934(uVar1);
  return uStack_24;
}



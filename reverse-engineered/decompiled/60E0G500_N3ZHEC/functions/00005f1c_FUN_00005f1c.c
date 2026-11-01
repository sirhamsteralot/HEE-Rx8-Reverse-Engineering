/* ROM address: 0x00005f1c; body bytes: 218; decompiled */

undefined4 FUN_00005f1c(uint param_1,undefined4 *param_2)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  
  uVar7 = 0;
  iVar5 = (param_1 & 0xffff) * 8;
  puVar8 = (&PTR_DAT_0000d74c)[(param_1 & 0xffff) * 2];
  sVar2 = *(short *)(&DAT_0000d750 + iVar5);
  bVar1 = (&DAT_0000d752)[iVar5];
  uVar3 = FUN_00003920(0xe0);
  if (bVar1 < (byte)(&DAT_ffff9306)[(param_1 & 0xffff) * 3]) {
    uVar7 = 2;
  }
  else {
    iVar5 = FUN_00003854((int)sVar2);
    if (iVar5 == 0) {
      iVar5 = (param_1 & 0xffff) * 3;
      (&DAT_ffff9306)[iVar5] = (&DAT_ffff9306)[iVar5] + '\x01';
      puVar9 = (undefined4 *)(puVar8 + (uint)(byte)(&DAT_ffff9304)[iVar5] * 0x14);
      iVar5 = 5;
      do {
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        iVar5 = iVar5 + -1;
        *puVar9 = uVar4;
        puVar9 = puVar9 + 1;
      } while (iVar5 != 0);
      pbVar6 = &DAT_ffff9304 + (param_1 & 0xffff) * 3;
      *pbVar6 = *pbVar6 + 1;
      if (bVar1 <= *pbVar6) {
        (&DAT_ffff9304)[(param_1 & 0xffff) * 3] = 0;
      }
    }
    else {
      uVar7 = 1;
      FUN_0000a2b6((int)sVar2);
    }
  }
  FUN_00003934(uVar3);
  return uVar7;
}



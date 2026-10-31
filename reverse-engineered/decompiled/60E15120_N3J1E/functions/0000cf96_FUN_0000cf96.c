/* ROM address: 0x0000cf96; body bytes: 342; decompiled */

undefined4 * FUN_0000cf96(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  byte in_r7;
  byte bVar7;
  float fVar8;
  
  if (DAT_ffff9f96 == '\x01') {
    if ((DAT_ffff9f95 == '\0') && (DAT_ffffa3d8 = DAT_ffffa3d8 + 1, 2 < DAT_ffffa3d8)) {
      DAT_ffffa3d8 = 0;
    }
    puVar6 = &DAT_ffffa3d0;
    puVar4 = &DAT_ffffa3b4;
    in_r7 = DAT_ffff9f95 + DAT_ffffa3d8 * '$';
    bVar7 = DAT_ffffa3d6;
    do {
      if (in_r7 == bVar7) {
        uVar1 = ATUII_ICR0AH_W;
        *puVar4 = uVar1;
        *puVar6 = 1;
        break;
      }
      bVar7 = bVar7 + 0x12;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    } while (puVar4 < &DAT_ffffa3cc);
  }
  iVar5 = 0;
  bVar7 = DAT_ffffa3d6 + DAT_ffffa3d7;
  puVar4 = &DAT_0000d124;
  do {
    if ((in_r7 == bVar7) &&
       (puVar4 = (undefined4 *)(uint)(byte)(&DAT_ffffa3d0)[iVar5], puVar4 == (undefined4 *)0x1)) {
      iVar2 = ATUII_ICR0AH_W;
      DAT_ffffa3cc = iVar2 - (&DAT_ffffa3b4)[iVar5];
      DAT_ffffa3ac = DAT_ffffa3a8;
      DAT_ffffa3a8 = DAT_ffffa3a4;
      DAT_ffffa3a4 = DAT_ffffa3a0;
      DAT_ffffa3a0 = DAT_ffffa39c;
      DAT_ffffa39c = DAT_ffffa398;
      DAT_ffffa398 = DAT_ffffa394;
      DAT_ffffa394 = DAT_ffffa390;
      fVar8 = (float)DAT_ffffa3cc;
      if (DAT_ffffa3cc < 0) {
        fVar8 = fVar8 + 4.2949673e+09;
      }
      DAT_ffffa390 = ((float)DAT_ffffa3d7 * 6666666.0) / fVar8;
      DAT_ffffa3b0 = (undefined1)iVar5;
      puVar4 = (undefined4 *)FUN_0000a156();
      return puVar4;
    }
    iVar5 = iVar5 + 1;
    bVar3 = bVar7 + 0x12;
    if (0x6b < (byte)(bVar7 + 0x12)) {
      bVar3 = bVar7 + 0xa6;
    }
    bVar7 = bVar3;
  } while (iVar5 < 6);
  return puVar4;
}



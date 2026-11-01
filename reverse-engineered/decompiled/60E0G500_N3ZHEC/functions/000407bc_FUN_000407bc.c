/* ROM address: 0x000407bc; body bytes: 108; decompiled */

undefined2 * FUN_000407bc(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  
  DAT_ffffc778 = 0x3f800000;
  DAT_ffffc77c = 0x3f800000;
  DAT_ffffc780 = 0x3f800000;
  DAT_ffffc784 = 0x3f800000;
  DAT_ffffc95c = 0x3f800000;
  DAT_ffffc960 = 0x3f800000;
  DAT_ffffc964 = 0x3f800000;
  DAT_ffffc968 = 0x3f800000;
  puVar1 = &DAT_ffffc864;
  for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1) {
    *puVar1 = DAT_ffffc780;
    puVar1 = puVar1 + 1;
  }
  puVar1 = &DAT_ffffc8e0;
  for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1) {
    *puVar1 = DAT_ffffc784;
    puVar1 = puVar1 + 1;
  }
  DAT_ffffc820 = 0x20;
  return &DAT_0007aa3e;
}



/* ROM address: 0x0003f86c; body bytes: 108; decompiled */

undefined2 * FUN_0003f86c(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  
  DAT_ffffc708 = 0x3f800000;
  DAT_ffffc70c = 0x3f800000;
  DAT_ffffc710 = 0x3f800000;
  DAT_ffffc714 = 0x3f800000;
  DAT_ffffc8ec = 0x3f800000;
  DAT_ffffc8f0 = 0x3f800000;
  DAT_ffffc8f4 = 0x3f800000;
  DAT_ffffc8f8 = 0x3f800000;
  puVar1 = &DAT_ffffc7f4;
  for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1) {
    *puVar1 = DAT_ffffc710;
    puVar1 = puVar1 + 1;
  }
  puVar1 = &DAT_ffffc870;
  for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1) {
    *puVar1 = DAT_ffffc714;
    puVar1 = puVar1 + 1;
  }
  DAT_ffffc7b0 = 0x20;
  return &DAT_0007ac76;
}



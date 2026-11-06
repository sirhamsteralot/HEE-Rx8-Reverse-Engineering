/* [ADDITIONAL SOURCE REVIEW]
 * hcan_mailbox_config_compare [high]: Compares a desired HCAN mailbox descriptor array (param_2: 16 x 16-byte records for channel 0, 6 for channel 1) against live registers: HCAN0_BCR_W 0xffffe402 / HCAN1_BCR_W 0xffffe602 expect 0x803e; MBCR/MBIMR rebuilt from record bytes and compared (HCAN0_MBCR_W 0xffffe404, HCAN0_MBIMR_W 0xffffe414, HCAN1_MBCR_W 0xffffe604, HCAN1_MBIMR_W 0xffffe614); HCAN0_IMR_W 0xffffe416 / HCAN1_IMR_W 0xffffe616 expect 0xfcfe; HCAN0_LAFMH_W 0xffffe41e + HCAN0_LAFML_W 0xffffe41c (and HCAN1_LAFMH_W 0xffffe61e / HCAN1_LAFML_W 0xffffe61c) must be zero; per-mailbox MC control/data bytes checked at HCAN0_MC0[1]_B 0xffffe420 + 8*(mb&0xf) (MC0[5]/MC0[6]/MC0[7]/MC0[8] hold ID/DLC fields). Returns nonzero on any mismatch. Called from ref_canSetup 0xd9f4 (jsr @r13 at 0xda3e/0xda4e; pool 0xdb20 = 0x2a4f8) in a <=2-iteration retry loop with ref_CANControllerSetup(0, 0x4e01c or 0x4e11c, 0x10) and (1, 0x4e21c, 6); after >1 tries sets error flag 0xffffa410.
 */
/* ROM address: 0x0002a4f8; body bytes: 1218; decompiled */

bool hcan_mailbox_config_compare(char param_1,uint *param_2)

{
  short sVar1;
  uint *puVar2;
  ushort uVar3;
  uint uVar4;
  byte bVar5;
  uint *puVar6;
  int iVar7;
  bool bVar8;
  uint *puVar9;
  ushort uVar10;
  ushort uVar11;
  uint *puStack_28;
  uint *puStack_24;
  
  if (param_1 == '\0') {
    sVar1 = -0x1c00;
  }
  else {
    sVar1 = -0x1a00;
  }
  bVar8 = *(char *)(int)sVar1 != '\0';
  if (param_1 == '\0') {
    sVar1 = HCAN0_BCR_W;
    if (sVar1 != -0x7fc2) {
      bVar8 = true;
    }
  }
  else {
    sVar1 = HCAN1_BCR_W;
    if (sVar1 != -0x7fc2) {
      bVar8 = true;
    }
  }
  if (param_1 == '\0') {
    uVar3 = 0x100;
    bVar5 = 0;
    puVar6 = param_2;
    puVar9 = param_2;
    do {
      uVar11 = 1;
      for (uVar10 = *(byte *)((int)puVar6 + 5) + 8 & 0xf; uVar10 != 0; uVar10 = uVar10 - 1) {
        uVar11 = uVar11 << 1;
      }
      uVar3 = uVar11 * *(byte *)(puVar9 + 1) | uVar3 & ~uVar11;
      puVar2 = puVar9 + 3;
      puVar9 = puVar9 + 4;
      bVar5 = bVar5 + 1;
      puVar6 = puVar6 + 4;
    } while (bVar5 < 0x10);
    uVar10 = HCAN0_MBCR_W;
    if (uVar10 != uVar3) {
      bVar8 = true;
    }
    sVar1 = HCAN0_MBIMR_W;
    if (sVar1 != (ushort)(uVar11 * *(byte *)puVar2)) {
      bVar8 = true;
    }
  }
  else {
    uVar3 = 0x100;
    bVar5 = 0;
    puVar6 = param_2;
    puVar9 = param_2;
    do {
      uVar11 = 1;
      for (uVar10 = *(byte *)((int)puVar6 + 5) + 8 & 0xf; uVar10 != 0; uVar10 = uVar10 - 1) {
        uVar11 = uVar11 << 1;
      }
      uVar3 = uVar11 * *(byte *)(puVar9 + 1) | uVar3 & ~uVar11;
      puVar2 = puVar9 + 3;
      puVar9 = puVar9 + 4;
      bVar5 = bVar5 + 1;
      puVar6 = puVar6 + 4;
    } while (bVar5 < 6);
    uVar10 = HCAN1_MBCR_W;
    if (uVar10 != uVar3) {
      bVar8 = true;
    }
    sVar1 = HCAN1_MBIMR_W;
    if (sVar1 != (ushort)(uVar11 * *(byte *)puVar2)) {
      bVar8 = true;
    }
  }
  if (param_1 == '\0') {
    sVar1 = HCAN0_IMR_W;
    if (sVar1 != -0x302) {
      bVar8 = true;
    }
  }
  else {
    sVar1 = HCAN1_IMR_W;
    if (sVar1 != -0x302) {
      bVar8 = true;
    }
  }
  if (param_1 == '\0') {
    sVar1 = -0x1be2;
  }
  else {
    sVar1 = -0x19e2;
  }
  if (*(short *)(int)sVar1 != 0) {
    bVar8 = true;
  }
  if (param_1 == '\0') {
    sVar1 = -0x1be4;
  }
  else {
    sVar1 = -0x19e4;
  }
  if (*(short *)(int)sVar1 != 0) {
    bVar8 = true;
  }
  puStack_24 = param_2;
  if (param_1 == '\0') {
    bVar5 = 0;
    puVar6 = param_2;
    do {
      bVar5 = bVar5 + 1;
      if ((&HCAN0_MC0_1__B)[(*(byte *)((int)puVar6 + 5) & 0xf) * 8] != *(char *)((int)puVar6 + 6)) {
        bVar8 = true;
      }
      puVar6 = puVar6 + 4;
    } while (bVar5 < 0x10);
    bVar5 = 0;
    puVar6 = param_2;
    puVar9 = param_2;
    do {
      iVar7 = (*(byte *)((int)param_2 + (uint)bVar5 * 0x10 + 5) & 0xf) * 8;
      if (*(char *)((int)param_2 + (uint)bVar5 * 0x10 + 7) == '\0') {
        if ((&HCAN0_MC0_5__B)[iVar7] !=
            (char)(*(char *)((int)(param_2 + (uint)bVar5 * 4) + 7) * '\b' +
                  (char)param_2[(uint)bVar5 * 4] * ' ')) {
          bVar8 = true;
        }
        if ((uint)(byte)(&HCAN0_MC0_6__B)[iVar7] != (param_2[(uint)bVar5 * 4] >> 3 & 0xff)) {
          bVar8 = true;
        }
      }
      else {
        uVar4 = param_2[(uint)bVar5 * 4];
        if ((&HCAN0_MC0_5__B)[iVar7] !=
            (byte)(*(char *)((int)(param_2 + (uint)bVar5 * 4) + 7) * '\b' +
                   (char)(uVar4 >> 0x12) * ' ' + ((byte)(uVar4 >> 0x10) & 3))) {
          bVar8 = true;
        }
        if ((&HCAN0_MC0_6__B)[iVar7] != (char)(*puVar9 >> 0x15)) {
          bVar8 = true;
        }
        if ((&HCAN0_MC0_7__B)[iVar7] != (char)*puStack_24) {
          bVar8 = true;
        }
        if ((uint)(byte)(&HCAN0_MC0_8__B)[iVar7] != (*puVar6 >> 8 & 0xff)) {
          bVar8 = true;
        }
      }
      bVar5 = bVar5 + 1;
      puVar6 = puVar6 + 4;
      puStack_24 = puStack_24 + 4;
      puVar9 = puVar9 + 4;
    } while (bVar5 < 0x10);
  }
  else {
    bVar5 = 0;
    puVar6 = param_2;
    do {
      bVar5 = bVar5 + 1;
      if ((&HCAN1_MC0_1__B)[(*(byte *)((int)puVar6 + 5) & 0xf) * 8] != *(char *)((int)puVar6 + 6)) {
        bVar8 = true;
      }
      puVar6 = puVar6 + 4;
    } while (bVar5 < 6);
    bVar5 = 0;
    puVar6 = param_2;
    puStack_28 = param_2;
    do {
      puVar9 = param_2 + (uint)bVar5 * 4;
      iVar7 = (*(byte *)((int)puVar9 + 5) & 0xf) * 8;
      if (*(char *)((int)puVar9 + 7) == '\0') {
        if ((&HCAN1_MC0_5__B)[iVar7] !=
            (char)(*(char *)((int)puVar9 + 7) * '\b' + (char)*puVar9 * ' ')) {
          bVar8 = true;
        }
        if ((uint)(byte)(&HCAN1_MC0_6__B)[iVar7] != (*puVar9 >> 3 & 0xff)) {
          bVar8 = true;
        }
      }
      else {
        if ((uint)(byte)(&HCAN1_MC0_5__B)[iVar7] !=
            ((uint)*(byte *)((int)puVar9 + 7) * 8 + (*puVar9 >> 0x12 & 7) * 0x20 +
             (*puVar9 >> 0x10 & 3) & 0xff)) {
          bVar8 = true;
        }
        if ((uint)(byte)(&HCAN1_MC0_6__B)[iVar7] != (*puStack_24 >> 0x15 & 0xff)) {
          bVar8 = true;
        }
        if ((uint)(byte)(&HCAN1_MC0_7__B)[iVar7] != (*puStack_28 & 0xff)) {
          bVar8 = true;
        }
        if ((uint)(byte)(&HCAN1_MC0_8__B)[iVar7] != (*puVar6 >> 8 & 0xff)) {
          bVar8 = true;
        }
      }
      bVar5 = bVar5 + 1;
      puStack_28 = puStack_28 + 4;
      puStack_24 = puStack_24 + 4;
      puVar6 = puVar6 + 4;
    } while (bVar5 < 6);
  }
  return bVar8;
}



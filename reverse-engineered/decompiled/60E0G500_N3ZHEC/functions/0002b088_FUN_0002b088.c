/* ROM address: 0x0002b088; body bytes: 1218; decompiled */

bool FUN_0002b088(char param_1,uint *param_2)

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
    sVar1 = DAT_ffffe402;
    if (sVar1 != -0x7fc2) {
      bVar8 = true;
    }
  }
  else {
    sVar1 = DAT_ffffe602;
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
    uVar10 = DAT_ffffe404;
    if (uVar10 != uVar3) {
      bVar8 = true;
    }
    sVar1 = DAT_ffffe414;
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
    uVar10 = DAT_ffffe604;
    if (uVar10 != uVar3) {
      bVar8 = true;
    }
    sVar1 = DAT_ffffe614;
    if (sVar1 != (ushort)(uVar11 * *(byte *)puVar2)) {
      bVar8 = true;
    }
  }
  if (param_1 == '\0') {
    sVar1 = DAT_ffffe416;
    if (sVar1 != -0x302) {
      bVar8 = true;
    }
  }
  else {
    sVar1 = DAT_ffffe616;
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
      if ((&DAT_ffffe420)[(*(byte *)((int)puVar6 + 5) & 0xf) * 8] != *(char *)((int)puVar6 + 6)) {
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
        if ((&DAT_ffffe424)[iVar7] !=
            (char)(*(char *)((int)(param_2 + (uint)bVar5 * 4) + 7) * '\b' +
                  (char)param_2[(uint)bVar5 * 4] * ' ')) {
          bVar8 = true;
        }
        if ((uint)(byte)(&DAT_ffffe425)[iVar7] != (param_2[(uint)bVar5 * 4] >> 3 & 0xff)) {
          bVar8 = true;
        }
      }
      else {
        uVar4 = param_2[(uint)bVar5 * 4];
        if ((&DAT_ffffe424)[iVar7] !=
            (byte)(*(char *)((int)(param_2 + (uint)bVar5 * 4) + 7) * '\b' +
                   (char)(uVar4 >> 0x12) * ' ' + ((byte)(uVar4 >> 0x10) & 3))) {
          bVar8 = true;
        }
        if ((&DAT_ffffe425)[iVar7] != (char)(*puVar9 >> 0x15)) {
          bVar8 = true;
        }
        if ((&DAT_ffffe426)[iVar7] != (char)*puStack_24) {
          bVar8 = true;
        }
        if ((uint)(byte)(&DAT_ffffe427)[iVar7] != (*puVar6 >> 8 & 0xff)) {
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
      if ((&DAT_ffffe620)[(*(byte *)((int)puVar6 + 5) & 0xf) * 8] != *(char *)((int)puVar6 + 6)) {
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
        if ((&DAT_ffffe624)[iVar7] !=
            (char)(*(char *)((int)puVar9 + 7) * '\b' + (char)*puVar9 * ' ')) {
          bVar8 = true;
        }
        if ((uint)(byte)(&DAT_ffffe625)[iVar7] != (*puVar9 >> 3 & 0xff)) {
          bVar8 = true;
        }
      }
      else {
        if ((uint)(byte)(&DAT_ffffe624)[iVar7] !=
            ((uint)*(byte *)((int)puVar9 + 7) * 8 + (*puVar9 >> 0x12 & 7) * 0x20 +
             (*puVar9 >> 0x10 & 3) & 0xff)) {
          bVar8 = true;
        }
        if ((uint)(byte)(&DAT_ffffe625)[iVar7] != (*puStack_24 >> 0x15 & 0xff)) {
          bVar8 = true;
        }
        if ((uint)(byte)(&DAT_ffffe626)[iVar7] != (*puStack_28 & 0xff)) {
          bVar8 = true;
        }
        if ((uint)(byte)(&DAT_ffffe627)[iVar7] != (*puVar6 >> 8 & 0xff)) {
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



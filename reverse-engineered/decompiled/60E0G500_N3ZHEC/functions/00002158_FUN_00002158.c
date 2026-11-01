/* ROM address: 0x00002158; body bytes: 420; decompiled */

undefined8 FUN_00002158(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int in_r1;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar11;
  uint uVar14;
  
  iVar7 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      iVar7 = ((param_1 & 0x80000000) != 0) + 0x7fffffff;
      in_r1 = 0x7fffffff;
    }
    else if (((param_1 & 0x7fffffff) != 0) || (in_r1 = -1, iVar7 = 0x7fffffff, param_2 != -1)) {
      uVar8 = -(uint)((param_1 & 0x80000000) != 0);
      uVar15 = param_1 - ((uVar8 & 0x80000000) != 0);
      uVar8 = uVar8 - (param_1 < uVar15);
      bVar1 = param_2 < 0;
      uVar2 = (uint)bVar1 << 9;
      uVar13 = uVar15 * 2;
      uVar15 = uVar8 * 2 | (uint)((uVar15 & 0x80000000) != 0);
      bVar4 = (int)uVar8 < 0 == bVar1;
      bVar5 = bVar1 == ((uVar8 & 0x80000000) != 0);
      uVar9 = (uint)bVar4 * (uVar15 - param_2) + (uint)!bVar4 * (uVar15 + param_2);
      cVar3 = bVar4 * (uVar15 < uVar9) + !bVar4 * (uVar9 < uVar15);
      uVar15 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar14 = uVar2 | uVar15;
      uVar10 = uVar9 * 2 | (uint)((uVar13 & 0x80000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar10 - param_2) + (uint)!bVar4 * (uVar10 + param_2);
      cVar3 = bVar4 * (uVar10 < uVar11) + !bVar4 * (uVar11 < uVar10);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar17 = uVar2 | uVar15 & 0xfffffeff | uVar14;
      uVar10 = uVar2 | uVar15 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar18 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar19 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar20 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar21 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar22 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar23 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar24 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar25 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar26 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar27 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar28 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar29 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar30 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar31 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar32 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar33 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar34 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar35 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar36 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar37 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar38 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar39 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar40 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar41 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar42 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar43 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar44 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 8) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar45 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 4) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar12 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar13 = uVar11 * 2 | (uint)((uVar13 & 2) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar14 = (uint)bVar4 * (uVar13 - param_2) + (uint)!bVar4 * (uVar13 + param_2);
      cVar3 = bVar4 * (uVar13 < uVar14) + !bVar4 * (uVar14 < uVar13);
      uVar14 = uVar10 | uVar9 & 0xfffffeff |
               (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      iVar16 = ((((((((((((((((((((((((((((((((uint)(((byte)((uVar2 | uVar15) >> 8) & 1) ==
                                                    ((byte)((uVar2 | uVar15) >> 9) & 1)) << 1 |
                                             (uint)(((byte)(uVar17 >> 8) & 1) ==
                                                   ((byte)(uVar17 >> 9) & 1))) << 1 |
                                            (uint)(((byte)(uVar18 >> 8) & 1) ==
                                                  ((byte)(uVar18 >> 9) & 1))) << 1 |
                                           (uint)(((byte)(uVar19 >> 8) & 1) ==
                                                 ((byte)(uVar19 >> 9) & 1))) << 1 |
                                          (uint)(((byte)(uVar20 >> 8) & 1) ==
                                                ((byte)(uVar20 >> 9) & 1))) << 1 |
                                         (uint)(((byte)(uVar21 >> 8) & 1) ==
                                               ((byte)(uVar21 >> 9) & 1))) << 1 |
                                        (uint)(((byte)(uVar22 >> 8) & 1) ==
                                              ((byte)(uVar22 >> 9) & 1))) << 1 |
                                       (uint)(((byte)(uVar23 >> 8) & 1) == ((byte)(uVar23 >> 9) & 1)
                                             )) << 1 |
                                      (uint)(((byte)(uVar24 >> 8) & 1) == ((byte)(uVar24 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar25 >> 8) & 1) ==
                                                     ((byte)(uVar25 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar27 >> 8) & 1) ==
                                                 ((byte)(uVar27 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar28 >> 8) & 1) == ((byte)(uVar28 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar30 >> 8) & 1) ==
                                                ((byte)(uVar30 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar33 >> 8) & 1) == ((byte)(uVar33 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar41 >> 8) & 1) == ((byte)(uVar41 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar42 >> 8) & 1) == ((byte)(uVar42 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar43 >> 8) & 1) == ((byte)(uVar43 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar44 >> 8) & 1) == ((byte)(uVar44 >> 9) & 1))) << 1 |
                 (uint)(((byte)(uVar45 >> 8) & 1) == ((byte)(uVar45 >> 9) & 1))) << 1 |
                (uint)(((byte)(uVar12 >> 8) & 1) == ((byte)(uVar12 >> 9) & 1))) << 1 |
               (uint)(((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1))) +
               (uint)(bVar1 != (int)uVar8 < 0);
      iVar6 = 0x7fffffff;
      iVar7 = 0x7fff;
      if (iVar16 < 0x8000) {
        iVar6 = -0x80000000;
        iVar7 = -0x8000;
        if (-0x8001 < iVar16) {
          iVar7 = param_1 << 1;
          uVar2 = (uint)((param_1 & 0x80000000) != 0) * -2;
          uVar15 = param_1 * 0x10000 - (uint)((uVar2 & 0x10000) != 0);
          uVar10 = ((((((((((((((((uVar2 | (param_1 & 0x80000000) != 0) << 1 |
                                 (uint)((param_1 & 0x40000000) != 0)) << 1 |
                                (uint)((param_1 & 0x20000000) != 0)) << 1 |
                               (uint)((param_1 & 0x10000000) != 0)) << 1 |
                              (uint)((param_1 & 0x8000000) != 0)) << 1 |
                             (uint)((param_1 & 0x4000000) != 0)) << 1 |
                            (uint)((param_1 & 0x2000000) != 0)) << 1 |
                           (uint)((param_1 & 0x1000000) != 0)) << 1 |
                          (uint)((param_1 & 0x800000) != 0)) << 1 |
                         (uint)((param_1 & 0x400000) != 0)) << 1 | (uint)((param_1 & 0x200000) != 0)
                        ) << 1 | (uint)((param_1 & 0x100000) != 0)) << 1 |
                      (uint)((param_1 & 0x80000) != 0)) << 1 | (uint)((param_1 & 0x40000) != 0)) <<
                     1 | (uint)((param_1 & 0x20000) != 0)) << 1 | (uint)((param_1 & 0x10000) != 0))
                   - (uint)(param_1 * 0x10000 < uVar15);
          bVar1 = param_2 < 0;
          uVar2 = (uint)bVar1 << 9;
          uVar13 = uVar15 * 2;
          uVar15 = uVar10 * 2 | (uint)((uVar15 & 0x80000000) != 0);
          bVar4 = (int)uVar10 < 0 == bVar1;
          bVar5 = bVar1 == ((uVar10 & 0x80000000) != 0);
          uVar9 = (uint)bVar4 * (uVar15 - param_2) + (uint)!bVar4 * (uVar15 + param_2);
          cVar3 = bVar4 * (uVar15 < uVar9) + !bVar4 * (uVar9 < uVar15);
          uVar15 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar14 = uVar2 | uVar15;
          uVar8 = uVar9 * 2 | (uint)((uVar13 & 0x80000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar8 - param_2) + (uint)!bVar4 * (uVar8 + param_2);
          cVar3 = bVar4 * (uVar8 < uVar11) + !bVar4 * (uVar11 < uVar8);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar17 = uVar2 | uVar15 & 0xfffffeff | uVar14;
          uVar8 = uVar2 | uVar15 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar18 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar19 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar20 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar21 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar22 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar23 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar24 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar25 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar26 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar27 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar28 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar29 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar30 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar31 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar32 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar33 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar34 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar35 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar36 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar37 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar38 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar39 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar40 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar41 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar42 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar43 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar44 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 8) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar45 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 4) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar12 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar13 = uVar11 * 2 | (uint)((uVar13 & 2) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar14 = (uint)bVar4 * (uVar13 - param_2) + (uint)!bVar4 * (uVar13 + param_2);
          cVar3 = bVar4 * (uVar13 < uVar14) + !bVar4 * (uVar14 < uVar13);
          uVar14 = uVar8 | uVar9 & 0xfffffeff |
                   (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          iVar6 = ((((((((((((((((((((((((((((((((uint)(((byte)((uVar2 | uVar15) >> 8) & 1) ==
                                                       ((byte)((uVar2 | uVar15) >> 9) & 1)) << 1 |
                                                (uint)(((byte)(uVar17 >> 8) & 1) ==
                                                      ((byte)(uVar17 >> 9) & 1))) << 1 |
                                               (uint)(((byte)(uVar18 >> 8) & 1) ==
                                                     ((byte)(uVar18 >> 9) & 1))) << 1 |
                                              (uint)(((byte)(uVar19 >> 8) & 1) ==
                                                    ((byte)(uVar19 >> 9) & 1))) << 1 |
                                             (uint)(((byte)(uVar20 >> 8) & 1) ==
                                                   ((byte)(uVar20 >> 9) & 1))) << 1 |
                                            (uint)(((byte)(uVar21 >> 8) & 1) ==
                                                  ((byte)(uVar21 >> 9) & 1))) << 1 |
                                           (uint)(((byte)(uVar22 >> 8) & 1) ==
                                                 ((byte)(uVar22 >> 9) & 1))) << 1 |
                                          (uint)(((byte)(uVar23 >> 8) & 1) ==
                                                ((byte)(uVar23 >> 9) & 1))) << 1 |
                                         (uint)(((byte)(uVar24 >> 8) & 1) ==
                                               ((byte)(uVar24 >> 9) & 1))) << 1 |
                                        (uint)(((byte)(uVar25 >> 8) & 1) ==
                                              ((byte)(uVar25 >> 9) & 1))) << 1 |
                                       (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1)
                                             )) << 1 |
                                      (uint)(((byte)(uVar27 >> 8) & 1) == ((byte)(uVar27 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar28 >> 8) & 1) ==
                                                     ((byte)(uVar28 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar30 >> 8) & 1) ==
                                                 ((byte)(uVar30 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar33 >> 8) & 1) ==
                                                ((byte)(uVar33 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar41 >> 8) & 1) == ((byte)(uVar41 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar42 >> 8) & 1) == ((byte)(uVar42 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar43 >> 8) & 1) == ((byte)(uVar43 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar44 >> 8) & 1) == ((byte)(uVar44 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar45 >> 8) & 1) == ((byte)(uVar45 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar12 >> 8) & 1) == ((byte)(uVar12 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1))) +
                  (uint)(bVar1 != (int)uVar10 < 0);
        }
      }
      return CONCAT44(iVar7,iVar6);
    }
  }
  return CONCAT44(in_r1,iVar7);
}



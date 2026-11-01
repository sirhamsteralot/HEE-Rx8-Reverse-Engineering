/* ROM address: 0x00045d64; body bytes: 612; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00045d9e) */
/* WARNING: Removing unreachable block (ram,0x00045d88) */

uint FUN_00045d64(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar4;
  uint uVar3;
  ushort uVar5;
  
  uVar2 = DAT_ffffcc26;
  DAT_ffffcc16 = DAT_ffffcc26;
  DAT_ffffcc26 = DAT_ffffcc24;
  DAT_ffffcc24 = DAT_ffffadd4;
  if (DAT_ffffb53c <= uVar2) {
    uVar5 = uVar2 - DAT_ffffb53c;
  }
  else {
    uVar5 = DAT_ffffb53c - uVar2;
  }
  bVar1 = DAT_ffffb53c > uVar2;
  if (((bool)DAT_ffffcc2a == bVar1) && (DAT_ffffcc22 != '\0')) {
    if (uVar5 < 0x5f0) {
      DAT_ffffcc18 = 0;
    }
    if (uVar5 < 0x937) {
      DAT_ffffcc1a = 0;
    }
    if (uVar5 < 0xc4a) {
      DAT_ffffcc1c = 0;
    }
    if (uVar5 < 0x1168) {
      DAT_ffffcc1e = 0;
    }
    if (uVar5 < 0x154d) {
      DAT_ffffcc20 = 0;
    }
    if (0x5ef < uVar5) {
      DAT_ffffcc18 = FUN_00002460((int)(short)DAT_ffffcc18,1);
    }
    if (0x936 < uVar5) {
      DAT_ffffcc1a = FUN_00002460((int)(short)DAT_ffffcc1a,1);
    }
    if (0xc49 < uVar5) {
      DAT_ffffcc1c = FUN_00002460((int)(short)DAT_ffffcc1c,1);
    }
    if (0x1167 < uVar5) {
      DAT_ffffcc1e = FUN_00002460((int)(short)DAT_ffffcc1e,1);
    }
    if (0x154c < uVar5) {
      DAT_ffffcc20 = FUN_00002460((int)(short)DAT_ffffcc20,1);
    }
  }
  else {
    DAT_ffffcc18 = 0;
    DAT_ffffcc1a = 0;
    DAT_ffffcc1c = 0;
    DAT_ffffcc1e = 0;
    DAT_ffffcc20 = 0;
  }
  DAT_ffffcc2a = bVar1;
  if ((DAT_ffffcc22 == '\x01') &&
     ((((0x5d < DAT_ffffcc18 || (0x44 < DAT_ffffcc1a)) || (0x31 < DAT_ffffcc1c)) ||
      ((0x25 < DAT_ffffcc1e || (0x1e < DAT_ffffcc20)))))) {
    FUN_0003ebc0(&DAT_ffff8750,1);
    DAT_ffffcc28 = 0;
  }
  else if ((DAT_ffffcc22 == '\x01') &&
          (((DAT_ffffcc18 == 0 && (DAT_ffffcc1a == 0)) &&
           ((DAT_ffffcc1c == 0 && ((DAT_ffffcc1e == 0 && (DAT_ffffcc20 == 0)))))))) {
    if (0xf9 < DAT_ffffcc28) {
      DAT_ffffcc14 = 1;
    }
    DAT_ffffcc28 = FUN_00002460((int)(short)DAT_ffffcc28,1);
  }
  else {
    DAT_ffffcc28 = 0;
  }
  cVar4 = FUN_0003eaa4(&DAT_ffff8750,0);
  if (cVar4 != '\x01') {
    if (DAT_ffffcc14 != 1) {
      return (uint)DAT_ffffcc14;
    }
    uVar3 = FUN_000604dc(0x4e,2);
    return uVar3;
  }
  uVar3 = FUN_000604dc(0x4e,1);
  return uVar3;
}



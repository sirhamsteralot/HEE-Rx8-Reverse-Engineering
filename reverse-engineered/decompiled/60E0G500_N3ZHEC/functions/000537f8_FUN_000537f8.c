/* ROM address: 0x000537f8; body bytes: 238; decompiled */

undefined1 * FUN_000537f8(void)

{
  ushort uVar1;
  ushort uVar2;
  float fVar3;
  ushort uVar5;
  undefined1 *puVar4;
  undefined1 *puVar6;
  float fVar7;
  float fVar8;
  
  uVar2 = DAT_ffffcfe6;
  uVar1 = DAT_ffffcfe4;
  fVar7 = DAT_ffffd01c - DAT_ffffd188;
  fVar8 = DAT_ffffd01c;
  uVar5 = FUN_00002460((int)(short)DAT_ffffcfe4,1);
  puVar6 = (undefined1 *)(uint)DAT_ffffd002;
  if ((uVar2 < uVar5) && (DAT_ffffd002 == 1)) {
    DAT_ffffd17c = 0.0;
    fVar3 = DAT_ffffd17c;
  }
  else {
    fVar3 = DAT_ffffd17c;
    if ((puVar6 == (undefined1 *)0x1) &&
       (((fVar3 = fVar7, uVar2 != uVar5 && (DAT_ffffd180 != 1)) &&
        (fVar3 = DAT_ffffd17c, DAT_ffffd180 < 3)))) {
      fVar3 = DAT_ffffd17c + fVar7;
    }
  }
  DAT_ffffd17c = fVar3;
  puVar4 = (undefined1 *)0x1;
  if (DAT_ffffcfb4 != '\x01') {
    if (puVar6 != (undefined1 *)0x1) {
      DAT_ffffd188 = fVar8;
      return puVar6;
    }
    puVar4 = (undefined1 *)0x1;
    if ((uVar2 != uVar5) && (puVar4 = &DAT_ffffd180, DAT_ffffd180 != 2)) {
      if (1 < DAT_ffffd180) {
        DAT_ffffd188 = fVar8;
        return puVar4;
      }
      if (uVar2 <= uVar1) {
        DAT_ffffd188 = fVar8;
        return puVar4;
      }
      DAT_ffffd188 = fVar8;
      puVar6 = (undefined1 *)FUN_00002478((int)(char)DAT_ffffd180,1);
      DAT_ffffd180 = (char)puVar6;
      return puVar6;
    }
  }
  DAT_ffffd188 = fVar8;
  DAT_ffffd180 = 1;
  return puVar4;
}



/* ROM address: 0x000667c8; body bytes: 210; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000650b8 (210 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000667c8(char param_1,undefined2 *param_2,ushort *param_3,byte param_4)

{
  ushort uVar2;
  uint uVar1;
  undefined2 *puVar3;
  int iVar4;
  ushort uVar6;
  ushort *puVar5;
  uint uVar7;
  
  uVar6 = 1;
  uVar2 = 0;
  uVar7 = 0;
  if ((param_1 == '\x01') || (param_1 == '\x03')) {
    uVar2 = FUN_00067bbc(0);
  }
  else if (param_1 == '\a') {
    uVar2 = FUN_00067c1a(0);
  }
  puVar3 = &DAT_0007e55c;
  do {
    if ((uVar6 & uVar2) != 0) {
      uVar1 = uVar7 & 0xff;
      uVar7 = uVar7 + 1;
      param_2[uVar1] = *puVar3;
    }
    uVar6 = uVar6 << 1;
    puVar3 = puVar3 + 1;
  } while (puVar3 < &UNK_0007e567);
  iVar4 = 0;
  if (1 < (uVar7 & 0xff)) {
    uVar7 = 1;
    *param_2 = 0x300;
  }
  puVar5 = param_3;
  if (param_4 != 0) {
    do {
      uVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      if ((uVar2 != 0) && (uVar2 != 1)) {
        uVar1 = uVar7 & 0xff;
        uVar7 = uVar7 + 1;
        param_2[uVar1] = (&DAT_0007e560)[*param_3];
      }
      iVar4 = iVar4 + 1;
      param_3 = param_3 + 1;
    } while (iVar4 < (int)(uint)param_4);
  }
  return uVar7;
}



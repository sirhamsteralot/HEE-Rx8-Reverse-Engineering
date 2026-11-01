/* ROM address: 0x00063eaa; body bytes: 258; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00063eaa(undefined4 param_1,byte param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  uVar3 = (uint)DAT_ffff8d74;
  uVar2 = 3;
  bVar4 = DAT_ffff8938;
  if (uVar3 == 0) {
    bVar4 = DAT_ffff896c;
  }
  uVar5 = (uint)(uVar3 == 0);
  uVar1 = 0;
  do {
    if (uVar1 != uVar3) {
      if (bVar4 < (&DAT_ffff8938)[uVar1 * 0x34]) {
        bVar4 = (&DAT_ffff8938)[uVar1 * 0x34];
        uVar5 = uVar1;
      }
      else if (bVar4 == (&DAT_ffff8938)[uVar1 * 0x34]) {
        if ((&DAT_ffff8937)[uVar1 * 0x34] == '\x10') {
          if ((ushort)(&DAT_ffff8932)[(uVar5 & 0xffff) * 0x1a] <
              (ushort)(&DAT_ffff8932)[uVar1 * 0x1a]) {
            uVar5 = uVar1;
          }
        }
        else if (((&DAT_ffff8937)[uVar1 * 0x34] == -0x40) &&
                ((ushort)(&DAT_ffff8934)[(uVar5 & 0xffff) * 0x1a] <
                 (ushort)(&DAT_ffff8934)[uVar1 * 0x1a])) {
          uVar5 = uVar1;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x15);
  if (param_2 < bVar4) {
    *param_3 = (&DAT_ffff8930)[(uVar5 & 0xffff) * 0x1a];
    _DAT_ffff8d78 = FUN_00002430(uVar5);
    uVar2 = 2;
  }
  return uVar2;
}



/* ROM address: 0x00063706; body bytes: 258; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00063706(undefined4 param_1,byte param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  uVar3 = (uint)DAT_ffff8d4c._0_2_;
  uVar2 = 3;
  bVar4 = DAT_ffff8910;
  if (uVar3 == 0) {
    bVar4 = DAT_ffff8944;
  }
  uVar5 = (uint)(uVar3 == 0);
  uVar1 = 0;
  do {
    if (uVar1 != uVar3) {
      if (bVar4 < (&DAT_ffff8910)[uVar1 * 0x34]) {
        bVar4 = (&DAT_ffff8910)[uVar1 * 0x34];
        uVar5 = uVar1;
      }
      else if (bVar4 == (&DAT_ffff8910)[uVar1 * 0x34]) {
        if ((&DAT_ffff890f)[uVar1 * 0x34] == '\x10') {
          if ((ushort)(&DAT_ffff890a)[(uVar5 & 0xffff) * 0x1a] <
              (ushort)(&DAT_ffff890a)[uVar1 * 0x1a]) {
            uVar5 = uVar1;
          }
        }
        else if (((&DAT_ffff890f)[uVar1 * 0x34] == -0x40) &&
                ((ushort)(&DAT_ffff890c)[(uVar5 & 0xffff) * 0x1a] <
                 (ushort)(&DAT_ffff890c)[uVar1 * 0x1a])) {
          uVar5 = uVar1;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x15);
  if (param_2 < bVar4) {
    *param_3 = (&DAT_ffff8908)[(uVar5 & 0xffff) * 0x1a];
    _DAT_ffff8d50 = rx8_pack_u16_with_complement(uVar5);
    uVar2 = 2;
  }
  return uVar2;
}



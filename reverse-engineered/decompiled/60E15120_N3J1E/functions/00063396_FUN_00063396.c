/* ROM address: 0x00063396; body bytes: 290; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061c86 (290 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 FUN_00063396(undefined4 param_1,byte param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  undefined1 local_20;
  
  local_20 = 3;
  uVar2 = (uint)dtc_master_current_index_ffff8900._0_2_;
  bVar3 = DAT_ffff87bd;
  if (uVar2 == 0) {
    bVar3 = DAT_ffff87cd;
  }
  uVar4 = (uint)(uVar2 == 0);
  uVar1 = 0;
  do {
    if (uVar1 != uVar2) {
      if (bVar3 < (&DAT_ffff87bd)[uVar1 * 0x10]) {
        bVar3 = (&DAT_ffff87bd)[uVar1 * 0x10];
        uVar4 = uVar1;
      }
      else if (bVar3 == (&DAT_ffff87bd)[uVar1 * 0x10]) {
        if (((&DAT_ffff87b6)[uVar1 * 0x10] == 0) || (0x3f < (byte)(&DAT_ffff87b6)[uVar1 * 0x10])) {
          if ((((&DAT_ffff87b6)[uVar1 * 0x10] & 0x80) == 0x80) &&
             ((ushort)(&DAT_ffff87b4)[(uVar4 & 0xffff) * 8] < (ushort)(&DAT_ffff87b4)[uVar1 * 8])) {
            uVar4 = uVar1;
          }
        }
        else if ((ushort)(&DAT_ffff87b2)[(uVar4 & 0xffff) * 8] < (ushort)(&DAT_ffff87b2)[uVar1 * 8])
        {
          uVar4 = uVar1;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x15);
  if (param_2 < bVar3) {
    *param_3 = (&dtc_master_table_21_ffff87b0)[(uVar4 & 0xffff) * 8];
    _DAT_ffff8904 = rx8_pack_u16_with_complement(uVar4);
    local_20 = 2;
  }
  return local_20;
}



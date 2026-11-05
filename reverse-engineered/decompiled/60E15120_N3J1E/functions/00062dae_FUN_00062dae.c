/* ROM address: 0x00062dae; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006169e (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062dae(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)dtc_master_current_index_ffff8900._0_2_;
  iVar3 = uVar2 * 0x10;
  uVar1 = (&dtc_master_table_21_ffff87b0)[uVar2 * 8];
  (&DAT_ffff87be)[iVar3] =
       (&DAT_ffff87be)[iVar3] +
       (((char)uVar1 + (char)((ushort)uVar1 >> 8)) - ((char)((uint)param_1 >> 8) + (char)param_1));
  (&dtc_master_table_21_ffff87b0)[uVar2 * 8] = (short)param_1;
  return;
}



/* ROM address: 0x000642da; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062bca (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_000642da(ushort *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if (puVar1 == (undefined *)((int)&vector_Illegal_instr + 1)) {
    puVar1 = &DAT_0007e442;
    if (*(byte *)((int)param_1 + 9) < (byte)(&DAT_0007e442)[*param_1]) {
      puVar1 = (undefined *)FUN_00062ebc((char)*(byte *)((int)param_1 + 9) + 1);
      return puVar1;
    }
  }
  return puVar1;
}



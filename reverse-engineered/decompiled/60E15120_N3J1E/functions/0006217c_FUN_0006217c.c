/* ROM address: 0x0006217c; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060a6c (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_0006217c(ushort *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if (((puVar1 != &UNK_00000020) &&
      (puVar1 = (undefined *)(uint)DAT_ffff8e7e,
      puVar1 == (undefined *)((int)&vector_Poweron_Reset + 1))) &&
     (puVar1 = &DAT_0007e442, (byte)(&DAT_0007e442)[*param_1] <= *(byte *)((int)param_1 + 9))) {
    puVar1 = &DAT_0007e4ce;
    if (*(byte *)(param_1 + 4) < (byte)(&DAT_0007e4ce)[*param_1]) {
      puVar1 = (undefined *)FUN_00062f2e((char)*(byte *)(param_1 + 4) + 1);
      return puVar1;
    }
  }
  return puVar1;
}



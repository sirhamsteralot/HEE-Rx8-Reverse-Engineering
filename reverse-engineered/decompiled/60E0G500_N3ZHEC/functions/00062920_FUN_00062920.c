/* ROM address: 0x00062920; body bytes: 92; decompiled */

undefined * FUN_00062920(ushort *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2];
  if (((puVar1 != &UNK_00000020) &&
      (puVar1 = (undefined *)(uint)DAT_ffff8ea6, puVar1 == &UNK_00000001)) &&
     (puVar1 = &DAT_0007dfea, (byte)(&DAT_0007dfea)[*param_1] <= *(byte *)((int)param_1 + 9))) {
    puVar1 = &DAT_0007e076;
    if (*(byte *)(param_1 + 4) < (byte)(&DAT_0007e076)[*param_1]) {
      puVar1 = (undefined *)FUN_000636d2((char)*(byte *)(param_1 + 4) + 1);
      return puVar1;
    }
  }
  return puVar1;
}



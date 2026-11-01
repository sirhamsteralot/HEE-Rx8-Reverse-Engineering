/* ROM address: 0x00061748; body bytes: 66; decompiled */

undefined * FUN_00061748(ushort *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2];
  if ((puVar1 == &UNK_00000010) || (puVar1 == &UNK_00000011)) {
    puVar1 = &DAT_0007dfea;
    if (*(byte *)((int)param_1 + 9) < (byte)(&DAT_0007dfea)[*param_1]) {
      puVar1 = (undefined *)FUN_00063660((char)*(byte *)((int)param_1 + 9) + 1);
      return puVar1;
    }
  }
  return puVar1;
}



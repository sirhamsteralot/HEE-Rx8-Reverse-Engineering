/* ROM address: 0x00060970; body bytes: 66; decompiled */

undefined * FUN_00060970(uint param_1,byte param_2,short param_3)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)param_2;
  if (((puVar1 != &UNK_00000002) && (puVar1 != &UNK_00000004)) && (puVar1 == &UNK_00000001)) {
    puVar1 = &DAT_ffffd5ac;
    (&DAT_ffffd5ac)[*(ushort *)(&DAT_0007daea + (param_1 & 0xffff) * 2)] = 1;
    if (DAT_ffffd3fc == 0) {
      DAT_ffffd3fc = param_3;
    }
  }
  return puVar1;
}



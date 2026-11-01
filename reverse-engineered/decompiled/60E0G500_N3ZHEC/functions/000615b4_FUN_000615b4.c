/* ROM address: 0x000615b4; body bytes: 204; decompiled */

undefined * FUN_000615b4(ushort *param_1)

{
  byte bVar1;
  undefined *puVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  puVar2 = &DAT_ffff8d7c;
  if (((bVar1 != 0) && (bVar1 < 0x40)) &&
     (puVar2 = (undefined *)(uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2], puVar2 == &UNK_00000010
     )) {
    FUN_0006357c(0);
    puVar2 = (undefined *)FUN_000638ae(8);
    return puVar2;
  }
  if (((bVar1 < 0x81) || (0xbf < bVar1)) ||
     (puVar2 = (undefined *)(uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2], puVar2 != &UNK_00000010
     )) {
    if (bVar1 == 0xc0) {
      puVar2 = (undefined *)(uint)(byte)(&DAT_ffff87e0)[(uint)DAT_ffff8928 * 0x10];
      if ((undefined *)(uint)(byte)(&DAT_0007dfea)[*param_1] <= puVar2) {
        puVar2 = (undefined *)FUN_0006357c(0xc1);
      }
    }
    else if ((bVar1 == 0xc1) &&
            (puVar2 = (undefined *)(uint)(byte)(&DAT_ffff87e1)[(uint)DAT_ffff8928 * 0x10],
            (undefined *)(uint)(byte)(&DAT_0007e076)[*param_1] <= puVar2)) {
      FUN_0006357c(0);
      puVar2 = (undefined *)FUN_000638ae(8);
      return puVar2;
    }
  }
  else {
    puVar2 = (undefined *)FUN_0006357c(0xc1);
  }
  return puVar2;
}



/* ROM address: 0x000497ca; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000486ce (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_000497ca(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffcd3e == '\x01') {
    if ((DAT_ffffcd3f != '\0') || (puVar1 = &DAT_ffffcd1c, DAT_ffffcd1c == 0)) {
      puVar1 = (undefined2 *)rx8_add_u16_saturate((int)(short)DAT_ffffcd1c,1);
      DAT_ffffcd1c = (short)puVar1;
      DAT_ffffcd3f = DAT_ffffcd3e;
      return puVar1;
    }
  }
  else if ((DAT_ffffcd3f != '\x01') || (puVar1 = (undefined2 *)0x20, 0x1f < DAT_ffffcd1c)) {
    if ((undefined2 *)(uint)DAT_ffffcd20 != (undefined2 *)0x1) {
      DAT_ffffcd3f = DAT_ffffcd3e;
      return (undefined2 *)(uint)DAT_ffffcd20;
    }
    DAT_ffffcd1c = 0;
    DAT_ffffcd3f = DAT_ffffcd3e;
    return (undefined2 *)((int)&vector_Poweron_Reset + 1);
  }
  DAT_ffffcd1c = 0;
  DAT_ffffcd3f = DAT_ffffcd3e;
  return puVar1;
}



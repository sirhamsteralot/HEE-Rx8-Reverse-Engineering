/* ROM address: 0x000486de; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004776a (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_000486de(void)

{
  char cVar1;
  undefined2 *puVar2;
  
  cVar1 = DAT_ffffaa68;
  if (DAT_ffffaa68 == '\x01') {
    puVar2 = (undefined2 *)rx8_add_u16_saturate((int)DAT_ffffccb4,1);
    DAT_ffffccb4 = (short)puVar2;
    DAT_ffffccb6 = 0;
  }
  else {
    DAT_ffffccb4 = 0;
    puVar2 = (undefined2 *)rx8_add_u16_saturate((int)(short)DAT_ffffccb6,1);
    DAT_ffffccb6 = (ushort)puVar2;
  }
  if ((cVar1 == '\0') && (puVar2 = &DAT_0007c6b8, 5 < DAT_ffffccb6)) {
    DAT_ffffccba = 1;
  }
  else {
    DAT_ffffccba = 0;
  }
  return puVar2;
}



/* ROM address: 0x000447e2; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043ffe (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000447e2(void)

{
  uint uVar1;
  undefined2 *puVar2;
  uint in_r7;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcb78 = 0;
    DAT_ffffcb7a = 0;
  }
  puVar2 = &DAT_ffffb660;
  if ((DAT_ffffb660 & 1) == 0) {
    puVar2 = (undefined2 *)(int)DAT_ffffba25;
    in_r7 = 1;
  }
  else if ((DAT_ffffb660 & 1) == 1) {
    puVar2 = (undefined2 *)(int)DAT_ffffba24;
    in_r7 = 0;
  }
  uVar1 = (uint)puVar2 & 0xff;
  if (uVar1 == 1) {
    if ((DAT_ffffcb8c * DAT_ffffba44 < DAT_ffffba48) || (DAT_ffffcb90 * DAT_ffffba44 < DAT_ffffba40)
       ) {
      uVar1 = in_r7 & 0xffff;
      (&DAT_ffffba24)[uVar1] = 0;
    }
    else if (DAT_ffffd1c5 == '\0') {
      DAT_ffffcb78 = rx8_add_u16_saturate((int)DAT_ffffcb78,1);
      uVar1 = rx8_add_u16_saturate((int)DAT_ffffcb7a,1);
      DAT_ffffcb7a = (short)uVar1;
    }
  }
  return uVar1;
}



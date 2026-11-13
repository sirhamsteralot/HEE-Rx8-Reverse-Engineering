/* ROM address: 0x0002fc00; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000300b8 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0002fc00(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = engine_running_flag_ffffaa68;
  cVar1 = engine_injectors_off_ffffa42c;
  if (engine_running_flag_ffffaa68 == '\x01') {
    DAT_ffffbdda = rx8_add_u16_saturate((int)(short)DAT_ffffbdda,1);
  }
  else {
    DAT_ffffbdda = 0;
  }
  if (cVar1 == '\x01') {
    DAT_ffffbdde = rx8_add_u16_saturate((int)DAT_ffffbdde,1);
  }
  else {
    DAT_ffffbdde = 0;
    DAT_ffffbde0 = '\0';
  }
  DAT_ffffbddc = rx8_add_u16_saturate((int)(short)DAT_ffffbddc,1);
  if (((DAT_ffffbdda < 0x1f) ||
      (((cVar1 == '\x01' && (cVar1 = DAT_ffffbde0, DAT_ffffbde0 == '\x01')) || (DAT_ffffbddc < 0x3f)
       ))) && (cVar1 = cVar2, cVar2 == '\x01')) {
    DAT_ffffbdd8 = 1;
  }
  else {
    cVar2 = cVar1;
    DAT_ffffbdd8 = 0;
  }
  return cVar2;
}



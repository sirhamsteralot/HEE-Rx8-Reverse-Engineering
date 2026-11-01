/* ROM address: 0x000438ca; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000430fe (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000438ca(void)

{
  uint uVar1;
  
  uVar1 = (uint)cranking_active_ffffaa62_ffffaa62;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffca3f, uVar1 == 100)) {
    DAT_ffffca4f = 0;
  }
  else if ((DAT_ffffca46 == '\0') && (uVar1 = (uint)DAT_ffffca9b, uVar1 == 1)) {
    DAT_ffffca4f = 1;
  }
  DAT_ffffca9b = DAT_ffffca46;
  return uVar1;
}



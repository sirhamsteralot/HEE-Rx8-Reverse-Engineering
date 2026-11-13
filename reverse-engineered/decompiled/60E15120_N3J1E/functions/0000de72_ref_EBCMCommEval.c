/* ROM address: 0x0000de72; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000de72 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_EBCMCommEval(void)

{
  char cVar1;
  
  cVar1 = engine_running_flag_ffffaa68;
  if ((engine_running_flag_ffffaa68 == '\x01') && (cVar1 = '\x01', DAT_ffffb578 != '\x01')) {
    if (((DAT_ffffbbdc == '\0') ||
        (((DAT_ffffbbb0 == '\0' || (DAT_ffffce5c == '\0')) || (DAT_ffffbbfe == '\0')))) &&
       (cVar1 = ref_getFaultStatus__(0x80), cVar1 == '\0')) {
      DAT_ffffa401 = 1;
      return '\0';
    }
    cVar1 = '\0';
    DAT_ffffa401 = 0;
  }
  return cVar1;
}



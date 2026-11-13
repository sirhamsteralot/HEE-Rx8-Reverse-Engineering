/* ROM address: 0x0002fb20; body bytes: 164; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002fb80) */
/* Unique exact-byte match to related 60E0FC00 function at 0002ffd8 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_fuelingAddOBDControlMode_(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = engine_injectors_off_ffffa42c;
  if (DAT_ffffbdc0 < DAT_ffffbdc4) {
    if (DAT_ffffbdc0 < DAT_ffffbdc4 - 3.5) {
      DAT_ffffbdd5 = '\0';
    }
  }
  else {
    DAT_ffffbdd5 = '\x01';
  }
  if (((DAT_ffffbdd5 == '\x01') && (engine_stopped_latch_ffffa41c == '\0')) ||
     ((engine_injectors_off_ffffa42c == '\x01' && (engine_running_flag_ffffaa68 == '\x01')))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  DAT_ffffbdbc = ref_obdFuelingAddRequst_(uVar2);
  if (cVar1 == '\x01') {
    DAT_ffffbdd4 = '\x01';
  }
  else if (DAT_ffffbdd4 != '\0') {
    DAT_ffffbdd4 = DAT_ffffbdd4 + -1;
  }
  return cVar1;
}



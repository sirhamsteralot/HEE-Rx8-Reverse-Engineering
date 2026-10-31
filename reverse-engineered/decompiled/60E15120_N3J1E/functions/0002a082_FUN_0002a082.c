/* ROM address: 0x0002a082; body bytes: 154; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a7d6 (154 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002a082(void)

{
  if (((DAT_ffffa9bc < 65.0) || (engine_speed_rpm_ffffb548 < 5500.0)) || (engine_running_ffffa428 != '\0')) {
    if (((DAT_ffffbbde & 0x800) == 0x800) && ((DAT_ffffbb62 & 0x800) != 0x800)) {
      DAT_ffffbb5c = 900000;
    }
    else if ((DAT_ffffaa62 == '\0') && (DAT_ffffbb5c != 0)) {
      DAT_ffffbb5c = DAT_ffffbb5c + -1;
    }
  }
  else {
    DAT_ffffbb5c = 0;
  }
  if (((DAT_ffffbbde & 0x800) == 0x800) && (DAT_ffffbb5c == 0)) {
    DAT_ffffbb49 = 1;
  }
  else {
    DAT_ffffbb49 = 0;
  }
  DAT_ffffbb62 = DAT_ffffbbde;
  return;
}



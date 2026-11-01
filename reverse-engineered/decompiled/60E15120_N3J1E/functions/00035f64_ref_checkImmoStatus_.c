/* ROM address: 0x00035f64; body bytes: 262; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036684 (262 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_checkImmoStatus_(void)

{
  uint uVar1;
  
  if (DAT_ffffc268 != 'Z') {
    DAT_ffffc268 = '\0';
  }
  if (DAT_ffffc268 == 'Z') {
    if ((DAT_ffffc275 & 0xfc) != 0) {
      DAT_ffffc275 = 0;
    }
    if (((inferred_ram_c1d3_ffffc1d3_ffffc1d3 & 0xf) != 0) && (inferred_ram_c1d3_ffffc1d3_ffffc1d3 = 0, inferred_ram_c274_ffffc274_ffffc274 == 1)) {
      inferred_ram_c1d3_ffffc1d3_ffffc1d3 = 0x40;
    }
    if (5 < DAT_ffffc276) {
      DAT_ffffc276 = 0;
    }
    uVar1 = (uint)(char)DAT_ffffc275;
    if (((uVar1 & 2) == 0) && (uVar1 = (uint)inferred_ram_c1d2_ffffc1d2_ffffc1d2, uVar1 == 0x55)) {
      inferred_ram_c1d2_ffffc1d2_ffffc1d2 = 0x33;
      DAT_ffffc234 = 0;
    }
    if (2 < DAT_ffffc282) {
      DAT_ffffc282 = 2;
    }
  }
  else {
    DAT_ffffc275 = 0;
    DAT_ffffc276 = 0;
    inferred_ram_c1d3_ffffc1d3_ffffc1d3 = 0;
    uVar1 = (uint)inferred_ram_c274_ffffc274_ffffc274;
    if (uVar1 == 1) {
      uVar1 = 0x40;
      inferred_ram_c1d3_ffffc1d3_ffffc1d3 = 0x40;
    }
    inferred_ram_c1d2_ffffc1d2_ffffc1d2 = 0x33;
    inferred_ram_c1d4_ffffc1d4_ffffc1d4 = 8;
    DAT_ffffc279 = '\0';
    DAT_ffffc278 = 0;
    DAT_ffffc27e = 0;
    DAT_ffffc27f = 0;
    DAT_ffffc280 = 0;
    DAT_ffffc281 = 0;
    DAT_ffffc282 = 2;
  }
  if ((inferred_ram_c1d4_ffffc1d4_ffffc1d4 < 8) || (0x3f < inferred_ram_c1d4_ffffc1d4_ffffc1d4)) {
    inferred_ram_c1d4_ffffc1d4_ffffc1d4 = 8;
  }
  if (DAT_ffffc279 != '\0') {
    DAT_ffffc239 = 1;
    DAT_ffffc279 = -0x38;
  }
  return uVar1;
}



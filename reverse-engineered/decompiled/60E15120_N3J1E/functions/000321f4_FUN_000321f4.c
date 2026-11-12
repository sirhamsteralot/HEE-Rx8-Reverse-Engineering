/* ROM address: 0x000321f4; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003269c (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000321f4(void)

{
  bool bVar1;
  undefined1 *puVar2;
  
  if (((((DAT_ffffbced != '\x01') || (DAT_ffffbfb5 != '\0')) || (DAT_ffffbfcc != '\0')) ||
      (inferred_ram_bc35_ffffbc35_ffffbc35 != '\x01')) ||
     ((2.0 < DAT_ffffbfa0 - cruise_target_speed_kmh_ffffbfa4 &&
      ((6.4 < DAT_ffffbfa0 - cruise_target_speed_kmh_ffffbfa4 || (DAT_ffffbfb7 != '\x01')))))) {
    DAT_ffffbfb6 = 0;
    bVar1 = false;
  }
  else {
    DAT_ffffbfb6 = 1;
    bVar1 = true;
  }
  if ((DAT_ffffbfcd == '\0') && (bVar1)) {
    DAT_ffffbfbe = 0x177;
    puVar2 = (undefined1 *)0x1;
  }
  else {
    puVar2 = (undefined1 *)(uint)DAT_ffffbfbe;
    if (puVar2 != (undefined1 *)0x0) {
      DAT_ffffbfbe = DAT_ffffbfbe - 1;
    }
  }
  if (DAT_ffffbfbe == 0) {
    puVar2 = &DAT_ffffbfb7;
  }
  DAT_ffffbfb7 = DAT_ffffbfbe != 0;
  DAT_ffffbfcc = inferred_ram_bc35_ffffbc35_ffffbc35;
  DAT_ffffbfcd = DAT_ffffbfb6;
  return puVar2;
}



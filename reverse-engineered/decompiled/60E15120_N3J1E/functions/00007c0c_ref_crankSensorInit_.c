/* ROM address: 0x00007c0c; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007c0c (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_crankSensorInit_(void)

{
  uint uVar1;
  
  DAT_ffff9fc9 = 0;
  DAT_ffff9fca = 0xff;
  if (DAT_ffff9f96 == 1) {
    DAT_ffff9f96 = 0;
    uVar1 = FUN_00007668(0);
    return uVar1;
  }
  return (uint)DAT_ffff9f96;
}



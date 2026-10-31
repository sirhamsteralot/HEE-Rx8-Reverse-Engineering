/* ROM address: 0x0002b6a4; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bdf8 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 FUN_0002b6a4(void)

{
  bool bVar1;
  undefined2 uVar2;
  
  bVar1 = (DAT_ffffbbde & 8) != 8;
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 8;
  }
  DAT_ffffbbcf = !bVar1;
  return uVar2;
}



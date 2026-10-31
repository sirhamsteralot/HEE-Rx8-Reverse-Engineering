/* ROM address: 0x0000a3ac; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a3ac (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a3ac(void)

{
  char cVar2;
  undefined4 uVar1;
  undefined4 local_c [2];
  
  ref_setSR_PARAM(local_c,0xe0);
  DAT_ffffa188 = DAT_ffffa188 + 1;
  if (300 < DAT_ffffa188) {
    FUN_0000a438(0xca,0xffffffff);
    FUN_0000a4be();
  }
  cVar2 = FUN_00006a28();
  if (cVar2 == '\x01') {
    FUN_0000a438(0xdc,0xffffffff);
  }
  uVar1 = FUN_00002064(local_c[0]);
  DAT_ffffa18a = DAT_ffffa18a + -1;
  if (DAT_ffffa18a == '\0') {
    uVar1 = FUN_0000a824();
    DAT_ffffa18a = '\x04';
  }
  return uVar1;
}



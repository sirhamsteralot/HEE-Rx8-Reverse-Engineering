/* ROM address: 0x00007568; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007568 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00007568(void)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  FUN_000076b8();
  if (DAT_ffff9fc4 == '\x01') {
    uVar1 = ATUII_TIER10_W;
    ATUII_TIER10_W = uVar1 & 0xfffb | 4;
  }
  uVar2 = FUN_00002064(local_8[0]);
  return uVar2;
}



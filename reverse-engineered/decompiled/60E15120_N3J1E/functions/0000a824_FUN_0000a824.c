/* ROM address: 0x0000a824; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a824 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a824(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  uVar1 = PBDR_W;
  uVar2 = PBDR_W;
  PBDR_W = ~(uVar1 | 0x7fff) + (uVar2 & 0x7fff);
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}



/* ROM address: 0x00001150; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001150 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001150(undefined4 param_1)

{
  ushort uVar1;
  
  do {
    uVar1 = HCAN0_TXPR_W;
  } while ((uVar1 & 0x80) != 0);
  HCAN0_TXACK_W = 0x80;
  FUN_00001fbc(8,0,param_1,&HCAN0_MD15_1__B);
  HCAN0_TXPR_W = 0x80;
  return;
}



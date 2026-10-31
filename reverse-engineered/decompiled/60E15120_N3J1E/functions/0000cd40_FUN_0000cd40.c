/* ROM address: 0x0000cd40; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cd40 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_0000cd40(byte param_1)

{
  int iVar1;
  
  iVar1 = FUN_0000cee8((int)(char)param_1,&HCAN0_MC0_1__B);
  return *(byte *)(iVar1 + (param_1 & 0xf) * 8) & 0xf;
}



/* ROM address: 0x000010fe; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000010fe (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000010fe(undefined4 param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = HCAN0_RXPR_W;
  if ((uVar1 & 0x40) != 0) {
    uVar1 = HCAN0_UMSR_W;
    if ((uVar1 & 0x40) != 0) {
      HCAN0_UMSR_W = 0x40;
      return 0xffffffff;
    }
    cVar2 = FUN_00001fe2(0);
    if (cVar2 == '\b') {
      HCAN0_RXPR_W = 0x40;
      FUN_00001fa2(8,0,param_1,&HCAN0_MD14_1__B);
      return 1;
    }
    HCAN0_RXPR_W = 0x40;
  }
  return 0;
}



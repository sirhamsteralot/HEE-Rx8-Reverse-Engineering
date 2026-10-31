/* ROM address: 0x000609ae; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f29e (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000609ae(ushort param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  short *psVar2;
  byte bVar3;
  ushort uVar4;
  
  uVar4 = 1;
  bVar3 = 0;
  uVar1 = FUN_00067c78(0);
  psVar2 = &DAT_0007e55c;
  do {
    if ((uVar4 & (param_1 | uVar1)) != 0) {
      param_3 = (int)*psVar2;
      bVar3 = bVar3 + 1;
    }
    uVar4 = uVar4 << 1;
    psVar2 = psVar2 + 1;
  } while (psVar2 < &UNK_0007e567);
  if (1 < bVar3) {
    param_3 = 0x300;
  }
  return param_3;
}



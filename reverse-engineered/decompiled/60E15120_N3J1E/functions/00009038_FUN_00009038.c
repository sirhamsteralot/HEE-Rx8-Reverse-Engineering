/* ROM address: 0x00009038; body bytes: 132; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009038 (132 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00009038(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_14 [2];
  
  ref_setSR_PARAM(local_14,0xe0);
  DAT_ffffa0fc = DAT_ffff9f98;
  DAT_ffffa104 = (undefined2)(DAT_ffff9f9c >> 4);
  FUN_00002064(local_14[0]);
  DAT_ffffa100 = (int)((float)crank_period_accumulator_ffff9f88 / 6.0);
  uVar2 = 0;
  do {
    uVar1 = (uint)(byte)(&DAT_ffffa0dc)[(uVar2 & 0xff) * 8];
    if (uVar1 == 2) {
      uVar1 = FUN_000091c6(uVar2);
    }
    else if (uVar1 == 1) {
      uVar1 = FUN_00009114(uVar2);
    }
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xff) < 4);
  return uVar1;
}



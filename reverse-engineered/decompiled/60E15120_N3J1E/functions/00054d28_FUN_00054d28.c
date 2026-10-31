/* ROM address: 0x00054d28; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052e14 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00054d28(short param_1,char param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = true;
  do {
    uVar2 = uVar4 & 0xff;
    uVar4 = uVar4 + 1;
    if (*(short *)(&DAT_0005486c + uVar2 * 2) == param_1) {
      bVar1 = false;
    }
  } while ((bVar1) && (*(short *)(&DAT_0005486c + (uVar4 & 0xff) * 2) != 0x8c));
  if (bVar1) {
    uVar3 = FUN_00054d90((int)param_2,param_3);
  }
  else {
    uVar3 = FUN_00054994(&DAT_ffff8fe8,(int)param_2,param_3);
  }
  return uVar3;
}



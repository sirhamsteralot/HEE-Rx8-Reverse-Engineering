/* ROM address: 0x00064088; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062978 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064088(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_00062df8();
  uVar3 = uVar1 & 0xff;
  if (((uVar3 == 0) || ((uVar3 != 0 && (uVar3 < 0x40)))) || ((0x80 < uVar3 && (uVar3 < 0xc0)))) {
    uVar2 = FUN_000640f4(param_1);
  }
  else {
    uVar2 = uVar1;
    if (((uVar3 != 0xc0) && (uVar2 = 0xc0, uVar3 != 0xc1)) && (uVar2 = uVar1, uVar3 == 0x50)) {
      uVar2 = FUN_000640f4(param_1,0);
    }
  }
  return uVar2;
}



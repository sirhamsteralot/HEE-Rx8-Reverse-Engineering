/* ROM address: 0x00062080; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060970 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00062080(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)(byte)(&DAT_ffff8d54)[(param_1 & 0xffff) * 2];
  uVar2 = param_2 & 0xff;
  if (uVar1 == 0) {
    uVar1 = FUN_00063e78(param_2);
  }
  else if (uVar1 == 0x10) {
    if ((uVar2 == 0x20) || (uVar1 = uVar2, uVar2 == 0x11)) {
      uVar1 = FUN_00063e78(param_2);
    }
  }
  else if ((uVar1 == 0x11) && (uVar1 = uVar2, uVar2 == 0x20)) {
    uVar1 = FUN_00063e78(param_2);
  }
  return uVar1;
}



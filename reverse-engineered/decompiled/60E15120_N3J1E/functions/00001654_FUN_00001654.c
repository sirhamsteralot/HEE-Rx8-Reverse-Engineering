/* ROM address: 0x00001654; body bytes: 116; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00001654 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00001654(byte *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  _DAT_ffffdfae = _DAT_ffffdfae + 1;
  if ((_DAT_ffffdfae & 0xf) == (*param_1 & 0xf)) {
    bVar2 = 1;
    for (; (bVar2 < 8 && (_DAT_ffffdfac < DAT_ffffd3f2)); _DAT_ffffdfac = _DAT_ffffdfac + 1) {
      if (_DAT_ffffdfac < 0x400) {
        (&DAT_ffffd3f4)[_DAT_ffffdfac] = param_1[bVar2];
      }
      bVar2 = bVar2 + 1;
    }
    if (_DAT_ffffdfac < DAT_ffffd3f2) {
      uVar1 = 0xfffffffe;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



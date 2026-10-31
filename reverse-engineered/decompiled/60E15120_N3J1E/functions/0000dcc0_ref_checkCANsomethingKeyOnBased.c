/* ROM address: 0x0000dcc0; body bytes: 252; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000dcc0 (252 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_checkCANsomethingKeyOnBased(void)

{
  char cVar2;
  uint uVar1;
  
  if (((DAT_ffffaa68 == 1) && (DAT_ffffb578 != '\x01')) &&
     ((cVar2 = ref_getHCANSomething(0), cVar2 == '\x01' ||
      (cVar2 = ref_getHCANSomething(1), cVar2 == '\x01')))) {
    if (DAT_ffffa40f != 0xff) {
      DAT_ffffa40f = DAT_ffffa40f + 1;
    }
  }
  else {
    DAT_ffffa40f = 0;
  }
  if ((100 < DAT_ffffa40f) && (ref_CANSetupSomethingDifferentBasedOnBit(), DAT_ffffa40a == 0)) {
    DAT_ffffa40a = 1;
  }
  uVar1 = (uint)DAT_ffffaa68;
  if ((uVar1 == 1) && (uVar1 = 1, DAT_ffffb578 != '\x01')) {
    cVar2 = FUN_00009ac4(0);
    if ((cVar2 == '\x01') ||
       ((cVar2 = FUN_00009ac4(1), cVar2 == '\x01' || (uVar1 = (uint)DAT_ffffa40a, uVar1 == 1)))) {
      DAT_ffffa40a = 1;
      DAT_ffffa409 = 1;
      if (DAT_ffffa40c == 0) {
        ref_CANSetupSomethingDifferentBasedOnBit();
        ref_canSetup();
      }
      ref_CANSetupSomethingDifferentBasedOnBit();
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffa40c,1);
      DAT_ffffa40c = (ushort)uVar1;
    }
    else {
      DAT_ffffa40c = 0;
    }
    if (999 < DAT_ffffa40c) {
      uVar1 = FUN_0000dade();
      DAT_ffffa40a = 0;
      DAT_ffffa40c = 0;
    }
  }
  return uVar1;
}



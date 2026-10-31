/* ROM address: 0x00068548; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066e38 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00068548(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = (ushort)DAT_ffffddc8;
  uVar2 = 1;
  if (((uVar1 & 0xf) < 8) && ((DAT_ffffddc8 & 0xf) != 0)) {
    DAT_ffffddf5 = DAT_ffffddf5 | 4;
    FUN_000683b4();
    DAT_ffffddec = FUN_00068a86((int)DAT_ffffddc9);
    DAT_ffffddea = DAT_ffffddc9;
    DAT_ffffdde6 = uVar1 & 0xf;
    ref_pack_for_OBD_response_((int)DAT_ffffddec,&DAT_ffffddc9,7);
    uVar2 = 0;
  }
  return uVar2;
}



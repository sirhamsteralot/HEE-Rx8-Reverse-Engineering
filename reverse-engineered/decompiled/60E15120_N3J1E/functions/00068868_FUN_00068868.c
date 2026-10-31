/* ROM address: 0x00068868; body bytes: 168; decompiled */

void FUN_00068868(void)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = FUN_000688c4();
  if (bVar2 == 1) {
    DAT_ffffddf8 = 1;
    uVar1 = sh_raise_interrupt_mask_return_previous(0x90);
    if ((DAT_ffffddf5 & 4) != 0) {
      DAT_ffffddf8 = 0;
      (&DAT_ffffddf4)[(uint)DAT_ffffddec * 2] = 0;
      DAT_ffffddeb = 0;
      DAT_ffffddf5 = DAT_ffffddf5 & 0xfb;
      thunk_FUN_00054b98((int)DAT_ffffddea);
    }
    ref_setSR(uVar1);
    return;
  }
  DAT_ffffddf8 = 0;
  DAT_ffffddd0 = DAT_ffffddd0 | bVar2;
  DAT_ffffddd1 = 0;
  DAT_ffffddd2 = 0;
  DAT_ffffddd3 = 0;
  DAT_ffffddd4 = 0;
  DAT_ffffddd5 = 0;
  DAT_ffffddd6 = 0;
  DAT_ffffddd7 = 0;
  DAT_ffffddeb = 3;
  FUN_00068bc6(5,0x12);
  return;
}



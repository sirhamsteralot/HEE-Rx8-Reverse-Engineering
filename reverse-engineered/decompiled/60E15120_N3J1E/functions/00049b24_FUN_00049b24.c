/* ROM address: 0x00049b24; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00048a28 (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_00049b24(void)

{
  short sVar1;
  undefined2 *puVar2;
  float extraout_fr0;
  
  sVar1 = DAT_ffffcd1e;
  puVar2 = (undefined2 *)(uint)DAT_ffffd1c5;
  if (puVar2 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
    DAT_ffffcd18 = 0.0;
    puVar2 = (undefined2 *)&DAT_ffffcd22;
    DAT_ffffcd21 = 0;
    DAT_ffffcd22 = 0;
  }
  else {
    if (DAT_ffffcd1e != 0) {
      puVar2 = (undefined2 *)rx8_decode_u16_affine(0x3f800000,0);
      DAT_ffffcd18 = DAT_ffffcd28 / extraout_fr0;
    }
    if (sVar1 == -1) {
      if (1e+23 <= DAT_ffffcd18) {
        DAT_ffffcd22 = 1;
      }
      else {
        DAT_ffffcd21 = 1;
      }
    }
    else {
      puVar2 = &DAT_0007c9ce;
      if (DAT_ffffcd18 < 1e+23) {
        DAT_ffffcd21 = 1;
      }
    }
  }
  return puVar2;
}



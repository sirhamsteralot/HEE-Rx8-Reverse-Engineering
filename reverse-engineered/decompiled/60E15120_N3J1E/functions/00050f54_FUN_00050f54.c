/* ROM address: 0x00050f54; body bytes: 190; decompiled */

undefined4 * FUN_00050f54(void)

{
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar1;
  float fVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  
  fVar8 = 0.0;
  fVar5 = (float)rx8_decode_u16_affine(0x42c80000,0,(int)DAT_ffffd0a4);
  fVar7 = 1000.0;
  fVar5 = fVar5 / 1000.0;
  uVar6 = ref_readValue_float_DEFAULTVAL_ADDRESS(fVar8,&DAT_ffff86a8);
  cVar2 = rx8_is_outside_tolerance_band(uVar6,fVar8,0x36b33333);
  cVar3 = rx8_is_outside_tolerance_band(DAT_ffffd0b4,fVar8,0x36b33333);
  cVar4 = rx8_is_outside_tolerance_band(fVar5,fVar8,0x3727c5ac);
  if (DAT_ffffd1c5 == '\x01') {
    puVar1 = (undefined4 *)0x1;
    DAT_ffffd098 = fVar8;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffd0a8;
    if (((puVar1 == (undefined4 *)0x1) &&
        (puVar1 = (undefined4 *)(int)cVar3, puVar1 == (undefined4 *)0x0)) && (cVar2 != '\0')) {
      if (cVar4 == '\0') {
        puVar1 = &DAT_000510f8;
        DAT_ffffd098 = 0.35999998;
      }
      else {
        DAT_ffffd098 = ((DAT_ffffcfe0 - DAT_ffffcfe8) * fVar7) / fVar5;
      }
    }
  }
  DAT_ffffd0b4 = uVar6;
  return puVar1;
}



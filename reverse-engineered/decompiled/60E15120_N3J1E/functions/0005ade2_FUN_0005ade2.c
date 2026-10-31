/* ROM address: 0x0005ade2; body bytes: 272; decompiled */

/* Function candidate recovered from ROM pointer at 5f6d4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005ade2(uint param_1)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  
  uVar2 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  fVar3 = inferred_coolant_temperature_catalyst_temp_model_ffffa998 - DAT_ffffade0;
  if (DAT_ffffd2d8 == '\x01') {
    param_1 = 0;
    uVar2 = 0;
  }
  else if ((((DAT_ffffd29e == '\0') &&
            (fVar4 = inferred_coolant_temperature_catalyst_temp_model_ffffa998, cVar1 = FUN_0005f9f0(0x11,0), cVar1 == '\0')) &&
           (cVar1 = FUN_0005f9f0(0x12,0), cVar1 == '\0')) && (DAT_ffffd198 == '\0')) {
    if ((DAT_ffffd2a7 == '\0') && ((DAT_ffffd0a9 == '\x01' || (DAT_ffffd0aa == '\x01')))) {
      param_1 = param_1 + 1;
      DAT_ffffd2a7 = '\x01';
    }
    if ((((DAT_ffffd2a8 == '\0') && (DAT_ffffd29f == '\x01')) &&
        ((4.444 <= fVar4 && (((fVar4 <= 35.0 && (fVar3 <= 6.667)) && (0x124f < DAT_ffffd296)))))) &&
       ((0x124f < DAT_ffffd294 && (0x927 < DAT_ffffd298)))) {
      uVar2 = uVar2 + 1;
      DAT_ffffd2a8 = '\x01';
    }
    if ((0xffff < param_1) || (0xffff < uVar2)) {
      param_1 = param_1 >> 1;
      uVar2 = uVar2 >> 1;
    }
  }
  return param_1 << 0x10 | uVar2 & 0xffff;
}



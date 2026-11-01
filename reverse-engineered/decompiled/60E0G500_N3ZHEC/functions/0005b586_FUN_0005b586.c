/* ROM address: 0x0005b586; body bytes: 272; decompiled */

/* Function candidate recovered from ROM pointer at 5fe78 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005b586(uint param_1)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  
  uVar2 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  fVar3 = DAT_ffffaa1c - DAT_ffffae58;
  if (DAT_ffffd314 == '\x01') {
    param_1 = 0;
    uVar2 = 0;
  }
  else if ((((DAT_ffffd2da == '\0') &&
            (fVar4 = DAT_ffffaa1c, cVar1 = FUN_00060194(0x11,0), cVar1 == '\0')) &&
           (cVar1 = FUN_00060194(0x12,0), cVar1 == '\0')) && (DAT_ffffd1d4 == '\0')) {
    if ((DAT_ffffd2e3 == '\0') && ((DAT_ffffd0e5 == '\x01' || (DAT_ffffd0e6 == '\x01')))) {
      param_1 = param_1 + 1;
      DAT_ffffd2e3 = '\x01';
    }
    if ((((DAT_ffffd2e4 == '\0') && (DAT_ffffd2db == '\x01')) &&
        ((4.444 <= fVar4 && (((fVar4 <= 35.0 && (fVar3 <= 6.667)) && (0x124f < DAT_ffffd2d2)))))) &&
       ((0x124f < DAT_ffffd2d0 && (0x927 < DAT_ffffd2d4)))) {
      uVar2 = uVar2 + 1;
      DAT_ffffd2e4 = '\x01';
    }
    if ((0xffff < param_1) || (0xffff < uVar2)) {
      param_1 = param_1 >> 1;
      uVar2 = uVar2 >> 1;
    }
  }
  return param_1 << 0x10 | uVar2 & 0xffff;
}



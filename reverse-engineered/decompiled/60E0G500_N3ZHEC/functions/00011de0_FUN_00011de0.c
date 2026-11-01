/* ROM address: 0x00011de0; body bytes: 256; decompiled */

/* Function candidate recovered from ROM pointer at d9a8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00011de0(void)

{
  uint uVar1;
  char cVar3;
  uint uVar2;
  
  if ((DAT_ffff9ec8 & 1) == 0) {
    uVar1 = FUN_00009c8e(0);
    if (uVar1 != 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x4000) != 0) {
          uVar1 = FUN_00009890(&DAT_0004e7a8);
        }
      }
      else {
        uVar1 = FUN_00009890(&DAT_0004e798);
      }
    }
  }
  else {
    uVar1 = FUN_00009c8e(0);
    if (uVar1 != 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x4000) != 0) {
          cVar3 = FUN_00009890();
          uVar2 = FUN_00009c34(&DAT_0004e7a8);
          uVar1 = (uint)cVar3;
          if ((uVar1 == 0) && (uVar1 = uVar2 & 0xff, uVar1 == 8)) {
            uVar1 = FUN_00068844(0x7e0);
            return uVar1;
          }
        }
      }
      else {
        cVar3 = FUN_00009890();
        uVar2 = FUN_00009c34(&DAT_0004e798);
        uVar1 = (uint)cVar3;
        if ((uVar1 == 0) && (uVar1 = uVar2 & 0xff, uVar1 == 8)) {
          uVar1 = FUN_00068844(0x7df);
          return uVar1;
        }
      }
    }
  }
  return uVar1;
}



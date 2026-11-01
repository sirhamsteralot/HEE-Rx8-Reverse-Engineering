/* ROM address: 0x00038340; body bytes: 278; decompiled */

/* Function candidate recovered from ROM pointer at 57ea4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00038340(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_ffffc2cf == '\0') {
    if ((DAT_ffffc2a9 == '\0') && (DAT_ffffc2b7 == '\0')) {
      if (((DAT_ffffc2ec == 0) || (DAT_ffffc2ea == 0)) ||
         ((DAT_ffffc2ec == -1 && (DAT_ffffc2ea == -1)))) {
        DAT_ffffc2ee = '\0';
      }
      else {
        if (DAT_ffffc2e6 == '\0') {
          FUN_00037892();
          DAT_ffffc2e6 = '\x05';
          DAT_ffffc2b2 = 1;
          DAT_ffffc2e8 = 0;
        }
        DAT_ffffc2ee = '\x01';
        if (DAT_ffffc242 == '3') {
          DAT_ffffc2d0 = 1;
        }
      }
      DAT_ffffc2cf = '\x01';
      DAT_ffffd224 = 0x80;
    }
    else {
      DAT_ffffd224 = 0xff;
    }
  }
  else if (DAT_ffffc2ce == '\0') {
    DAT_ffffc2ce = '\x01';
    DAT_ffffc2cb = 1;
  }
  else if (DAT_ffffc2cd == '\x01') {
    FUN_000581d2(param_1,(int)DAT_ffffc2ee);
    if (DAT_ffffc2ee == '\x01') {
      FUN_000581d2(param_1,(int)DAT_ffffc2ef);
      FUN_000581d2(param_1,(int)DAT_ffffc2f0);
      iVar1 = (int)DAT_ffffc2f1;
    }
    else {
      FUN_000581d2(param_1,0);
      FUN_000581d2(param_1,0);
      iVar1 = 0;
    }
    FUN_000581d2(param_1,iVar1);
    DAT_ffffd224 = 0;
    DAT_ffffc2cf = '\0';
    DAT_ffffc2ce = '\0';
    DAT_ffffc2cd = '\0';
  }
  return;
}



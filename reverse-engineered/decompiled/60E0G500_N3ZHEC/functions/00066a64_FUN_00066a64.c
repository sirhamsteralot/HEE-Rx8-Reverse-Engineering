/* ROM address: 0x00066a64; body bytes: 444; decompiled */

/* Function candidate recovered from ROM pointer at 5f330 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint obd_mode09_vehicle_info(undefined4 param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  uint unaff_r9;
  undefined1 local_34 [4];
  char cStack_30;
  undefined4 local_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  bVar1 = false;
  cStack_30 = param_2;
  cVar2 = FUN_00066c68(param_1);
  if (cVar2 == '\0') {
    FUN_00068928(9,&DAT_ffffd963,param_1);
    unaff_r9 = FUN_00066ebc((int)(char)DAT_ffffd963);
    cVar2 = FUN_00066ca4(unaff_r9,&DAT_ffffd963,param_1);
    if (cVar2 != '\0') {
      bVar1 = true;
    }
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    DAT_ffffd940 = 1;
    local_34[0] = 0x49;
    FUN_000688c8(9,local_34,1);
    if ((unaff_r9 & 0xff) == 0) {
      FUN_00066cca(&DAT_ffffd963,param_1);
    }
    else {
      cVar2 = FUN_00066e1c(9,(int)(char)DAT_ffffd963);
      if (cVar2 == '\0') {
        if (DAT_ffffd963 == 6) {
          cVar2 = FUN_00066dc4();
          if (cVar2 == '\0') {
            FUN_00066d70((int)(char)DAT_ffffd963);
            if (DAT_ffffd940 == 1) {
              bVar1 = false;
            }
          }
          else {
            bVar1 = true;
          }
        }
        else if (DAT_ffffd963 == 2) {
          FUN_00066d70(2);
          if (DAT_ffffd940 == 1) {
            bVar1 = false;
          }
        }
        else if (DAT_ffffd963 < 9) {
          FUN_00066d70((int)(char)DAT_ffffd963);
        }
      }
    }
    if ((bVar1 == false) && (DAT_ffffd940 == 1)) {
      bVar1 = false;
    }
  }
  uVar3 = (uint)bVar1;
  if (uVar3 == 0) {
    local_2c = 9;
    uStack_28 = (uint)DAT_ffffd940;
    uStack_24 = 8;
    uStack_20 = 0;
    uVar3 = FUN_000694fa();
  }
  else if (uVar3 == 1) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_00066ece(9,0x12,uVar4);
  }
  else if (uVar3 == 2) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_00066ece(9,0x12,uVar4);
  }
  else if (uVar3 == 3) {
    uVar3 = FUN_00066ece(9,0x22,1);
  }
  else if (uVar3 == 4) {
    uVar3 = FUN_00066ece(9,0x22,3);
  }
  else if (uVar3 == 6) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_00066ece(9,0x10,uVar4);
  }
  return uVar3;
}



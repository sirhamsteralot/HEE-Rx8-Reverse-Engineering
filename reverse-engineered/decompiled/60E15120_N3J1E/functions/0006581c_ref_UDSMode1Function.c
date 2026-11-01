/* ROM address: 0x0006581c; body bytes: 282; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006410c (282 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode01_current_data(uint param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  char local_3c [4];
  undefined1 auStack_38 [4];
  char cStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  param_1 = param_1 & 0xffff;
  bVar1 = false;
  if ((param_1 == 0) || (6 < param_1)) {
    bVar1 = true;
  }
  cStack_34 = param_2;
  if (!bVar1) {
    DAT_ffffd816 = 1;
    auStack_38[0] = 0x41;
    ref_setupForUdsResponse_(1,auStack_38);
    iVar5 = 0;
    if (param_1 != 0) {
      do {
        ref_udsServiceResponse(1,local_3c);
        cVar2 = FUN_00066678(1,(int)local_3c[0]);
        if (cVar2 == '\0') {
          cVar2 = FUN_00066718((int)local_3c[0]);
          if (cVar2 == '\0') {
            FUN_00065936((int)local_3c[0]);
          }
          else {
            FUN_00065980((int)local_3c[0]);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)param_1);
    }
    if (DAT_ffffd816 == 1) {
      bVar1 = false;
    }
  }
  uVar3 = (uint)bVar1;
  if (uVar3 == 0) {
    local_30 = 1;
    uStack_2c = (uint)DAT_ffffd816;
    uStack_28 = 8;
    uStack_24 = 0;
    uVar3 = FUN_00068d56();
  }
  else if (uVar3 == 1) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(1,0x12,uVar4);
  }
  else if (uVar3 == 2) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(1,0x12,uVar4);
  }
  return uVar3;
}



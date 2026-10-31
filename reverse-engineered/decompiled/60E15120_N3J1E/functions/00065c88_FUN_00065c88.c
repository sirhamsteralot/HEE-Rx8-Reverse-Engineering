/* ROM address: 0x00065c88; body bytes: 462; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064578 (462 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00065c88(uint param_1,char param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  char local_48 [4];
  char acStack_44 [4];
  undefined1 auStack_40 [4];
  uint uStack_3c;
  uint uStack_38;
  char cStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar6 = param_1 & 0xffff;
  bVar1 = false;
  bVar2 = false;
  if (((uVar6 == 0) || (6 < uVar6)) || ((param_1 & 1) == 1)) {
    bVar1 = true;
  }
  cStack_34 = param_2;
  if (!bVar1) {
    DAT_ffffd818 = 1;
    auStack_40[0] = 0x42;
    ref_setupForUdsResponse_(2,auStack_40,1);
    cVar3 = FUN_0006071e(&DAT_ffffd81a);
    iVar5 = 0;
    uStack_38 = (uint)(cVar3 == '\0');
    uStack_3c = (uint)(cVar3 == '\0');
    if (uVar6 != 0) {
      do {
        ref_udsServiceResponse(2,local_48,1);
        ref_udsServiceResponse(2,acStack_44,1);
        cVar3 = FUN_00066678(2,(int)local_48[0]);
        if (cVar3 == '\0') {
          cVar3 = FUN_00066718((int)local_48[0]);
          if (cVar3 == '\0') {
            FUN_00065e56((int)local_48[0],(int)acStack_44[0]);
          }
          else if (local_48[0] == '\x02') {
            if ((uStack_38 == 0) || (acStack_44[0] != '\0')) {
              FUN_00065f96(2,(int)acStack_44[0]);
            }
            else {
              FUN_00065ed0(2,0);
            }
          }
          else if ((uStack_3c != 0) && (acStack_44[0] == '\0')) {
            FUN_00065ed0((int)local_48[0],0);
          }
          bVar2 = true;
        }
        iVar5 = iVar5 + 2;
      } while (iVar5 < (int)uVar6);
    }
    if (DAT_ffffd818 == 1) {
      if (bVar2) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
  }
  uVar6 = (uint)bVar1;
  if (uVar6 == 0) {
    local_30 = 2;
    uStack_2c = (uint)DAT_ffffd818;
    uStack_28 = 8;
    uStack_24 = 0;
    uVar6 = FUN_00068d56();
  }
  else if (uVar6 == 1) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar6 = FUN_0006672a(2,0x12,uVar4);
  }
  else if (uVar6 == 2) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar6 = FUN_0006672a(2,0x12,uVar4);
  }
  else if (uVar6 == 3) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar6 = FUN_0006672a(2,0x22,uVar4);
  }
  return uVar6;
}



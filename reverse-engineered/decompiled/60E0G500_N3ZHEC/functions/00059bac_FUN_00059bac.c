/* ROM address: 0x00059bac; body bytes: 414; decompiled */

void FUN_00059bac(void)

{
  bool bVar1;
  char cVar4;
  undefined4 uVar2;
  undefined2 uVar3;
  byte bVar5;
  char local_80 [100];
  
  if (DAT_ffffd2af == '\0') {
    return;
  }
  bVar1 = true;
  if (DAT_ffffd2b8 != '\0') {
    bVar5 = 0;
    do {
      cVar4 = FUN_00060194((int)(short)DAT_ffffd2b6,3);
      if (cVar4 == '\x01') {
        if ((DAT_ffffd2b6 == 0) || (DAT_ffffd2b6 == 1)) {
          DAT_ffffd2b3 = DAT_ffffd2b3 + '\x01';
          uVar2 = FUN_00060070((int)DAT_ffffd3fc);
          uVar3 = FUN_000600fe(uVar2);
        }
        else {
          uVar3 = FUN_000600f4((int)(short)DAT_ffffd2b6);
        }
        if (((DAT_ffffd2b6 != 0) && (DAT_ffffd2b6 != 1)) || (DAT_ffffd2b3 == '\x01')) {
          local_80[(uint)bVar5 * 2] = (char)((ushort)uVar3 >> 8);
          local_80[(uint)bVar5 * 2 + 1] = (char)uVar3;
          bVar5 = bVar5 + 1;
          DAT_ffffd2b4 = DAT_ffffd2b4 + '\x01';
        }
      }
      DAT_ffffd2b6 = DAT_ffffd2b6 + 1;
      if ((DAT_ffffd2b4 == DAT_ffffd2b2) || (0x8b < DAT_ffffd2b6)) {
        bVar1 = false;
      }
    } while ((bVar5 < 0x30) && (bVar1));
    FUN_000688c8(0x33,local_80,(ushort)bVar5 * 2);
    DAT_ffffd2b0 = DAT_ffffd2b0 + (ushort)bVar5 * 2;
    goto LAB_00059d54;
  }
  if (((DAT_ffffd29d != '\0') || (DAT_ffffd2a2 != '\0')) || (DAT_ffffd2ab != '\0'))
  goto LAB_00059d54;
  local_80[0] = 's';
  local_80[1] = DAT_ffffd2af;
  FUN_000688c8(0x33,local_80,2);
  DAT_ffffd2b0 = DAT_ffffd2b0 + 2;
  DAT_ffffd2b2 = FUN_000602ac();
  if (DAT_ffffd297 == '\0') {
    local_80[0] = '\x02';
LAB_00059c42:
    bVar1 = false;
  }
  else {
    if (DAT_ffffd2b2 == '\0') {
      local_80[0] = '\0';
      goto LAB_00059c42;
    }
    local_80[0] = '\x01';
    DAT_ffffd2b8 = '\x01';
  }
  FUN_000688c8(0x33,local_80,1);
  DAT_ffffd2b0 = DAT_ffffd2b0 + 1;
LAB_00059d54:
  if (!bVar1) {
    FUN_000550ca(0x33,(int)DAT_ffffd2b0);
    FUN_00059b8c();
  }
  return;
}



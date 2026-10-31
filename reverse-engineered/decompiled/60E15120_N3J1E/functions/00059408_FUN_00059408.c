/* ROM address: 0x00059408; body bytes: 414; decompiled */

void FUN_00059408(void)

{
  bool bVar1;
  char cVar4;
  undefined4 uVar2;
  undefined2 uVar3;
  byte bVar5;
  char local_80 [100];
  
  if (DAT_ffffd273 == '\0') {
    return;
  }
  bVar1 = true;
  if (DAT_ffffd27c != '\0') {
    bVar5 = 0;
    do {
      cVar4 = FUN_0005f9f0((int)(short)DAT_ffffd27a,3);
      if (cVar4 == '\x01') {
        if ((DAT_ffffd27a == 0) || (DAT_ffffd27a == 1)) {
          DAT_ffffd277 = DAT_ffffd277 + '\x01';
          uVar2 = FUN_0005f8cc((int)DAT_ffffd3c0);
          uVar3 = FUN_0005f95a(uVar2);
        }
        else {
          uVar3 = FUN_0005f950((int)(short)DAT_ffffd27a);
        }
        if (((DAT_ffffd27a != 0) && (DAT_ffffd27a != 1)) || (DAT_ffffd277 == '\x01')) {
          local_80[(uint)bVar5 * 2] = (char)((ushort)uVar3 >> 8);
          local_80[(uint)bVar5 * 2 + 1] = (char)uVar3;
          bVar5 = bVar5 + 1;
          DAT_ffffd278 = DAT_ffffd278 + '\x01';
        }
      }
      DAT_ffffd27a = DAT_ffffd27a + 1;
      if ((DAT_ffffd278 == DAT_ffffd276) || (0x8b < DAT_ffffd27a)) {
        bVar1 = false;
      }
    } while ((bVar5 < 0x30) && (bVar1));
    ref_setupForUdsResponse_(0x33,local_80,(ushort)bVar5 * 2);
    DAT_ffffd274 = DAT_ffffd274 + (ushort)bVar5 * 2;
    goto LAB_000595b0;
  }
  if (((DAT_ffffd261 != '\0') || (DAT_ffffd266 != '\0')) || (DAT_ffffd26f != '\0'))
  goto LAB_000595b0;
  local_80[0] = 's';
  local_80[1] = DAT_ffffd273;
  ref_setupForUdsResponse_(0x33,local_80,2);
  DAT_ffffd274 = DAT_ffffd274 + 2;
  DAT_ffffd276 = FUN_0005fb08();
  if (DAT_ffffd25b == '\0') {
    local_80[0] = '\x02';
LAB_0005949e:
    bVar1 = false;
  }
  else {
    if (DAT_ffffd276 == '\0') {
      local_80[0] = '\0';
      goto LAB_0005949e;
    }
    local_80[0] = '\x01';
    DAT_ffffd27c = '\x01';
  }
  ref_setupForUdsResponse_(0x33,local_80,1);
  DAT_ffffd274 = DAT_ffffd274 + 1;
LAB_000595b0:
  if (!bVar1) {
    ref_udsResponseRelated__(0x33,(int)DAT_ffffd274);
    FUN_000593e8();
  }
  return;
}



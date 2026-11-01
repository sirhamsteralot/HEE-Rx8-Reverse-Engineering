/* ROM address: 0x00068ca0; body bytes: 182; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067590 (182 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_udsSomething_(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 auStack_18 [8];
  
  uVar5 = *param_1;
  uVar3 = param_1[1];
  uVar2 = param_1[2];
  uVar4 = uVar2 & 0xff;
  if ((uVar3 & 0xffff) == 0) {
    if (uVar4 != 0) {
      if (uVar4 != 1) {
        return uVar4;
      }
      uVar2 = ref_udsResponseRelated2(uVar5,0x12,1);
      return uVar2;
    }
    uVar1 = 0x12;
  }
  else {
    ref_udsServiceResponse(uVar5,auStack_18,1);
    uVar2 = uds_service_dispatch_table_scan(uVar5,uVar3 - 1,uVar2);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 1) {
      if (uVar4 == 0) {
        uVar2 = ref_udsResponseRelated2(uVar5,0x11,1);
        return uVar2;
      }
      if (uVar4 != 1) {
        return uVar4;
      }
      uVar2 = ref_udsResponseRelated2(uVar5,0x11,2);
      return uVar2;
    }
    if (uVar2 != 2) {
      return uVar2;
    }
    if (uVar4 != 0) {
      if (uVar4 != 1) {
        return uVar4;
      }
      uVar2 = ref_udsResponseRelated2(uVar5,0x22,2);
      return uVar2;
    }
    uVar1 = 0x22;
  }
  uVar2 = ref_udsResponseRelated2(uVar5,uVar1,1);
  return uVar2;
}



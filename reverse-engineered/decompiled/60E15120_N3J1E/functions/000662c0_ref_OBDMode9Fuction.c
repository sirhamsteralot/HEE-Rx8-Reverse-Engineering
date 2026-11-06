/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode09_vehicle_info [high]: service table record 0x5eb88 (service 0x09) -> handler; ROM bytes verified; OBD Mode 09 (ref_OBDMode9Fuction)
 */
/* ROM address: 0x000662c0; body bytes: 444; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064bb0 (444 bytes). Names prefixed ref_
   are inherited hypotheses. */

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
  cVar2 = FUN_000664c4(param_1);
  if (cVar2 == '\0') {
    ref_udsServiceResponse(9,&DAT_ffffd927,param_1);
    unaff_r9 = FUN_00066718((int)(char)DAT_ffffd927);
    cVar2 = FUN_00066500(unaff_r9,&DAT_ffffd927,param_1);
    if (cVar2 != '\0') {
      bVar1 = true;
    }
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    DAT_ffffd904 = 1;
    local_34[0] = 0x49;
    ref_setupForUdsResponse_(9,local_34,1);
    if ((unaff_r9 & 0xff) == 0) {
      FUN_00066526(&DAT_ffffd927,param_1);
    }
    else {
      cVar2 = FUN_00066678(9,(int)(char)DAT_ffffd927);
      if (cVar2 == '\0') {
        if (DAT_ffffd927 == 6) {
          cVar2 = FUN_00066620();
          if (cVar2 == '\0') {
            FUN_000665cc((int)(char)DAT_ffffd927);
            if (DAT_ffffd904 == 1) {
              bVar1 = false;
            }
          }
          else {
            bVar1 = true;
          }
        }
        else if (DAT_ffffd927 == 2) {
          FUN_000665cc(2);
          if (DAT_ffffd904 == 1) {
            bVar1 = false;
          }
        }
        else if (DAT_ffffd927 < 9) {
          FUN_000665cc((int)(char)DAT_ffffd927);
        }
      }
    }
    if ((bVar1 == false) && (DAT_ffffd904 == 1)) {
      bVar1 = false;
    }
  }
  uVar3 = (uint)bVar1;
  if (uVar3 == 0) {
    local_2c = 9;
    uStack_28 = (uint)DAT_ffffd904;
    uStack_24 = 8;
    uStack_20 = 0;
    uVar3 = FUN_00068d56();
  }
  else if (uVar3 == 1) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(9,0x12,uVar4);
  }
  else if (uVar3 == 2) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(9,0x12,uVar4);
  }
  else if (uVar3 == 3) {
    uVar3 = FUN_0006672a(9,0x22,1);
  }
  else if (uVar3 == 4) {
    uVar3 = FUN_0006672a(9,0x22,3);
  }
  else if (uVar3 == 6) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(9,0x10,uVar4);
  }
  return uVar3;
}



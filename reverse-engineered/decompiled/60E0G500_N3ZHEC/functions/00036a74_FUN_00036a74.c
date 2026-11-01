/* ROM address: 0x00036a74; body bytes: 606; decompiled */

uint FUN_00036a74(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  param_1 = param_1 & 0xff;
  puVar4 = (undefined4 *)&DAT_ffffc243;
  if (param_1 != 1) {
    if (param_1 == 2) {
      uVar3 = 8;
      puVar4 = &DAT_ffffc2dc;
      uVar2 = 2;
      goto LAB_00036d1e;
    }
    if (param_1 == 0xd) {
      uVar3 = 1;
      puVar4 = (undefined4 *)&DAT_ffffc2f2;
      uVar2 = 0x1e;
      goto LAB_00036d1e;
    }
    if (param_1 == 3) {
      uVar3 = 1;
      puVar4 = (undefined4 *)&DAT_ffffc2d8;
      uVar2 = 0;
      goto LAB_00036d1e;
    }
    if (param_1 == 4) {
      FUN_00038e8c(0xc,&DAT_ffffc2e5,1);
      FUN_00038e8c(0xe,&DAT_ffffc243,1);
      uVar3 = 1;
      puVar4 = (undefined4 *)&DAT_ffffc242;
      uVar2 = 0x10;
      goto LAB_00036d1e;
    }
    if (param_1 == 5) {
      FUN_00038e8c(0x12,&DAT_ffffc244,1);
      uVar3 = 1;
      puVar4 = (undefined4 *)&DAT_ffffc2e8;
      uVar2 = 0x13;
      goto LAB_00036d1e;
    }
    if (param_1 == 6) {
      uVar3 = 1;
      uVar2 = 0xe;
      goto LAB_00036d1e;
    }
    if (param_1 == 7) {
      FUN_00038e8c(0x16,&DAT_ffffc2ea,2);
      puVar4 = (undefined4 *)&DAT_ffffc2ec;
      uVar3 = 2;
      uVar2 = 0x18;
      goto LAB_00036d1e;
    }
    if (param_1 == 8) {
      puVar4 = (undefined4 *)&DAT_ffffc2e9;
      uVar3 = 1;
      uVar2 = 0x14;
      goto LAB_00036d1e;
    }
    if (param_1 == 0xc) {
      FUN_00038e8c(0xc,&DAT_ffffc2e5,1);
      FUN_00038e8c(0xd,&DAT_ffffc2e6,1);
      FUN_00038e8c(0xe,&DAT_ffffc243,1);
      FUN_00038e8c(0xf,&DAT_ffffc2e7,1);
      FUN_00038e8c(0x10,&DAT_ffffc242,1);
      FUN_00038e8c(0x14,&DAT_ffffc2e9,1);
      FUN_00038e8c(0x12,&DAT_ffffc244,1);
      FUN_00038e8c(0x13,&DAT_ffffc2e8,1);
      FUN_00038e8c(0x1a,&DAT_ffffc2ee,1);
      FUN_00038e8c(0x1b,&DAT_ffffc2ef,1);
      FUN_00038e8c(0x1c,&DAT_ffffc2f0,1);
      FUN_00038e8c(0x1d,&DAT_ffffc2f1,1);
      puVar4 = (undefined4 *)&DAT_ffffc2f2;
      uVar3 = 1;
      uVar2 = 0x1e;
      goto LAB_00036d1e;
    }
    if (param_1 == 9) {
      FUN_00038e8c(0xc,&DAT_ffffc2e5,1);
      FUN_00038e8c(0xe,&DAT_ffffc243,1);
      FUN_00038e8c(0x10,&DAT_ffffc242,1);
      FUN_00038e8c(0x12,&DAT_ffffc244,1);
      puVar4 = (undefined4 *)&DAT_ffffc2e8;
      uVar3 = 1;
      uVar2 = 0x13;
      goto LAB_00036d1e;
    }
    if (param_1 == 10) {
      FUN_00038e8c(0x1a,&DAT_ffffc2ee,1);
      FUN_00038e8c(0x1b,&DAT_ffffc2ef,1);
      FUN_00038e8c(0x1c,&DAT_ffffc2f0,1);
      puVar4 = (undefined4 *)&DAT_ffffc2f1;
      uVar3 = 1;
      uVar2 = 0x1d;
      goto LAB_00036d1e;
    }
    if (param_1 != 0xb) {
      if (param_1 == 0xe) {
        puVar4 = (undefined4 *)&DAT_ffffc2e6;
        uVar3 = 1;
        uVar2 = 0xd;
      }
      else if (param_1 == 0xf) {
        puVar4 = (undefined4 *)&DAT_ffffc2e7;
        uVar3 = 1;
        uVar2 = 0xf;
      }
      else {
        if (param_1 != 0xff) {
          return param_1;
        }
        FUN_00038e8c(0,&DAT_ffffc2d8,1);
        FUN_00038e8c(2,&DAT_ffffc2dc,8);
        FUN_00038e8c(10,&DAT_ffffc2e4,1);
        FUN_00038e8c(0xc,&DAT_ffffc2e5,1);
        FUN_00038e8c(0xd,&DAT_ffffc2e6,1);
        FUN_00038e8c(0xe,&DAT_ffffc243,1);
        FUN_00038e8c(0xf,&DAT_ffffc2e7,1);
        FUN_00038e8c(0x10,&DAT_ffffc242,1);
        FUN_00038e8c(0x12,&DAT_ffffc244,1);
        FUN_00038e8c(0x13,&DAT_ffffc2e8,1);
        FUN_00038e8c(0x16,&DAT_ffffc2ea,2);
        FUN_00038e8c(0x18,&DAT_ffffc2ec,2);
        FUN_00038e8c(0x14,&DAT_ffffc2e9,1);
        FUN_00038e8c(0x1a,&DAT_ffffc2ee,1);
        FUN_00038e8c(0x1b,&DAT_ffffc2ef,1);
        FUN_00038e8c(0x1c,&DAT_ffffc2f0,1);
        FUN_00038e8c(0x1d,&DAT_ffffc2f1,1);
        puVar4 = (undefined4 *)&DAT_ffffc2f2;
        uVar2 = 0x1e;
        uVar3 = 1;
      }
      goto LAB_00036d1e;
    }
    FUN_00038e8c(2,&DAT_ffffc2dc,8);
  }
  puVar4 = (undefined4 *)&DAT_ffffc2e4;
  uVar3 = 1;
  uVar2 = 10;
LAB_00036d1e:
  uVar1 = FUN_00038e8c(uVar2,puVar4,uVar3);
  return uVar1;
}



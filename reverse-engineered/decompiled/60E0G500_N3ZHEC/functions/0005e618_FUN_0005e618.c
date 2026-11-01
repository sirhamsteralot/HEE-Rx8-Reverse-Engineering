/* ROM address: 0x0005e618; body bytes: 178; decompiled */

uint FUN_0005e618(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_20;
  undefined1 uStack_1f;
  
  uVar1 = FUN_00038ed8(0x9a,&local_20,2);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    DAT_ffffd3bc = CONCAT11(local_20,uStack_1f);
    if ((DAT_ffffd1f1 == '\x01') || (DAT_ffffd1f4 == '\x01')) {
      uVar1 = 1;
      DAT_ffffd3be = 99;
    }
    else {
      uVar4 = 0;
      uVar5 = 0x3f800000;
      fVar2 = (float)FUN_000024c0(0x3f800000,0,0x64a);
      fVar3 = (float)FUN_000024c0(uVar5,uVar4,(int)DAT_ffffd3bc);
      uVar1 = FUN_00002440(fVar3,uVar4,0x3727c5ac);
      if ((uVar1 & 0xff) != 0) {
        uVar1 = FUN_000024d0(fVar2 / fVar3,0x3c23d70a,uVar5);
        DAT_ffffd3be = (undefined1)uVar1;
      }
    }
  }
  return uVar1;
}



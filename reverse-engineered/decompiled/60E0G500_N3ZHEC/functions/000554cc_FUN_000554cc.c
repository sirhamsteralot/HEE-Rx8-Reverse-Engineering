/* ROM address: 0x000554cc; body bytes: 104; decompiled */

undefined4 FUN_000554cc(short param_1,char param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = true;
  do {
    uVar2 = uVar4 & 0xff;
    uVar4 = uVar4 + 1;
    if (*(short *)(&DAT_00055010 + uVar2 * 2) == param_1) {
      bVar1 = false;
    }
  } while ((bVar1) && (*(short *)(&DAT_00055010 + (uVar4 & 0xff) * 2) != 0x8c));
  if (bVar1) {
    uVar3 = FUN_00055534((int)param_2,param_3);
  }
  else {
    uVar3 = FUN_00055138(&DAT_ffff9010,(int)param_2,param_3);
  }
  return uVar3;
}



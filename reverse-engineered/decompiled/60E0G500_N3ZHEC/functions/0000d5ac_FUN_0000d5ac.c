/* ROM address: 0x0000d5ac; body bytes: 98; decompiled */

ulonglong FUN_0000d5ac(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_ffffecb0;
  DAT_ffffecb0 = uVar1 & 0xfff8 | 1;
  DAT_ffff9300 = 0;
  DAT_ffffecc0 = &DAT_ffff9300;
  DAT_ffffecc4 = &DAT_ffff9300;
  DAT_ffffeccc._2_2_ = 0x128;
  DAT_ffffeccc = 0x1f0128;
  DAT_ffffecc8 = 0x133f;
  uVar2 = DAT_ffffeccc;
  DAT_ffffeccc = uVar2 & 0xfffffff9 | 1;
  do {
    uVar3 = DAT_ffffeccc;
  } while ((uVar3 & 2) == 0);
  uVar4 = DAT_ffffeccc;
  uVar3 = DAT_ffffeccc;
  DAT_ffffeccc = uVar3 & 0xfffffffc;
  return CONCAT44(uVar4,uVar2) & 0xfffffffffffffff9 | 1;
}



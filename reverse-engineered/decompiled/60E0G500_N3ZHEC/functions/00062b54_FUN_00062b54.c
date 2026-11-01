/* ROM address: 0x00062b54; body bytes: 112; decompiled */

undefined4 FUN_00062b54(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (DAT_ffff87cc._0_1_ == '\x02') {
    uVar1 = (uint)DAT_ffff87c4;
    DAT_ffff8e9a = FUN_00002420((int)(char)(&DAT_ffff8d7c)[uVar1 * 2]);
    DAT_ffff8e9c = FUN_00002420((int)(char)(&DAT_ffff8d7d)[uVar1 * 2]);
    DAT_ffff8e98 = FUN_00002420((int)DAT_ffff8e94._0_1_);
    DAT_ffff87cc = FUN_00002420(1);
  }
  else if (DAT_ffff87cc._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87cc = FUN_00002420(1);
  }
  return uVar2;
}



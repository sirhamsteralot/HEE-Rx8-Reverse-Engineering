/* ROM address: 0x00029e0c; body bytes: 64; decompiled */

uint FUN_00029e0c(void)

{
  uint uVar1;
  
  if (DAT_ffffbc23 == '\x01') {
    DAT_ffffbb68 = 0xffff;
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_00002490(DAT_ffffbc1c,0x3c23d70a,0xc2c80000);
    if ((undefined *)(uVar1 & 0xffff) < (undefined *)0x9c41) {
      DAT_ffffbb68 = (undefined2)uVar1;
    }
    else {
      DAT_ffffbb68 = 40000;
    }
  }
  return uVar1;
}



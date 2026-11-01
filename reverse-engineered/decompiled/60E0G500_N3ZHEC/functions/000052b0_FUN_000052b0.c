/* ROM address: 0x000052b0; body bytes: 28; decompiled */

uint FUN_000052b0(void)

{
  byte bVar1;
  uint uVar2;
  
  DAT_fffff708 = 1;
  bVar1 = DAT_fffff70a._1_1_;
  if ((bVar1 & 2) != 0) {
    uVar2 = FUN_0000a370();
    return uVar2;
  }
  return (uint)bVar1;
}



/* ROM address: 0x00007eca; body bytes: 88; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00007ef0) */

uint FUN_00007eca(void)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  
  uVar1 = DAT_fffff6e8;
  if ((uVar1 & 1) != 0) {
    DAT_ffff9fce = 1;
  }
  DAT_ffff9fa0 = 1;
  bVar3 = DAT_ffff9fce;
  if (DAT_ffff9fa3 == '\x02') {
    bVar3 = DAT_ffff9fa0;
  }
  if ((bVar3 == 1) && (DAT_ffff9f8c == '\0')) {
    DAT_ffff9f8c = 1;
    uVar2 = FUN_0000763e();
    return uVar2;
  }
  return (uint)bVar3;
}



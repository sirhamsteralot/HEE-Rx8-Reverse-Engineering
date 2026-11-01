/* ROM address: 0x0005ee08; body bytes: 206; decompiled */

char FUN_0005ee08(void)

{
  char cVar1;
  byte local_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  
  cVar1 = FUN_00038ed8(100,&local_14,3);
  if (cVar1 == '\0') {
    DAT_ffffd3d0 = ((uint)local_14 * 0x100 + (uint)bStack_13) * 0x10000 +
                   ((uint)bStack_12 * 0x100 + (uint)bStack_11 & (uint)&PTR_FUN_0000ff00) + 0x20;
  }
  cVar1 = FUN_00038ed8(0x68,&local_14,1);
  if (cVar1 == '\0') {
    DAT_ffffd3d6 = local_14;
  }
  cVar1 = FUN_00038ed8(0x6a,&local_14,2);
  if (cVar1 == '\0') {
    DAT_ffffd3d4 = (ushort)local_14 * 0x100 + (ushort)bStack_13;
  }
  cVar1 = FUN_00038ed8(0x6c,&local_14,1);
  if (cVar1 == '\0') {
    DAT_ffffd3d7 = local_14;
  }
  return cVar1;
}



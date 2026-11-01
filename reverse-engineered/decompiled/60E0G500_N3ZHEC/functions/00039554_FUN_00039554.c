/* ROM address: 0x00039554; body bytes: 90; decompiled */

uint FUN_00039554(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffa42c;
  uVar2 = (uint)DAT_ffffc56f;
  if ((uVar2 == 1) && (40.0 <= DAT_ffffc538)) {
    uVar2 = FUN_00002460((int)DAT_ffffc56a,1);
    DAT_ffffc56a = (short)uVar2;
  }
  if ((DAT_ffffa428 == '\0') ||
     ((uVar2 = (uint)(char)DAT_ffffc594, uVar2 == 0 && (uVar2 = (uint)bVar1, uVar2 == 1)))) {
    DAT_ffffc56c = 0;
  }
  DAT_ffffc594 = bVar1;
  return uVar2;
}



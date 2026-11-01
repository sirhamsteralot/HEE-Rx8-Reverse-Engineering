/* ROM address: 0x00055410; body bytes: 58; decompiled */

void FUN_00055410(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = FUN_00003920(0x10);
  puVar2 = &DAT_ffff9010;
  DAT_ffff9039 = 0;
  do {
    DAT_ffff9039 = DAT_ffff9039 + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (DAT_ffff9039 < 0x28);
  DAT_ffff903a = (ushort)DAT_ffff9039;
  DAT_ffff9038 = 0xa5;
  FUN_00003934(uVar1);
  return;
}



/* ROM address: 0x0000787a; body bytes: 470; decompiled */

undefined4 * FUN_0000787a(void)

{
  char cVar2;
  undefined4 *puVar1;
  byte bVar3;
  uint uVar4;
  
  if (0x24 < DAT_ffff9f95) {
    FUN_00007724();
  }
  DAT_ffff9f95 = (&DAT_0000d76c)[(uint)DAT_ffff9f95 * 2];
  if ((DAT_ffff9fc3 != 0) && (DAT_ffff9f95 = DAT_ffff9f95 + DAT_ffff9fc3, 0x23 < DAT_ffff9f95)) {
    DAT_ffff9f95 = DAT_ffff9f95 - 0x24;
  }
  uVar4 = (uint)DAT_ffff9fc5 + (uint)DAT_ffff9fc3 + 1;
  if (uVar4 < 0x100) {
    DAT_ffff9fc5 = (byte)uVar4;
  }
  else {
    DAT_ffff9fc5 = 0xff;
  }
  DAT_ffff9fbc = DAT_ffff9fbc + (float)(DAT_ffff9fc3 + 1) * 10.0;
  if (DAT_ffff9fc2 != 0xff) {
    DAT_ffff9fc2 = DAT_ffff9fc2 + 1;
  }
  if (DAT_ffff9fc1 == '\x03') {
    puVar1 = (undefined4 *)(uint)DAT_ffff9f95;
    if ((puVar1 == (undefined4 *)&UNK_0000001c) || (puVar1 == (undefined4 *)&UNK_0000000a)) {
      DAT_ffff9fc1 = '\x02';
      DAT_ffff9fc2 = 0;
    }
  }
  else if (DAT_ffff9fc1 == '\x02') {
    cVar2 = FUN_00007ab2(0x3fd872b0);
    if (cVar2 == '\0') {
      puVar1 = (undefined4 *)0x0;
      if (4 < DAT_ffff9fc2) {
        DAT_ffff9fa2 = 2;
        puVar1 = (undefined4 *)FUN_00007724();
        return puVar1;
      }
    }
    else {
      DAT_ffff9fc1 = '\x01';
      DAT_ffff9f95 = DAT_ffff9f95 + *(char *)((int)&PTR_LAB_0000d7b6 + (uint)DAT_ffff9fc2);
      puVar1 = (undefined4 *)(uint)DAT_ffff9fc2;
      if (puVar1 == (undefined4 *)&UNK_00000003) {
        DAT_ffff9fa2 = 0;
      }
      else {
        DAT_ffff9fa2 = 1;
      }
    }
  }
  else if (DAT_ffff9fc1 == '\x01') {
    if (((DAT_ffff9fa4 != '\x01') || (DAT_ffff9fa1 == '\0')) ||
       (puVar1 = (undefined4 *)&UNK_00000001, DAT_ffff9fc0 == '\0')) {
      uVar4 = FUN_00007ab2(0x3f256042);
      puVar1 = (undefined4 *)(uVar4 & 0xff);
      if (puVar1 == (undefined4 *)0x0) {
        bVar3 = 0x22;
      }
      else {
        bVar3 = 0x12;
      }
      if (DAT_ffff9f95 == bVar3) {
        if (DAT_ffff9fa1 != -1) {
          DAT_ffff9fa1 = DAT_ffff9fa1 + '\x01';
        }
      }
      else {
        DAT_ffff9fa1 = '\0';
        DAT_ffff9f95 = bVar3;
      }
    }
    DAT_ffff9fc1 = '\x03';
  }
  else {
    if (DAT_ffff9fc1 != '\0') {
      puVar1 = (undefined4 *)FUN_00007724();
      return puVar1;
    }
    puVar1 = &DAT_ffff9fb0;
    if (0xa2c27 < DAT_ffff9fb0) {
      DAT_ffff9fc2 = 1;
    }
    if (2 < DAT_ffff9fc2) {
      cVar2 = FUN_00007ab2(0x3fd872b0);
      puVar1 = (undefined4 *)0x0;
      if (cVar2 != '\0') {
        DAT_ffff9fc1 = '\x01';
        DAT_ffff9f95 = 0x21;
        puVar1 = &DAT_ffff9fac;
        DAT_ffff9fac = DAT_ffff9fb8;
      }
    }
  }
  return puVar1;
}



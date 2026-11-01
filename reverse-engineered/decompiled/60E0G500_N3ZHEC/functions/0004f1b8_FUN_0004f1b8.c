/* ROM address: 0x0004f1b8; body bytes: 112; decompiled */

char FUN_0004f1b8(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffd002 == '\x01') {
    DAT_ffffcfe2 = 0x17;
    puVar1 = &DAT_0007d23e;
  }
  else {
    if (DAT_ffffd12e != '\x01') {
      if (DAT_ffffcfc1 != '\0') {
        DAT_ffffcfe2 = 0;
        DAT_ffffcfe4 = 0x18;
      }
      goto LAB_0004f202;
    }
    DAT_ffffcfe2 = 0;
    puVar1 = &DAT_0007d240;
  }
  DAT_ffffcfe4 = *puVar1;
LAB_0004f202:
  if (DAT_ffffcffb == '\x01') {
    DAT_ffffcfec = 0x4b;
  }
  else if (DAT_ffffcfc1 != '\0') {
    DAT_ffffcfec = 0x46;
  }
  return DAT_ffffcffb;
}



/* ROM address: 0x0004bff6; body bytes: 94; decompiled */

uint FUN_0004bff6(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffa42c;
  if ((DAT_ffffaae0 == '\0') || (DAT_ffffa41c == '\x01')) {
    DAT_ffffce85 = 0;
  }
  else if ((uVar1 == 1) && (1 < DAT_ffffce87)) {
    DAT_ffffce85 = 1;
  }
  if (uVar1 == 1) {
    uVar1 = FUN_00002478((int)(char)DAT_ffffce87,1);
    DAT_ffffce87 = (byte)uVar1;
  }
  else {
    DAT_ffffce87 = 0;
  }
  return uVar1;
}



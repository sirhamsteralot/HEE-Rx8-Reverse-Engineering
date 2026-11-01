/* ROM address: 0x00006cdc; body bytes: 114; decompiled */

char FUN_00006cdc(void)

{
  char cVar1;
  
  if (DAT_ffff9f31 == '\0') {
    return '\0';
  }
  if (DAT_ffff9f31 == '\b') {
    DAT_ffff9f22 = DAT_fffff84e;
    DAT_ffff9f20 = DAT_fffff84c;
    DAT_ffff9f1e = DAT_fffff84a;
    DAT_ffff9f1c = DAT_fffff848;
  }
  else if (DAT_ffff9f31 != '\x04') {
    cVar1 = '\x01';
    if (DAT_ffff9f31 != '\x01') {
      DAT_ffff9f2f = 0;
      DAT_ffff9f30 = 0;
      return DAT_ffff9f31;
    }
    goto LAB_00006d42;
  }
  DAT_ffff9f1a = DAT_fffff846;
  DAT_ffff9f18 = DAT_fffff844;
  cVar1 = '2';
  DAT_ffff9f16 = DAT_fffff842;
LAB_00006d42:
  DAT_ffff9f14 = DAT_fffff840;
  DAT_ffff9f30 = 0;
  DAT_ffff9f2f = 0;
  return cVar1;
}



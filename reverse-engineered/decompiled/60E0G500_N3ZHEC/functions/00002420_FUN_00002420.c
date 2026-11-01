/* ROM address: 0x00002420; body bytes: 16; decompiled */

int FUN_00002420(uint param_1)

{
  return (param_1 & 0xff) * 0x100 + (~param_1 & 0xff);
}



/* ROM address: 0x00029e88; body bytes: 64; decompiled */

undefined1 * FUN_00029e88(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_00078d60;
  if (DAT_ffffccd1 < 3) {
    puVar1 = (undefined1 *)FUN_000024d0(DAT_ffffaa40,0x3f000000,0);
    DAT_ffffbb6a = (byte)puVar1;
    if (200 < DAT_ffffbb6a) {
      DAT_ffffbb6a = 200;
    }
  }
  else {
    DAT_ffffbb6a = 0xff;
  }
  return puVar1;
}



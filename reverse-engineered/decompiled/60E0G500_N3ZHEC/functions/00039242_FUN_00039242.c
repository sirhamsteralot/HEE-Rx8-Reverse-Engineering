/* ROM address: 0x00039242; body bytes: 48; decompiled */

undefined4 * FUN_00039242(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)&DAT_0007a5c0;
  DAT_ffffc538 = DAT_ffffaa10;
  if (0x9ff < DAT_ffffa424) {
    puVar1 = &DAT_00039310;
    DAT_ffffc538 = DAT_ffffc53c + DAT_ffffc540 * 0.099999994;
  }
  DAT_ffffc53c = DAT_ffffc538;
  DAT_ffffc540 = 0.0;
  return puVar1;
}



/* ROM address: 0x00000450; body bytes: 44; decompiled */

undefined4 FUN_00000450(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  puVar2 = &DAT_ffffdfe4;
  if (DAT_ffffdfec != 'U') {
    return 0xffffffff;
  }
  uVar3 = 0;
  do {
    uVar3 = uVar3 + 1;
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  } while (uVar3 < 8);
  DAT_ffffdfec = 0xaa;
  return 1;
}



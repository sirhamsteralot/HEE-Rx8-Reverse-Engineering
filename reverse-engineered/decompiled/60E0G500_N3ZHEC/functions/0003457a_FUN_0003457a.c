/* ROM address: 0x0003457a; body bytes: 122; decompiled */

undefined4 * FUN_0003457a(void)

{
  undefined4 *puVar1;
  float fVar2;
  
  fVar2 = (float)FUN_000024c0(0x3e200000,0,(int)DAT_ffffc0fc);
  puVar1 = (undefined4 *)0x0;
  if ((((DAT_ffffc0e4 == 0) || (puVar1 = (undefined4 *)&DAT_ffffa428, DAT_ffffa428 == '\0')) ||
      (puVar1 = (undefined4 *)&DAT_0007a17c, DAT_ffffa424 < 0xfa)) ||
     ((puVar1 = &DAT_0003465c, DAT_ffffa63c <= 5.0 - fVar2 ||
      (puVar1 = &DAT_0003465c, DAT_ffffa644 <= 5.0 - fVar2)))) {
    DAT_ffffc0c4 = 0;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffc0e4;
    if (puVar1 == (undefined4 *)&UNK_00000001) {
      DAT_ffffc0c4 = 1;
    }
  }
  return puVar1;
}



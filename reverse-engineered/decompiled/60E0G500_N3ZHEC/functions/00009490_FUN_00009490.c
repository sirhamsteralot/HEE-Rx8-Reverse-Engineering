/* ROM address: 0x00009490; body bytes: 50; decompiled */

uint FUN_00009490(void)

{
  uint uVar1;
  undefined2 *puVar2;
  
  uVar1 = FUN_0000213c(DAT_ffff9f80,DAT_ffff9f68,&DAT_0006bf28);
  puVar2 = (undefined2 *)((uVar1 & 0xffff) + (uint)DAT_ffffa0d6);
  if (puVar2 < &DAT_00010000) {
    DAT_ffffa0d4 = SUB42(puVar2,0);
  }
  else {
    DAT_ffffa0d4 = 0xffff;
  }
  return uVar1 & 0xffff;
}



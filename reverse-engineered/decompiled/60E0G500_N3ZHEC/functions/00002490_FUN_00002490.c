/* ROM address: 0x00002490; body bytes: 40; decompiled */

undefined * FUN_00002490(float param_1,float param_2,float param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = (undefined *)0xffff;
  puVar2 = (undefined *)(int)((param_1 - param_3) / param_2 + 0.5);
  if (((int)puVar2 < (int)&DAT_00010000) && (puVar1 = puVar2, (int)puVar2 < 0)) {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}



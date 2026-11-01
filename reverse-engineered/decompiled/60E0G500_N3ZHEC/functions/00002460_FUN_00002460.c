/* ROM address: 0x00002460; body bytes: 20; decompiled */

undefined * FUN_00002460(uint param_1,uint param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)((param_1 & 0xffff) + (param_2 & 0xffff));
  if ((undefined *)0xfffe < puVar1) {
    puVar1 = (undefined *)0xffff;
  }
  return puVar1;
}



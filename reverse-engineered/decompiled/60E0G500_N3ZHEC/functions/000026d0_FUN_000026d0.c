/* ROM address: 0x000026d0; body bytes: 34; decompiled */

undefined2 FUN_000026d0(void)

{
  int in_r0;
  undefined2 uVar1;
  int in_r1;
  undefined2 *puVar2;
  float in_fr0;
  
  puVar2 = (undefined2 *)(in_r1 + in_r0 * 2);
  uVar1 = *puVar2;
  if (in_fr0 != 0.0) {
    uVar1 = puVar2[1];
  }
  return uVar1;
}



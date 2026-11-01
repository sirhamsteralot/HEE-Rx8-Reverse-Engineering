/* ROM address: 0x0000a230; body bytes: 54; decompiled */

undefined * FUN_0000a230(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  param_1 = param_1 * 0xc;
  *(undefined4 *)(&DAT_ffffa170 + (uint)(byte)(&DAT_ffffa178)[param_1] * 4 + param_1) = param_2;
  (&DAT_ffffa178)[param_1] = (&DAT_ffffa178)[param_1] + '\x01';
  puVar1 = (undefined *)(uint)(byte)(&DAT_ffffa178)[param_1];
  if (&UNK_00000001 < puVar1) {
    puVar1 = &DAT_ffffa178;
    (&DAT_ffffa178)[param_1] = 0;
  }
  return puVar1;
}



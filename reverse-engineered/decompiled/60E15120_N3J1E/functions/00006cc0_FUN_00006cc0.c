/* ROM address: 0x00006cc0; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006cc0 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00006cc0(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  uVar2 = ADDR15H_B;
  *(undefined2 *)(param_1 + 0x1e) = uVar2;
  uVar2 = ADDR14H_B;
  *(undefined2 *)(param_1 + 0x1c) = uVar2;
  uVar2 = ADDR13H_B;
  *(undefined2 *)(param_1 + 0x1a) = uVar2;
  sVar1 = ADDR12H_B;
  *(short *)(param_1 + 0x18) = sVar1;
  return (int)sVar1;
}



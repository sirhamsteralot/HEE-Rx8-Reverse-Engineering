/* ROM address: 0x0000f254; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000f258 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000f254(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  for (uVar1 = param_1 + 0x10;
      (uVar2 = 1, uVar1 < param_1 + 0x58U && (uVar2 = 0, *(int *)(uVar1 + 0x10) <= param_2));
      uVar1 = uVar1 + 0x18) {
  }
  return uVar2;
}



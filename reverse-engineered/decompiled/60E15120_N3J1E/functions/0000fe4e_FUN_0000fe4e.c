/* ROM address: 0x0000fe4e; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000fe52 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000fe4e(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x10;
  while( true ) {
    if (param_1 + 0x58U <= uVar2) {
      return 1;
    }
    if ((param_2 <= *(int *)(uVar2 + 0x10)) || (iVar1 = FUN_0000feb4(uVar2), param_2 < iVar1))
    break;
    uVar2 = uVar2 + 0x18;
  }
  return 0;
}



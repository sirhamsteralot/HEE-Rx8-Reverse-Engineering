/* ROM address: 0x000602a4; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eb94 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000602a4(uint param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  
  uVar1 = *(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  uVar2 = FUN_00061800((int)(short)uVar1);
  (&DAT_ffffd5fc)[uVar1] = uVar2;
  return;
}



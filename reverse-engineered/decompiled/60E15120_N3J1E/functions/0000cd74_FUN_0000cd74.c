/* ROM address: 0x0000cd74; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cd74 (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000cd74(byte param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_0000cee8((int)(char)param_1,&HCAN0_MC0_1__B);
  iVar1 = iVar1 + (param_1 & 0xf) * 8;
  if ((*(byte *)(iVar1 + 4) & 8) == 0) {
    uVar2 = (uint)(*(byte *)(iVar1 + 4) >> 5);
    uVar3 = (uint)*(byte *)(iVar1 + 5) << 3;
  }
  else {
    uVar2 = (*(byte *)(iVar1 + 4) & 3) << 0x10 | (*(byte *)(iVar1 + 4) & 0xe0) << 0xd |
            (uint)*(byte *)(iVar1 + 5) << 0x15 | (uint)*(byte *)(iVar1 + 7) << 8;
    uVar3 = (uint)*(byte *)(iVar1 + 6);
  }
  return uVar2 | uVar3;
}



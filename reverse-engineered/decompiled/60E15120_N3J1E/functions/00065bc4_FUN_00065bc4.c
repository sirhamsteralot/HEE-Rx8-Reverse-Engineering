/* ROM address: 0x00065bc4; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000644b4 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065bc4(short *param_1,ushort param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      cVar1 = FUN_00062e6a((int)*param_1);
      iVar3 = iVar3 + 1;
      if (cVar1 != '\0') {
        uVar2 = 0xc0;
      }
      param_1 = param_1 + 1;
    } while (iVar3 < (int)(uint)param_2);
  }
  return uVar2;
}



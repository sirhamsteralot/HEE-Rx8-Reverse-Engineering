/* ROM address: 0x000011fa; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000011fa (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000011fa(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  short sVar3;
  byte bVar4;
  char local_18;
  undefined1 uStack_17;
  undefined1 local_16 [10];
  
  bVar4 = 2;
  sVar3 = *(short *)(param_1 + 2);
  local_18 = (char)sVar3 + '\x01';
  puVar1 = local_16;
  uStack_17 = *param_1;
  param_1 = param_1 + 4;
  puVar2 = puVar1;
  do {
    bVar4 = bVar4 + 1;
    if (sVar3 == 0) {
      *puVar2 = 0;
    }
    else {
      *puVar1 = *param_1;
      sVar3 = sVar3 + -1;
    }
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
    puVar1 = puVar1 + 1;
  } while (bVar4 < 8);
  FUN_00001150(&local_18);
  FUN_00001182();
  return;
}



/* ROM address: 0x00006010; body bytes: 164; decompiled */

/* Function candidate recovered from ROM pointer at 9730 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00006010(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined4 local_1c;
  byte bStack_18;
  
  uVar3 = 0;
  puVar4 = (&PTR_DAT_0000d74c)[(param_1 & 0xffff) * 2];
  bStack_18 = (&DAT_0000d752)[(param_1 & 0xffff) * 8];
  FUN_00002054(&local_1c,0xe0);
  iVar2 = (param_1 & 0xffff) * 3;
  if ((&DAT_ffff9306)[iVar2] == '\0') {
    uVar3 = 3;
  }
  else {
    (&DAT_ffff9306)[iVar2] = (&DAT_ffff9306)[iVar2] + -1;
    puVar5 = (undefined4 *)(puVar4 + (uint)(byte)(&DAT_ffff9305)[iVar2] * 0x14);
    iVar2 = 5;
    do {
      iVar2 = iVar2 + -1;
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    } while (iVar2 != 0);
    iVar2 = (param_1 & 0xffff) * 3;
    (&DAT_ffff9305)[iVar2] = (&DAT_ffff9305)[iVar2] + '\x01';
    if (bStack_18 <= (byte)(&DAT_ffff9305)[iVar2]) {
      (&DAT_ffff9305)[(param_1 & 0xffff) * 3] = 0;
    }
  }
  FUN_00002064(local_1c);
  return uVar3;
}



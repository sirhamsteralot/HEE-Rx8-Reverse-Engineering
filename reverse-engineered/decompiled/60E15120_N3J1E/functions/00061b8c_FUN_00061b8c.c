/* ROM address: 0x00061b8c; body bytes: 392; decompiled */

/* Function candidate recovered from ROM pointer at 67d2c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00061b8c(uint *param_1)

{
  char cVar2;
  undefined4 uVar1;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_1;
  FUN_000623a0(uVar4);
  FUN_000623b0();
  FUN_00063e78(0);
  FUN_00063ecc(0);
  FUN_0006289a();
  cVar2 = FUN_00062df8(uVar4);
  uVar5 = uVar4 & 0xffff;
  if ((cVar2 != '\0') && (cVar2 != 'P')) {
    FUN_00062420(8);
    FUN_00062dd8(0);
    FUN_0006310a(8);
    FUN_00062e4a(0);
    FUN_00063026(0);
    FUN_00063098(0);
    FUN_00062ebc((int)(char)(&DAT_0007e442)[uVar5]);
    FUN_00062f2e((int)(char)(&DAT_0007e4ce)[uVar5]);
    FUN_00062fa0(0x50);
    FUN_000628b8();
  }
  uVar1 = FUN_00063998(uVar4);
  cVar3 = FUN_00063920(uVar1);
  if ((cVar3 != '\0') && (cVar3 != '\x01')) {
    FUN_00062570(8);
    FUN_0006381c();
    FUN_000628d6();
  }
  cVar3 = (&DAT_0007e32a)[uVar5];
  if (((cVar3 == '\x01') || (cVar3 == '\x02')) || (cVar3 == '\x03')) {
    FUN_00062668();
    FUN_00067760();
    FUN_0006763c(0);
    FUN_000676c8(0);
    FUN_0006789e(0);
    FUN_000628f4();
  }
  if (((&DAT_0007e32a)[uVar5] == '\x01') || ((&DAT_0007e32a)[uVar5] == '\x02')) {
    if ((&DAT_0007e32a)[uVar5] == '\x01') {
      cVar2 = FUN_00062df8(1);
      uVar5 = FUN_000630b8(1);
    }
    else if ((&DAT_0007e32a)[uVar5] == '\x02') {
      cVar2 = FUN_00062df8(0);
      uVar5 = FUN_000630b8(0);
    }
    FUN_000626d4(0);
    if ((cVar2 == '\0') || (cVar2 == 'P')) {
      FUN_00067b88(0);
      FUN_00067c64(0);
    }
    if ((uVar5 & 0xff) == 0) {
      FUN_00067c06(0);
    }
    FUN_00062918(0);
  }
  FUN_000627a0();
  FUN_00060a96();
  return;
}



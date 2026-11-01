/* ROM address: 0x00062330; body bytes: 392; decompiled */

/* Function candidate recovered from ROM pointer at 684d0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00062330(uint *param_1)

{
  char cVar2;
  undefined4 uVar1;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_1;
  FUN_00062b44(uVar4);
  FUN_00062b54();
  FUN_0006461c(0);
  FUN_00064670(0);
  FUN_0006303e();
  cVar2 = FUN_0006359c(uVar4);
  uVar5 = uVar4 & 0xffff;
  if ((cVar2 != '\0') && (cVar2 != 'P')) {
    FUN_00062bc4(8);
    FUN_0006357c(0);
    FUN_000638ae(8);
    FUN_000635ee(0);
    FUN_000637ca(0);
    FUN_0006383c(0);
    FUN_00063660((int)(char)(&DAT_0007dfea)[uVar5]);
    FUN_000636d2((int)(char)(&DAT_0007e076)[uVar5]);
    FUN_00063744(0x50);
    FUN_0006305c();
  }
  uVar1 = FUN_0006413c(uVar4);
  cVar3 = FUN_000640c4(uVar1);
  if ((cVar3 != '\0') && (cVar3 != '\x01')) {
    FUN_00062d14(8);
    FUN_00063fc0();
    FUN_0006307a();
  }
  cVar3 = (&DAT_0007ded2)[uVar5];
  if (((cVar3 == '\x01') || (cVar3 == '\x02')) || (cVar3 == '\x03')) {
    FUN_00062e0c();
    FUN_00067f04();
    FUN_00067de0(0);
    FUN_00067e6c(0);
    FUN_00068042(0);
    FUN_00063098();
  }
  if (((&DAT_0007ded2)[uVar5] == '\x01') || ((&DAT_0007ded2)[uVar5] == '\x02')) {
    if ((&DAT_0007ded2)[uVar5] == '\x01') {
      cVar2 = FUN_0006359c(1);
      uVar5 = FUN_0006385c(1);
    }
    else if ((&DAT_0007ded2)[uVar5] == '\x02') {
      cVar2 = FUN_0006359c(0);
      uVar5 = FUN_0006385c(0);
    }
    FUN_00062e78(0);
    if ((cVar2 == '\0') || (cVar2 == 'P')) {
      FUN_0006832c(0);
      FUN_00068408(0);
    }
    if ((uVar5 & 0xff) == 0) {
      FUN_000683aa(0);
    }
    FUN_000630bc(0);
  }
  FUN_00062f44();
  FUN_0006123a();
  return;
}



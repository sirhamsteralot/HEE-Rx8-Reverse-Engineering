/* ROM address: 0x00043cbe; body bytes: 212; decompiled */

void FUN_00043cbe(void)

{
  char cVar1;
  char cVar2;
  undefined **ppuVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  cVar2 = DAT_ffffcabd;
  cVar1 = DAT_ffffcaba;
  if (DAT_ffffaada == '\x01') {
    DAT_ffffcaad = 0;
  }
  else if (DAT_ffffcaa4 <= 5.0) {
    DAT_ffffcaad = 1;
  }
  else if (DAT_ffffcaa4 < 6.5) {
    DAT_ffffcaad = 2;
  }
  else {
    DAT_ffffcaad = 3;
  }
  if (DAT_ffffcaae == '\x02') {
    DAT_ffffca90 = DAT_ffffca98;
  }
  else {
    DAT_ffffca90 = 0;
  }
  uVar5 = DAT_ffffca98;
  uVar4 = FUN_00002500(0x3f800000,0,DAT_ffffcaad);
  if ((cVar1 == '\0') && (cVar2 == '\0')) {
    ppuVar3 = &PTR_DAT_0006bc2c;
  }
  else {
    if (cVar1 != '\0') {
      if (cVar2 == '\0') {
        ppuVar3 = &PTR_DAT_0006bc64;
      }
      else {
        ppuVar3 = &PTR_DAT_0006bc80;
      }
      DAT_ffffca88 = FUN_000020dc(DAT_ffffca90,uVar4,ppuVar3);
      goto LAB_00043dc0;
    }
    ppuVar3 = &PTR_DAT_0006bc48;
  }
  DAT_ffffca88 = FUN_000020dc(ppuVar3);
LAB_00043dc0:
  DAT_ffffca8c = FUN_00002068(uVar5,&DAT_0006bc18);
  return;
}



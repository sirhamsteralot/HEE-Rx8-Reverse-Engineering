/* ROM address: 0x0004f72a; body bytes: 212; decompiled */

char FUN_0004f72a(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  cVar2 = DAT_ffffcff9;
  DAT_ffffcff2 = DAT_ffffcff8 == '\x01';
  uVar8 = 0x3f800000;
  uVar7 = 0;
  uVar4 = FUN_00002500(0x3f800000,0,(int)DAT_ffffcfe9);
  uVar5 = FUN_00002500(uVar8,uVar7,(int)DAT_ffffcfe8);
  uVar6 = FUN_00002500(uVar8,uVar7,(int)DAT_ffffcfeb);
  uVar7 = FUN_00002500(uVar8,uVar7,(int)DAT_ffffcfea);
  if (cVar2 == '\x01') {
    puVar3 = &DAT_0006b768;
    uVar6 = uVar4;
    uVar7 = uVar5;
  }
  else {
    puVar3 = &DAT_0006b77c;
  }
  cVar1 = FUN_00002120(uVar6,uVar7,puVar3);
  DAT_ffffcff3 = 0;
  if (cVar2 == '\x01') {
    cVar2 = '\x01';
    if (DAT_ffffcff6 == '\0') {
      DAT_ffffcff3 = 1;
    }
    else if (cVar1 == '\x01') {
      DAT_ffffcff3 = 1;
    }
  }
  else {
    cVar2 = DAT_ffffcff7;
    if ((DAT_ffffcff7 == '\x01') && (cVar1 == '\x01')) {
      DAT_ffffcff3 = 1;
    }
  }
  return cVar2;
}



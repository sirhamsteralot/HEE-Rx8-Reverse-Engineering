/* ROM address: 0x00060596; body bytes: 272; decompiled */

void FUN_00060596(void)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  undefined4 uVar4;
  short sStack00000000;
  short sStack00000002;
  char cStack00000004;
  char cStack00000006;
  
  cVar2 = FUN_00062570((int)cStack00000004);
  if (cVar2 != '\x01') goto LAB_000606ae;
  uVar4 = 0xc0;
  if (cStack00000006 == '\x01') {
    uVar4 = FUN_000609fe((int)sStack00000000);
    FUN_00060872(uVar4,(int)sStack00000000,(int)cStack00000004,0x10);
  }
  else if (cStack00000006 == '\x02') {
    uVar4 = FUN_000609fe((int)sStack00000000);
    FUN_00060872(uVar4,(int)sStack00000000,(int)cStack00000004,0xc0);
  }
  else {
    if (cStack00000006 != '\x03') {
      if (cStack00000006 == '\x04') {
        uVar1 = FUN_00063998();
        uVar4 = 0x10;
LAB_00060688:
        iVar3 = (int)cStack00000004;
      }
      else {
        if (cStack00000006 == '\x05') {
          uVar1 = FUN_00063998();
          goto LAB_00060688;
        }
        if (cStack00000006 == '\x06') {
          uVar1 = FUN_00063998();
          goto LAB_00060688;
        }
        if (cStack00000006 != '\a') {
          if ((cStack00000006 != '\b') && (cStack00000006 == '\t')) {
            uVar4 = FUN_00063998();
            FUN_00060872(uVar4,(int)sStack00000000,7,1);
          }
          goto LAB_000606ae;
        }
        uVar1 = FUN_00063998();
        uVar4 = 1;
        iVar3 = 7;
      }
      FUN_00060872(uVar1,(int)sStack00000000,iVar3,uVar4);
      goto LAB_000606ae;
    }
    uVar4 = FUN_00063998();
    FUN_00060872(uVar4,(int)sStack00000000,(int)cStack00000004,0xc0);
  }
  FUN_000608c8(uVar4,(int)sStack00000000,(int)sStack00000002);
LAB_000606ae:
  FUN_000628d6();
  return;
}



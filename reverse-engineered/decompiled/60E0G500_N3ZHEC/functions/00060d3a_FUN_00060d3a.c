/* ROM address: 0x00060d3a; body bytes: 272; decompiled */

void FUN_00060d3a(void)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  undefined4 uVar4;
  short sStack00000000;
  short sStack00000002;
  char cStack00000004;
  char cStack00000006;
  
  cVar2 = FUN_00062d14((int)cStack00000004);
  if (cVar2 != '\x01') goto LAB_00060e52;
  uVar4 = 0xc0;
  if (cStack00000006 == '\x01') {
    uVar4 = FUN_000611a2((int)sStack00000000);
    FUN_00061016(uVar4,(int)sStack00000000,(int)cStack00000004,0x10);
  }
  else if (cStack00000006 == '\x02') {
    uVar4 = FUN_000611a2((int)sStack00000000);
    FUN_00061016(uVar4,(int)sStack00000000,(int)cStack00000004,0xc0);
  }
  else {
    if (cStack00000006 != '\x03') {
      if (cStack00000006 == '\x04') {
        uVar1 = FUN_0006413c();
        uVar4 = 0x10;
LAB_00060e2c:
        iVar3 = (int)cStack00000004;
      }
      else {
        if (cStack00000006 == '\x05') {
          uVar1 = FUN_0006413c();
          goto LAB_00060e2c;
        }
        if (cStack00000006 == '\x06') {
          uVar1 = FUN_0006413c();
          goto LAB_00060e2c;
        }
        if (cStack00000006 != '\a') {
          if ((cStack00000006 != '\b') && (cStack00000006 == '\t')) {
            uVar4 = FUN_0006413c();
            FUN_00061016(uVar4,(int)sStack00000000,7,1);
          }
          goto LAB_00060e52;
        }
        uVar1 = FUN_0006413c();
        uVar4 = 1;
        iVar3 = 7;
      }
      FUN_00061016(uVar1,(int)sStack00000000,iVar3,uVar4);
      goto LAB_00060e52;
    }
    uVar4 = FUN_0006413c();
    FUN_00061016(uVar4,(int)sStack00000000,(int)cStack00000004,0xc0);
  }
  FUN_0006106c(uVar4,(int)sStack00000000,(int)sStack00000002);
LAB_00060e52:
  FUN_0006307a();
  return;
}



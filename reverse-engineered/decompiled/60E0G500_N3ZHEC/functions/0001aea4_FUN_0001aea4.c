/* ROM address: 0x0001aea4; body bytes: 40; decompiled */

int FUN_0001aea4(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  
  FUN_0001aefa();
  uVar1 = DAT_ffffaa84;
  bVar3 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)&DAT_ffffaa94 + iVar2) = uVar1;
    bVar3 = bVar3 + 1;
    *(undefined4 *)((int)&DAT_ffffaaac + iVar2) = uVar1;
    iVar2 = iVar2 + 4;
  } while (bVar3 < 6);
  return iVar2;
}



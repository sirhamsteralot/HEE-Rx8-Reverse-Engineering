/* ROM address: 0x0001afd8; body bytes: 90; decompiled */

void FUN_0001afd8(void)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  float arg1;
  
  iVar2 = 0;
  bVar1 = 0;
  arg1 = DAT_ffffaa84;
  do {
    fVar3 = rx8_max_float(*(float *)((int)&DAT_ffffaa94 + iVar2),arg1);
    *(float *)((int)&DAT_ffffaa94 + iVar2) = fVar3;
    fVar3 = rx8_min_float(*(float *)((int)&DAT_ffffaaac + iVar2),arg1);
    bVar1 = bVar1 + 1;
    *(float *)((int)&DAT_ffffaaac + iVar2) = fVar3;
    iVar2 = iVar2 + 4;
  } while (bVar1 < 6);
  return;
}



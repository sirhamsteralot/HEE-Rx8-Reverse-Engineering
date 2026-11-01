/* ROM address: 0x000084c6; body bytes: 244; decompiled */

undefined4 FUN_000084c6(uint param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 local_20;
  int *piStack_1c;
  
  iVar5 = (param_1 & 0xff) * 0x18;
  if ((&DAT_ffffa017)[iVar5] == '\0') {
    uVar2 = 1;
    if ((&DAT_ffffa018)[iVar5] != '\x01') {
      FUN_00002054(&local_20,0xe0);
      ppuVar4 = &PTR_DAT_0000d7d4 + (param_1 & 0xff) * 3;
      if ((3 < *(ushort *)*ppuVar4) && ((&DAT_ffffa016)[iVar5] != '\x01')) {
        iVar3 = param_2 - *(int *)(&DAT_ffffa010 + iVar5);
        uVar1 = *(ushort *)*ppuVar4;
        if (iVar3 < 1) {
          if ((-iVar3 >> 4 & 0xffffU) < (uint)uVar1) {
            iVar3 = (int)(short)uVar1 - (-iVar3 >> 4);
          }
          else {
            iVar3 = 0;
          }
        }
        else {
          iVar3 = (int)(short)uVar1 + (iVar3 >> 4);
        }
        FUN_0000a8a4(*ppuVar4,iVar3);
      }
      uVar2 = FUN_00002064(local_20);
    }
    *(int *)(&DAT_ffffa010 + iVar5) = param_2;
  }
  else {
    piStack_1c = (int *)(&DAT_ffffa004 + iVar5);
    *piStack_1c = param_2;
    uVar2 = FUN_0000871c(param_1);
    if (piStack_1c[1] < 0x230000) {
      FUN_00008814(param_1);
      uVar2 = 0x13;
      (&DAT_ffffa017)[iVar5] = 0;
    }
  }
  return uVar2;
}



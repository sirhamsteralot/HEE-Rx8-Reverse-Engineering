/* ROM address: 0x00050ef0; body bytes: 284; decompiled */

undefined1 * FUN_00050ef0(void)

{
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 *puVar1;
  undefined4 uVar2;
  
  bVar3 = FUN_0003eaa4(&DAT_ffff8704,4);
  bVar4 = FUN_0003eaa4(&DAT_ffff86ea,0);
  bVar5 = FUN_0003eaa4(&DAT_ffff86e8,0);
  bVar6 = FUN_0003eaa4(&DAT_ffff86ce,0);
  bVar7 = FUN_0003eaa4(&DAT_ffff86cc,0);
  bVar8 = FUN_0003eaa4(&DAT_ffff86c8,0);
  if ((undefined1 *)(uint)DAT_ffffd201 != (undefined1 *)0x1) {
    if (DAT_ffffcfb4 != '\0') {
      DAT_ffffd0ba = bVar3;
      DAT_ffffd0c1 = bVar7;
      DAT_ffffd0c2 = bVar6;
      DAT_ffffd0c3 = bVar8;
      DAT_ffffd0c4 = bVar5;
      DAT_ffffd0c5 = bVar4;
      return (undefined1 *)(uint)DAT_ffffd201;
    }
    puVar1 = &DAT_ffffcfc1;
    if (DAT_ffffcfc1 != '\0') {
      DAT_ffffd0ba = bVar3;
      DAT_ffffd0c1 = bVar7;
      DAT_ffffd0c2 = bVar6;
      DAT_ffffd0c3 = bVar8;
      DAT_ffffd0c4 = bVar5;
      DAT_ffffd0c5 = bVar4;
      return puVar1;
    }
    if (((DAT_ffffd0ba <= bVar3) &&
        ((DAT_ffffd0c5 != '\0' || (puVar1 = (undefined1 *)(uint)bVar4, puVar1 != (undefined1 *)0x1))
        )) && ((DAT_ffffd0c4 != '\0' ||
               (puVar1 = (undefined1 *)(uint)bVar5, puVar1 != (undefined1 *)0x1)))) {
      if (((DAT_ffffd0c1 != '\0') ||
          (puVar1 = (undefined1 *)(uint)bVar7, puVar1 != (undefined1 *)0x1)) &&
         ((DAT_ffffd0c2 != '\0' || (puVar1 = (undefined1 *)(uint)bVar6, puVar1 != (undefined1 *)0x1)
          ))) {
        if (DAT_ffffd0c3 != '\0') {
          DAT_ffffd0ba = bVar3;
          DAT_ffffd0c1 = bVar7;
          DAT_ffffd0c2 = bVar6;
          DAT_ffffd0c3 = bVar8;
          DAT_ffffd0c4 = bVar5;
          DAT_ffffd0c5 = bVar4;
          return puVar1;
        }
        if ((undefined1 *)(uint)bVar8 != (undefined1 *)0x1) {
          DAT_ffffd0ba = bVar3;
          DAT_ffffd0c1 = bVar7;
          DAT_ffffd0c2 = bVar6;
          DAT_ffffd0c3 = bVar8;
          DAT_ffffd0c4 = bVar5;
          DAT_ffffd0c5 = bVar4;
          return (undefined1 *)(uint)bVar8;
        }
      }
      uVar2 = FUN_0003eaa4(&DAT_ffff86c4,0);
      puVar1 = (undefined1 *)FUN_0003ebc0(&DAT_ffff86c6,uVar2);
      DAT_ffffd0ba = bVar3;
      DAT_ffffd0c1 = bVar7;
      DAT_ffffd0c2 = bVar6;
      DAT_ffffd0c3 = bVar8;
      DAT_ffffd0c4 = bVar5;
      DAT_ffffd0c5 = bVar4;
      return puVar1;
    }
  }
  FUN_0003ebc0(&DAT_ffff86c4,0);
  puVar1 = (undefined1 *)FUN_0003ebc0(&DAT_ffff86c6,0);
  DAT_ffffd0ba = bVar3;
  DAT_ffffd0c5 = bVar4;
  DAT_ffffd0c4 = bVar5;
  DAT_ffffd0c2 = bVar6;
  DAT_ffffd0c1 = bVar7;
  DAT_ffffd0c3 = bVar8;
  return puVar1;
}



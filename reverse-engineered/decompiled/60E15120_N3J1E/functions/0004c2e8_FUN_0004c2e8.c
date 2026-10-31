/* ROM address: 0x0004c2e8; body bytes: 136; decompiled */

undefined1 * FUN_0004c2e8(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  uVar1 = PHDR_W;
  DAT_ffffce9e = (uVar1 & 0x1000) == 0;
  uVar1 = PHDR_W;
  DAT_ffffce9f = (uVar1 & 0x2000) == 0;
  puVar3 = (undefined1 *)(uint)apv_drive_status_ffffa1bc;
  puVar2 = &DAT_ffffceac;
  if (puVar3 == (undefined1 *)(uint)DAT_ffffceac) {
    if (puVar3 == (undefined1 *)0x0) {
      DAT_ffffce97 = 1;
      DAT_ffffce94 = 0;
      DAT_ffffce95 = 0;
    }
    else {
      puVar2 = puVar3;
      if (puVar3 == (undefined1 *)((int)&vector_Poweron_Reset + 2)) {
        DAT_ffffce95 = 1;
        DAT_ffffce97 = 0;
        DAT_ffffce94 = 0;
      }
      else {
        if (puVar3 != (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
          if (puVar3 != (undefined1 *)((int)&vector_Poweron_Reset + 3)) {
            DAT_ffffceac = apv_drive_status_ffffa1bc;
            return puVar3;
          }
          DAT_ffffce94 = 0;
          DAT_ffffce95 = 0;
          DAT_ffffce96 = 1;
          DAT_ffffce97 = 0;
          DAT_ffffceac = apv_drive_status_ffffa1bc;
          return puVar3;
        }
        DAT_ffffce94 = 1;
        DAT_ffffce97 = 0;
        DAT_ffffce95 = 0;
      }
    }
    DAT_ffffce96 = 0;
  }
  DAT_ffffceac = apv_drive_status_ffffa1bc;
  return puVar2;
}



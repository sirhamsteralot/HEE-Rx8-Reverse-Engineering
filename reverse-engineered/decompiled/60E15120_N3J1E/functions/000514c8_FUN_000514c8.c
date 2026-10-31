/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b538: Table 2D - 249 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000514c8; body bytes: 332; decompiled */

undefined4 * FUN_000514c8(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char cVar5;
  
  DAT_ffffd0fc = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_249_0006b538);
  uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff869c,0);
  cVar5 = -((((int)(char)DAT_ffffcfb5 & 0x80U) == 0) + -1);
  if (((DAT_ffffd109 == '\0') && (cVar5 == '\x01')) || (DAT_ffffd0f3 == '\x01')) {
    puVar4 = (undefined4 *)0x1;
    DAT_ffffd0f2 = 0;
    bVar1 = false;
  }
  else {
    puVar4 = (undefined4 *)(uint)DAT_ffffd00e;
    if (((((puVar4 == (undefined4 *)0x1) &&
          (puVar4 = (undefined4 *)(uint)DAT_ffffd0f1, puVar4 == (undefined4 *)0x1)) &&
         ((puVar4 = (undefined4 *)(int)DAT_ffffd0f0, puVar4 == (undefined4 *)0x0 &&
          ((DAT_ffffa9bc < DAT_ffffd0fc &&
           (puVar4 = (undefined4 *)&DAT_ffffaa62, DAT_ffffaa62 == '\0')))))) &&
        ((puVar4 = (undefined4 *)-(((DAT_ffffcfb5 & 0x20) == 0) - 1), puVar4 == (undefined4 *)0x1 &&
         ((puVar4 = (undefined4 *)(uint)DAT_ffffb2f6, puVar4 == (undefined4 *)0x1 &&
          (puVar4 = (undefined4 *)(int)DAT_ffffcfc3, puVar4 == (undefined4 *)0x0)))))) &&
       (((uVar2 & 0xff) == 1 || (puVar4 = (undefined4 *)(uVar2 & 0xff), puVar4 == (undefined4 *)0x3)
        ))) {
      uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c6,0);
      puVar4 = (undefined4 *)(uVar3 & 0xff);
      if ((((((puVar4 != (undefined4 *)(uVar2 & 0xff)) &&
             (puVar4 = (undefined4 *)(int)DAT_ffffd10e, puVar4 == (undefined4 *)0x0)) &&
            (DAT_ffffcac9 == '\0')) &&
           ((puVar4 = (undefined4 *)&DAT_ffffcf78, DAT_ffffcf78 == '\0' && (DAT_ffffcf85 == '\0'))))
          && (DAT_ffffd240 == 0)) && (DAT_ffffcd74 == '\0')) {
        puVar4 = (undefined4 *)0x1;
        DAT_ffffd0f2 = 1;
        bVar1 = true;
        goto LAB_00051632;
      }
    }
    DAT_ffffd0f2 = 0;
    bVar1 = false;
  }
LAB_00051632:
  if (!bVar1) {
    puVar4 = &DAT_00051680;
    DAT_ffffd0dc = 0x3d1ba5e3;
  }
  DAT_ffffd109 = cVar5;
  return puVar4;
}



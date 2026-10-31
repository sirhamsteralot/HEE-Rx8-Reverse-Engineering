/* ROM address: 0x0005074c; body bytes: 284; decompiled */

undefined1 * FUN_0005074c(void)

{
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 *puVar1;
  undefined4 uVar2;
  
  bVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86dc,4);
  bVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c2,0);
  bVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c0,0);
  bVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a6,0);
  bVar7 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0);
  bVar8 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0);
  if ((undefined1 *)(uint)DAT_ffffd1c5 != (undefined1 *)0x1) {
    if (DAT_ffffcf78 != '\0') {
      DAT_ffffd07e = bVar3;
      DAT_ffffd085 = bVar7;
      DAT_ffffd086 = bVar6;
      DAT_ffffd087 = bVar8;
      DAT_ffffd088 = bVar5;
      DAT_ffffd089 = bVar4;
      return (undefined1 *)(uint)DAT_ffffd1c5;
    }
    puVar1 = &DAT_ffffcf85;
    if (DAT_ffffcf85 != '\0') {
      DAT_ffffd07e = bVar3;
      DAT_ffffd085 = bVar7;
      DAT_ffffd086 = bVar6;
      DAT_ffffd087 = bVar8;
      DAT_ffffd088 = bVar5;
      DAT_ffffd089 = bVar4;
      return puVar1;
    }
    if (((DAT_ffffd07e <= bVar3) &&
        ((DAT_ffffd089 != '\0' || (puVar1 = (undefined1 *)(uint)bVar4, puVar1 != (undefined1 *)0x1))
        )) && ((DAT_ffffd088 != '\0' ||
               (puVar1 = (undefined1 *)(uint)bVar5, puVar1 != (undefined1 *)0x1)))) {
      if (((DAT_ffffd085 != '\0') ||
          (puVar1 = (undefined1 *)(uint)bVar7, puVar1 != (undefined1 *)0x1)) &&
         ((DAT_ffffd086 != '\0' || (puVar1 = (undefined1 *)(uint)bVar6, puVar1 != (undefined1 *)0x1)
          ))) {
        if (DAT_ffffd087 != '\0') {
          DAT_ffffd07e = bVar3;
          DAT_ffffd085 = bVar7;
          DAT_ffffd086 = bVar6;
          DAT_ffffd087 = bVar8;
          DAT_ffffd088 = bVar5;
          DAT_ffffd089 = bVar4;
          return puVar1;
        }
        if ((undefined1 *)(uint)bVar8 != (undefined1 *)0x1) {
          DAT_ffffd07e = bVar3;
          DAT_ffffd085 = bVar7;
          DAT_ffffd086 = bVar6;
          DAT_ffffd087 = bVar8;
          DAT_ffffd088 = bVar5;
          DAT_ffffd089 = bVar4;
          return (undefined1 *)(uint)bVar8;
        }
      }
      uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff869c,0);
      puVar1 = (undefined1 *)ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff869e,uVar2);
      DAT_ffffd07e = bVar3;
      DAT_ffffd085 = bVar7;
      DAT_ffffd086 = bVar6;
      DAT_ffffd087 = bVar8;
      DAT_ffffd088 = bVar5;
      DAT_ffffd089 = bVar4;
      return puVar1;
    }
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff869c,0);
  puVar1 = (undefined1 *)ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff869e,0);
  DAT_ffffd07e = bVar3;
  DAT_ffffd089 = bVar4;
  DAT_ffffd088 = bVar5;
  DAT_ffffd086 = bVar6;
  DAT_ffffd085 = bVar7;
  DAT_ffffd087 = bVar8;
  return puVar1;
}



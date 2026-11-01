/* ROM address: 0x00028240; body bytes: 218; decompiled */

undefined2 *
FUN_00028240(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar2;
  undefined2 *puVar1;
  short sVar3;
  undefined2 *extraout_r0;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  float fVar7;
  
  uVar2 = DAT_ffffb6d0 & 1;
  puVar1 = &DAT_ffffba74;
  if ((((DAT_ffffba74 != 0) && (DAT_ffffba76 == 0)) && (DAT_ffffb960 - 100.0 <= DAT_ffffb5b8)) &&
     (DAT_ffffb5b8 < DAT_ffffb960 + 100.0)) {
    uVar5 = (uint)DAT_ffffb734;
    uVar4 = (uint)DAT_ffffb734;
    if ((&DAT_ffffb964)[(uint)uVar2 * 0x44 + uVar5] == 0) {
      psVar6 = &DAT_ffffb964 + (uint)uVar2 * 0x44 + uVar5;
      puVar1 = (undefined2 *)FUN_00002460((int)*psVar6,1,param_3,param_4,psVar6);
      *psVar6 = (short)puVar1;
      (&DAT_ffffb73c)[(uint)uVar2 * 0x44 + uVar4] = DAT_ffffba94;
    }
    else {
      psVar6 = &DAT_ffffb964 + (uint)uVar2 * 0x44 + uVar5;
      sVar3 = FUN_00002460((int)*psVar6,1,param_3,param_4,psVar6);
      *psVar6 = sVar3;
      fVar7 = rx8_first_order_filter
                        (DAT_ffffba94,(float)(&DAT_ffffb73c)[(uint)uVar2 * 0x44 + uVar4],0.031,1e-05
                        );
      (&DAT_ffffb73c)[(uint)uVar2 * 0x44 + uVar4] = fVar7;
      puVar1 = extraout_r0;
    }
  }
  return puVar1;
}



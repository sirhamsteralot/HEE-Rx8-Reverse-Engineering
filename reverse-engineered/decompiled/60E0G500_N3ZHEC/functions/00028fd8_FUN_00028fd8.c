/* ROM address: 0x00028fd8; body bytes: 96; decompiled */

void FUN_00028fd8(short param_1,ushort param_2,ushort param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = &DAT_ffff8130;
  uVar3 = 0;
  if (param_1 != 0) {
    puVar1 = &DAT_ffff8350;
  }
  uVar2 = FUN_0003eb72(0,puVar1 + (uint)param_2 * 8);
  *param_4 = uVar2;
  uVar3 = FUN_0003eb72(uVar3,puVar1 + (uint)param_3 * 8);
  *param_5 = uVar3;
  return;
}



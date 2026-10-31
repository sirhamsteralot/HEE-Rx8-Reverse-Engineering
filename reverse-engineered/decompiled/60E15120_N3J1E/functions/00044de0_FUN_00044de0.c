/* ROM address: 0x00044de0; body bytes: 114; decompiled */

undefined2 * FUN_00044de0(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(uint)engine_stopped_latch_ffffa41c;
  if (puVar2 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
    uVar1 = ATUII_TSR3_W;
    if ((uVar1 & 0x20) != 0) {
      ATUII_TSR3_W = 0xffdf;
    }
    uVar1 = ATUII_TSR3_W;
    if ((uVar1 & 8) != 0) {
      ATUII_TSR3_W = 0xfff7;
    }
    DAT_ffffcbc3 = 0;
    DAT_ffffcbc4 = 0;
    uVar1 = ATUII_TSR3_W;
    if ((uVar1 & 4) != 0) {
      ATUII_TSR3_W = 0xfffb;
    }
    uVar1 = ATUII_TSR3_W;
    if ((uVar1 & 2) != 0) {
      ATUII_TSR3_W = 0xfffd;
    }
    DAT_ffffcbc5 = 0;
    DAT_ffffcbc6 = 0;
    DAT_ffffcbb5 = 10;
    DAT_ffffcbc8 = leading_ignition_timing_ffffa630;
    puVar2 = &DAT_ffffa0d4;
    DAT_ffffcbcc = DAT_ffffa0d4;
  }
  return puVar2;
}



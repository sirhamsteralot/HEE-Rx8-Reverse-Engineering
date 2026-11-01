/* ROM address: 0x0000c486; body bytes: 674; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000c5c4) */

undefined4 * FUN_0000c486(void)

{
  uint uVar1;
  float fVar2;
  float arg0;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float local_30;
  
  DAT_ffffa370 = (float)(int)((uint)DAT_ffffa378 - (uint)DAT_ffffa326) * 7.6293945e-05;
  fVar6 = 0.0;
  if (DAT_ffffa370 < 0.0) {
    DAT_ffffa370 = 0.0;
  }
  fVar2 = (float)FUN_00002068(&DAT_0006b63c);
  DAT_ffffa330 = fVar2 - (float)((uint)(byte)(&DAT_ffffa381)[DAT_ffffa384] << 5);
  if (DAT_ffffa330 < 0.0) {
    DAT_ffffa330 = fVar6;
  }
  DAT_ffffa32c = rx8_first_order_filter(DAT_ffffa330 - DAT_ffffa348,DAT_ffffa32c,0.0625,fVar6);
  DAT_ffffa38b = (&DAT_ffffa387)[DAT_ffffa384] != (&DAT_ffffa389)[DAT_ffffa384];
  if ((bool)DAT_ffffa38b) {
    DAT_ffffa32c = 40.0;
  }
  (&DAT_ffffa389)[DAT_ffffa384] = (&DAT_ffffa387)[DAT_ffffa384];
  fVar2 = DAT_ffffa330 - (float)(&DAT_ffffa334)[DAT_ffffa384];
  if (fVar2 < 0.0) {
    fVar2 = -fVar2;
  }
  fVar3 = DAT_ffffa32c;
  if (DAT_ffffa32c < 0.0) {
    fVar3 = -DAT_ffffa32c;
  }
  DAT_ffffa344 = DAT_ffffc0cc * fVar2;
  if (fVar3 < DAT_ffffc0cc * fVar2) {
    DAT_ffffa344 = fVar3;
  }
  if (DAT_ffffa344 < 1.0) {
    DAT_ffffa344 = 1.0;
  }
  local_30 = *(float *)(&DAT_ffffa33c + (uint)DAT_ffffa384 * 4);
  if (DAT_ffffa330 <= (float)(&DAT_ffffa334)[DAT_ffffa384]) {
    if (DAT_ffffa330 < (float)(&DAT_ffffa334)[DAT_ffffa384]) {
      local_30 = local_30 - DAT_ffffa344;
    }
  }
  else {
    local_30 = local_30 + DAT_ffffa344;
  }
  *(float *)(&DAT_ffffa33c + (uint)DAT_ffffa384 * 4) = local_30;
  uVar4 = DAT_ffff9f80;
  DAT_ffffa358 = (float)FUN_00002068(DAT_ffff9f80,&PTR_DAT_0006b674);
  fVar3 = DAT_ffffa358 + 8.0;
  fVar2 = (float)FUN_00002068(uVar4,&PTR_DAT_0006b668);
  fVar5 = 2.0;
  if ((DAT_ffffa330 <= (float)(&DAT_ffffa334)[DAT_ffffa384] - (float)(&DAT_ffffa350)[DAT_ffffa384])
     || ((float)(&DAT_ffffa334)[DAT_ffffa384] < DAT_ffffa330)) {
    arg0 = (float)(&DAT_ffffa350)[DAT_ffffa384] + DAT_ffffa344 * DAT_ffffc0d0;
  }
  else {
    arg0 = (float)(&DAT_ffffa350)[DAT_ffffa384] - DAT_ffffa344 * DAT_ffffc0d0 * 2.0;
  }
  uVar1 = (uint)DAT_ffffa384;
  fVar2 = rx8_clamp_float(arg0,fVar2,fVar3);
  (&DAT_ffffa350)[uVar1] = fVar2;
  DAT_ffffa348 = rx8_first_order_filter(DAT_ffffa330,DAT_ffffa348,DAT_ffffc0d4,fVar6);
  DAT_ffffa34c = *(float *)(&DAT_ffffa33c + (uint)DAT_ffffa384 * 4) + DAT_ffffa348;
  if (*(float *)(&DAT_ffffa33c + (uint)DAT_ffffa384 * 4) + DAT_ffffa348 < 0.0) {
    DAT_ffffa34c = fVar6;
  }
  (&DAT_ffffa334)[DAT_ffffa384] = DAT_ffffa34c;
  DAT_ffffa35c = fVar6;
  if (0.0 <= (float)(&DAT_ffffa350)[DAT_ffffa384] - DAT_ffffa358) {
    DAT_ffffa35c = ((float)(&DAT_ffffa350)[DAT_ffffa384] - DAT_ffffa358) * fVar5;
  }
  DAT_ffffa360 = (float)(&DAT_ffffa350)[DAT_ffffa384] - DAT_ffffa35c;
  if ((float)(&DAT_ffffa350)[DAT_ffffa384] - DAT_ffffa35c < 0.0) {
    DAT_ffffa360 = fVar6;
  }
  DAT_ffffa364 = 64.0;
  fVar6 = DAT_ffffa34c + DAT_ffffa328 * DAT_ffffa360;
  if ((64.0 <= fVar6) && (DAT_ffffa364 = fVar6, 255.0 < fVar6)) {
    DAT_ffffa364 = 255.0;
  }
  (&DAT_ffffa368)[DAT_ffffa384] = DAT_ffffa364 + DAT_ffffa360 * fVar5;
  DAT_ffffa324 = DAT_ffffa364 <= DAT_ffffa330;
  return &DAT_ffffa368;
}



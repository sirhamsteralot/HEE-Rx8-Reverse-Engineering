/* ROM address: 0x0001702c; body bytes: 376; decompiled */

uint FUN_0001702c(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar5;
  uint uVar4;
  undefined4 local_3c;
  char cStack_38;
  char cStack_34;
  char cStack_30;
  char cStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_24;
  
  cVar3 = DAT_ffffa8ec;
  bVar2 = false;
  bVar1 = false;
  cStack_34 = engine_running_flag_ffffaa68;
  cStack_30 = DAT_ffffa8f7;
  uStack_24 = 0;
  uStack_28 = 0;
  cStack_38 = DAT_ffffa8ec;
  cStack_2c = DAT_ffffa8ea;
  if ((engine_running_ffffa428 == '\0') && (engine_running_flag_ffffaa68 == '\x01')) {
    uStack_24 = 1;
    DAT_ffffa8f8 = '\0';
  }
  else if ((engine_running_ffffa428 == '\x01') && ((DAT_ffffa8f8 == '\0' && (DAT_ffffa914 == '\0')))) {
    uStack_28 = 1;
  }
  else {
    bVar1 = DAT_ffffa8f8 == '\x01';
    if ((engine_running_flag_ffffaa68 == '\0') &&
       (((bVar1 && (DAT_ffffa914 == '\0')) &&
        (cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8054,0), cVar5 == '\0')))) {
      bVar2 = true;
    }
    DAT_ffffa8ec = cVar3;
    if (((!bVar2) && (cStack_30 == '\0')) && (DAT_ffffa8f0 == '\x01')) {
      DAT_ffffa8ec = '\x01';
    }
    if ((cStack_38 == '\0') && (DAT_ffffa8ec == '\x01')) {
      DAT_ffffa8ee = 0;
    }
  }
  DAT_ffffa8eb = uStack_24;
  DAT_ffffa8e8 = uStack_28;
  if (inferred_coolant_temperature_ffffa98c < -40.0) {
    if (499 < DAT_ffffa8ee) {
      DAT_ffffa8ec = '\0';
    }
  }
  else if (0x137 < DAT_ffffa8ee) {
    DAT_ffffa8ec = '\0';
  }
  DAT_ffffa8e9 = bVar1;
  DAT_ffffa8ea = bVar2;
  DAT_ffffa8ee = rx8_add_u16_saturate((int)(short)DAT_ffffa8ee,1);
  DAT_ffffa8f0 = cStack_30;
  uVar4 = 0x10;
  if ((cStack_2c == '\0') && (uVar4 = (uint)DAT_ffffa8ea, uVar4 == 1)) {
    local_3c = 0;
    uVar4 = os_schedule_task_event(0,2,&local_3c);
  }
  return uVar4;
}



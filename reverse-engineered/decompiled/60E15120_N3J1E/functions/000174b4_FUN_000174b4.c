/* ROM address: 0x000174b4; body bytes: 670; decompiled */

void FUN_000174b4(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  char acStack_44 [40];
  
  sh_copy_bytes_forward_r0_r1_r2();
  uVar2 = param_1 & 0xff;
  DAT_ffffa90a = (undefined1)param_1;
  if (uVar2 == 0) {
    bVar1 = DAT_ffffa8fb + 1;
    DAT_ffffa8fb = bVar1 & 7;
    if (((bVar1 & 1) == 0) && (inferred_ram_a8f4_ffffa8f4_ffffa8f4 < 0x3c)) {
      DAT_ffffa8fe = inferred_ram_a8f4_ffffa8f4_ffffa8f4 + 1;
    }
  }
  else if (uVar2 == 1) {
    if (DAT_ffffa8fb == 8) {
      DAT_ffffa8fb = DAT_ffffa8fc - 1 & 7;
    }
    else {
      DAT_ffffa8fb = DAT_ffffa8fb - 1 & 7;
      if (((inferred_ram_a8f4_ffffa8f4_ffffa8f4 == 1) && (DAT_ffffa907 != '\x04')) &&
         ((DAT_ffffa8e9 == '\x01' || (DAT_ffffa8ea == '\x01')))) {
        DAT_ffffa8fe = '\0';
      }
    }
    if ((((DAT_ffffa8fb & 1) == 0) && (DAT_ffffa907 != '\x04')) && (inferred_ram_a8f4_ffffa8f4_ffffa8f4 != 0)) {
      DAT_ffffa8fe = inferred_ram_a8f4_ffffa8f4_ffffa8f4 - 1;
    }
  }
  else if (uVar2 == 2) {
    if ((DAT_ffffa907 == '\x04') || ((DAT_ffffa8fb & 1) == 1)) {
      if (DAT_ffffa8fb == 8) {
        DAT_ffffa8fb = DAT_ffffa8fc;
      }
      bVar1 = DAT_ffffa8fb + 1;
    }
    else {
      bVar1 = DAT_ffffa8fb + 2;
    }
    DAT_ffffa8fb = bVar1 & 7;
    if (inferred_ram_a8f4_ffffa8f4_ffffa8f4 < 0x3c) {
      DAT_ffffa8fe = inferred_ram_a8f4_ffffa8f4_ffffa8f4 + 1;
    }
  }
  else if (uVar2 == 3) {
    if ((DAT_ffffa907 == '\x04') || ((DAT_ffffa8fb & 1) == 1)) {
      if (DAT_ffffa8fb == 8) {
        DAT_ffffa8fb = DAT_ffffa8fc - 1 & 7;
      }
      else {
        DAT_ffffa8fb = DAT_ffffa8fb - 1 & 7;
        if ((inferred_ram_a8f4_ffffa8f4_ffffa8f4 == 1) && (DAT_ffffa907 != '\x04')) {
          DAT_ffffa8fe = '\0';
        }
      }
    }
    else {
      DAT_ffffa8fb = DAT_ffffa8fb - 2 & 7;
      if (inferred_ram_a8f4_ffffa8f4_ffffa8f4 != 0) {
        DAT_ffffa8fe = inferred_ram_a8f4_ffffa8f4_ffffa8f4 - 1;
      }
    }
  }
  else if (uVar2 == 4) {
    if (DAT_ffffa8fb == 8) {
      DAT_ffffa8fb = DAT_ffffa8fc;
    }
    else if ((DAT_ffffa8fb & 1) == 0) {
      DAT_ffffa8fb = DAT_ffffa8fb + 1 & 7;
      DAT_ffffa8fc = DAT_ffffa8fb;
    }
    else {
      DAT_ffffa8fb = 8;
    }
  }
  else if (uVar2 == 6) {
    DAT_ffffa8fb = 8;
  }
  DAT_ffffa907 = DAT_ffffa90a;
  ref_setSR_PARAM(&uStack_48,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,1,acStack_44[(uint)DAT_ffffa8fb * 4] == '\x01');
  FUN_00002064(uStack_48);
  ref_setSR_PARAM(&uStack_4c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,2,acStack_44[(uint)DAT_ffffa8fb * 4 + 1] == '\x01');
  FUN_00002064(uStack_4c);
  ref_setSR_PARAM(&uStack_50,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,4,acStack_44[(uint)DAT_ffffa8fb * 4 + 2] == '\x01');
  FUN_00002064(uStack_50);
  ref_setSR_PARAM(&local_54,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,8,acStack_44[(uint)DAT_ffffa8fb * 4 + 3] == '\x01');
  FUN_00002064(local_54);
  return;
}



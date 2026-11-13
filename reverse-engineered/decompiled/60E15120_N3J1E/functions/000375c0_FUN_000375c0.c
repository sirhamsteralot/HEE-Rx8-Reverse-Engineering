/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_immo_key_read [high]: Reads device words 0x6010000-0x6040000 (chip 0x02-0x09, 8-byte immo key), 0x60b0000/0x60c0000 (0x16-0x19 immo code), 0x6050000 (0x0a-0x0b status) via e2ram_read_word 0xbdfa under mask 0x10 with 0xbed8 busy checks; all-0x00/all-0xff patterns -> erased flags 0xffffc1d5-0xffffc1d8; gated by ref_securityNotUnlocked(1) and DAT_ffffd1ce. Called from 0x34a04 (boot, near ref_ImmoSomethingOrOther__ 0x349e4).
 */
/* ROM address: 0x000375c0; body bytes: 684; decompiled */

undefined1 * e2ram_immo_key_read(void)

{
  char extraout_var;
  char cVar4;
  undefined4 uVar1;
  ushort uVar3;
  undefined1 *puVar2;
  undefined1 *unaff_r14;
  undefined2 *puStack_44;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 uStack_2c;
  char cStack_2b;
  char cStack_2a;
  char cStack_29;
  char cStack_28;
  char cStack_27;
  char cStack_26;
  char cStack_25;
  char cStack_24;
  
  if ((DAT_ffffd1ce == '\x01') && (cVar4 = ref_securityNotUnlocked(1), cVar4 == '\0')) {
    if (DAT_ffffc283 == '\0') {
      DAT_ffffc284 = '\0';
      inferred_ram_c1d5_ffffc1d5_ffffc1d5 = 0;
      DAT_ffffc285 = '\0';
      inferred_ram_c1d6_ffffc1d6_ffffc1d6 = 0;
      inferred_ram_c1d7_ffffc1d7_ffffc1d7 = 0;
      inferred_ram_c1d8_ffffc1d8_ffffc1d8 = 0;
      DAT_ffffc286 = '\0';
    }
    else {
      if (DAT_ffffc284 == '\0') {
        uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
        unaff_r14 = &uStack_2c;
        cVar4 = e2ram_busy_status_read();
        if (cVar4 == '\0') {
          puStack_44 = &local_34;
          local_34 = e2ram_read_word(0x6010000);
          local_32 = e2ram_read_word(0x6020000);
          local_30 = e2ram_read_word(0x6030000);
          local_2e = e2ram_read_word(0x6040000);
          cStack_2b = (char)((ushort)local_34 >> 8);
          cStack_2a = (char)local_34;
          cStack_29 = (char)((ushort)local_32 >> 8);
          cStack_28 = (char)local_32;
          cStack_27 = (char)((ushort)local_30 >> 8);
          cStack_26 = (char)local_30;
          cStack_25 = (char)((ushort)local_2e >> 8);
          cStack_24 = (char)local_2e;
          DAT_ffffc284 = '\x01';
        }
        ref_setSR(uVar1);
        if (DAT_ffffc284 == '\x01') {
          if ((((((cStack_2b == '\0') && (cStack_2a == '\0')) && (cStack_29 == '\0')) &&
               ((cStack_28 == '\0' && (cStack_27 == '\0')))) &&
              ((cStack_26 == '\0' && ((cStack_25 == '\0' && (cStack_24 == '\0')))))) ||
             ((cStack_2b == -1 &&
              ((((cStack_2a == -1 && (cStack_29 == -1)) && (cStack_28 == -1)) &&
               (((cStack_27 == -1 && (cStack_26 == -1)) && ((cStack_25 == -1 && (cStack_24 == -1))))
               )))))) {
            inferred_ram_c1d5_ffffc1d5_ffffc1d5 = 0;
          }
          else {
            inferred_ram_c1d5_ffffc1d5_ffffc1d5 = 1;
          }
        }
      }
      if (DAT_ffffc285 == '\0') {
        uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
        cVar4 = e2ram_busy_status_read();
        if (cVar4 == '\0') {
          unaff_r14 = (undefined1 *)e2ram_read_word(0x60b0000);
          uVar3 = e2ram_read_word(0x60c0000);
          puStack_44 = (undefined2 *)((uint)uVar3 << 0x10);
          DAT_ffffc285 = '\x01';
        }
        ref_setSR(uVar1);
        if (DAT_ffffc285 == '\x01') {
          if (((puStack_44._0_2_ == -1) && (((uint)unaff_r14 & 0xffff) == 0xffff)) ||
             (((uint)unaff_r14 & 0xffff) == 0)) {
            inferred_ram_c1d6_ffffc1d6_ffffc1d6 = 0;
          }
          else {
            inferred_ram_c1d6_ffffc1d6_ffffc1d6 = 1;
          }
        }
      }
      if (DAT_ffffc286 == '\0') {
        uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
        cVar4 = e2ram_busy_status_read();
        if (cVar4 == '\0') {
          e2ram_read_word(0x6050000);
          DAT_ffffc286 = '\x01';
          puStack_44._0_1_ = extraout_var;
        }
        ref_setSR(uVar1);
        if (DAT_ffffc286 == '\x01') {
          if (puStack_44._0_1_ == '\0') {
            inferred_ram_c1d7_ffffc1d7_ffffc1d7 = 0;
            inferred_ram_c1d8_ffffc1d8_ffffc1d8 = 0;
          }
          else if (puStack_44._0_1_ == '\x01') {
            inferred_ram_c1d7_ffffc1d7_ffffc1d7 = 1;
            inferred_ram_c1d8_ffffc1d8_ffffc1d8 = 0;
          }
          else {
            inferred_ram_c1d7_ffffc1d7_ffffc1d7 = 1;
            inferred_ram_c1d8_ffffc1d8_ffffc1d8 = 1;
          }
        }
      }
    }
  }
  if (DAT_ffffd1ce != '\x01') {
    puVar2 = &DAT_ffffc283;
  }
  else {
    puVar2 = (undefined1 *)((int)&vector_Poweron_Reset + 1);
  }
  DAT_ffffc283 = DAT_ffffd1ce == '\x01';
  return puVar2;
}



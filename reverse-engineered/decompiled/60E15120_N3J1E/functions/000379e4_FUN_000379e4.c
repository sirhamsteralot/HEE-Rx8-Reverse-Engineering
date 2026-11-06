/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_verify_state_machine [medium]: State machine over 0xffffc49c (states 1-4): busy-check 0xbed8, issue command 0x4c00000 via 0xbe30 (pools 0x37bd4/0x37bd8), then read-back verify with 0xbdfa(0x6000000 + (byte)0xffffc498*0x10000) (pools 0x37be8/0x37bec) comparing against 0xffffc49a; status cells 0xffffc4a0-a6. Called from 0x38082.
 */
/* ROM address: 0x000379e4; body bytes: 626; decompiled */

void candidate_e2ram_verify_state_machine(void)

{
  undefined4 uVar1;
  char cVar3;
  ushort uVar2;
  int iVar4;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((((DAT_ffffc49c != '\x01') && (DAT_ffffc49c != '\x02')) && (DAT_ffffc49c != '\x03')) &&
     (DAT_ffffc49c != '\x04')) goto LAB_00037c9a;
  cVar3 = e2ram_busy_status_read();
  if (cVar3 == '\0') {
    DAT_ffffc4a0 = 0;
    if (DAT_ffffc4a2 == '\0') {
      e2ram_send_command2(0x4c00000);
      DAT_ffffc4a2 = '\x01';
    }
    else if (DAT_ffffc4a3 == '\0') {
      if (DAT_ffffc4a4 == '\x01') {
        DAT_ffffc4a4 = '\0';
      }
      else {
        uVar2 = e2ram_read_word((uint)(byte)DAT_ffffc498 * 0x10000 + 0x6000000);
        if (uVar2 != DAT_ffffc49a) {
          if (DAT_ffffc4a5 != '\x01') {
            DAT_ffffc4a5 = '\x01';
            goto LAB_00037aa4;
          }
          DAT_ffffc4a6 = '\x01';
        }
        DAT_ffffc4a5 = '\0';
      }
LAB_00037aa4:
      if (DAT_ffffc4a5 == '\0') {
        if (DAT_ffffc4a6 == '\0') {
          DAT_ffffc498 = (ushort)DAT_ffffc49f * 0x80 + DAT_ffffc48e;
          iVar4 = ((int)(short)DAT_ffffc48e & 0x7fffU) * 2;
          DAT_ffffc49a = (ushort)(byte)(&e2ram_shadow_data_ffffc28e)[iVar4] * 0x100 +
                         (ushort)(byte)(&DAT_ffffc28f)[iVar4];
          uVar2 = e2ram_read_word((uint)(byte)DAT_ffffc498 * 0x10000 + 0x6000000);
          if (uVar2 != DAT_ffffc49a) {
            candidate_e2ram_send_command4_a((uint)(byte)DAT_ffffc498 * 0x10000 + (uint)DAT_ffffc49a + 0x5000000);
          }
          if (DAT_ffffc49f == 0xff) {
            DAT_ffffc49f = 0;
          }
          else {
            DAT_ffffc49f = 0;
            DAT_ffffc48e = DAT_ffffc48e + 1;
            if (DAT_ffffc490 < DAT_ffffc48e) {
              DAT_ffffc4a3 = '\x01';
            }
          }
        }
        else {
          DAT_ffffc4a1 = 0;
          e2ram_send_command2(0x4000000);
          DAT_ffffc4a3 = '\0';
          DAT_ffffc4a2 = '\0';
        }
      }
    }
    else {
      uVar2 = e2ram_read_word((uint)(byte)DAT_ffffc498 * 0x10000 + 0x6000000);
      if (uVar2 == DAT_ffffc49a) {
LAB_00037b88:
        DAT_ffffc4a5 = '\0';
      }
      else {
        if (DAT_ffffc4a5 == '\x01') {
          DAT_ffffc4a6 = '\x01';
          goto LAB_00037b88;
        }
        DAT_ffffc4a5 = '\x01';
      }
      if (DAT_ffffc4a5 == '\0') {
        if (DAT_ffffc4a6 == '\0') {
          if (DAT_ffffc49c == '\x01') {
            DAT_ffffc288 = 1;
          }
          else if (DAT_ffffc49c == '\x02') {
            DAT_ffffc289 = 1;
          }
          else if (DAT_ffffc49c == '\x03') {
            DAT_ffffc28a = 1;
          }
          DAT_ffffc49c = '\0';
        }
        DAT_ffffc4a1 = 0;
        e2ram_send_command2(0x4000000);
        DAT_ffffc4a3 = '\0';
        DAT_ffffc4a2 = '\0';
      }
    }
  }
  else if ((DAT_ffffc4a0 != 0xff) && (DAT_ffffc4a0 = DAT_ffffc4a0 + 1, 5 < DAT_ffffc4a0)) {
    DAT_ffffc4a6 = '\x01';
    DAT_ffffc4a1 = 0;
    DAT_ffffc4a3 = '\0';
    DAT_ffffc4a2 = '\0';
  }
  if (DAT_ffffc4a6 == '\x01') {
    if (DAT_ffffc49c == '\x01') {
      DAT_ffffc28b = 1;
    }
    else if (DAT_ffffc49c == '\x02') {
      DAT_ffffc28c = 1;
    }
    else if (DAT_ffffc49c == '\x03') {
      DAT_ffffc28d = 1;
    }
    DAT_ffffc49c = '\0';
  }
LAB_00037c9a:
  ref_setSR(uVar1);
  return;
}



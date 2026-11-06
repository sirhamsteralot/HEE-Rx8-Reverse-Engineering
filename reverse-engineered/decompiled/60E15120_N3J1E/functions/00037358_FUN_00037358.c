/* [ADDITIONAL SOURCE REVIEW]
 * dtc_state_machine_step [medium]: DTC/immo state machine over DAT_ffffc239-c281; sets DAT_ffffd1e8 response code; reached via thunk 0x576c2 (PID 0xc116)
 */
/* ROM address: 0x00037358; body bytes: 278; decompiled */

/* Function candidate recovered from ROM pointer at 57700 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_dtc_state_machine_step(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_ffffc25f == '\0') {
    if ((DAT_ffffc239 == '\0') && (DAT_ffffc247 == '\0')) {
      if (((DAT_ffffc27c == 0) || (DAT_ffffc27a == 0)) ||
         ((DAT_ffffc27c == -1 && (DAT_ffffc27a == -1)))) {
        DAT_ffffc27e = '\0';
      }
      else {
        if (DAT_ffffc276 == '\0') {
          FUN_000368aa();
          DAT_ffffc276 = '\x05';
          DAT_ffffc242 = 1;
          DAT_ffffc278 = 0;
        }
        DAT_ffffc27e = '\x01';
        if (inferred_ram_c1d2_ffffc1d2_ffffc1d2 == '3') {
          DAT_ffffc260 = 1;
        }
      }
      DAT_ffffc25f = '\x01';
      DAT_ffffd1e8 = 0x80;
    }
    else {
      DAT_ffffd1e8 = 0xff;
    }
  }
  else if (DAT_ffffc25e == '\0') {
    DAT_ffffc25e = '\x01';
    DAT_ffffc25b = 1;
  }
  else if (DAT_ffffc25d == '\x01') {
    diag_append_u8(param_1,(int)DAT_ffffc27e);
    if (DAT_ffffc27e == '\x01') {
      diag_append_u8(param_1,(int)DAT_ffffc27f);
      diag_append_u8(param_1,(int)DAT_ffffc280);
      iVar1 = (int)DAT_ffffc281;
    }
    else {
      diag_append_u8(param_1,0);
      diag_append_u8(param_1,0);
      iVar1 = 0;
    }
    diag_append_u8(param_1,iVar1);
    DAT_ffffd1e8 = 0;
    DAT_ffffc25f = '\0';
    DAT_ffffc25e = '\0';
    DAT_ffffc25d = '\0';
  }
  return;
}



/* ROM address: 0x0003b854; body bytes: 178; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003bc88 (178 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003b854(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((((DAT_ffffd1c5 == '\x01') || (uVar1 = 1, DAT_ffffd1ad == '\x01')) ||
      (uVar1 = 1, DAT_ffffc5b1 == '\x01')) || (uVar1 = (uint)DAT_ffffc5bd, uVar1 == 1)) {
    DAT_ffffc5a4 = '\x1b';
    DAT_ffffc5a5 = '\x06';
  }
  else if (200.0 < DAT_ffffc5a0 - DAT_ffffc59c) {
    if ((0.0 < vehicle_speed_ffffbbb4) || (uVar1 = (uint)(short)engine_running_timer_ffffa424, uVar1 < 0x321)) {
      DAT_ffffc5a4 = '\x1b';
    }
    else if (DAT_ffffc5a4 != '\0') {
      DAT_ffffc5a4 = DAT_ffffc5a4 + -1;
    }
    DAT_ffffc5a5 = '\x06';
  }
  else {
    DAT_ffffc5a4 = '\x1b';
    if (engine_running_timer_ffffa424 < 0x321) {
      uVar1 = 6;
      DAT_ffffc5a5 = '\x06';
    }
    else {
      uVar1 = 0;
      if (DAT_ffffc5a5 != '\0') {
        uVar1 = 0xff;
        DAT_ffffc5a5 = DAT_ffffc5a5 + -1;
      }
    }
  }
  return uVar1;
}



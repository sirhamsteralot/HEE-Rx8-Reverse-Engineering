/* ROM address: 0x00053cca; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051dde (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00053cca(void)

{
  undefined4 uVar1;
  
  if (engine_running_ffffa428 == '\x01') {
    DAT_ffffd1a0 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = rx8_add_u8_saturate((int)DAT_ffffd1a0,1);
    DAT_ffffd1a0 = (char)uVar1;
  }
  return uVar1;
}



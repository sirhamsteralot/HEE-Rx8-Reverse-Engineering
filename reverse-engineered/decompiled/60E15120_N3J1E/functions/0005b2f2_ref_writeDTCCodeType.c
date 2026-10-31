/* ROM address: 0x0005b2f2; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059ae2 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_writeDTCCodeType(char param_1)

{
  undefined1 local_c;
  undefined1 uStack_b;
  
  if (param_1 == '\x02') {
    ref_udsServiceResponse(0x12,&local_c,2);
    DAT_ffffd2e6 = CONCAT11(local_c,uStack_b);
    DAT_ffffd2e4 = 2;
  }
  else {
    ref_dtcCodeTypeInit();
  }
  return;
}



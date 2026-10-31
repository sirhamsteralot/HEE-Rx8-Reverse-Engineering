/* ROM address: 0x00010d5e; body bytes: 146; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00010d82 (146 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setEngineCycle_(void)

{
  int iVar1;
  char unaff_r10;
  int unaff_r11;
  code *unaff_r12;
  undefined1 unaff_r13;
  char *unaff_r14;
  float in_fr15;
  
  do {
    if (unaff_r14[4] == '\0') {
      *(undefined4 *)(unaff_r14 + 8) = *(undefined4 *)(unaff_r14 + 0xc);
      if (unaff_r14[3] == '\x01') {
        iVar1 = (*unaff_r12)();
        ref_outputSpark2((float)iVar1 / in_fr15,(int)*unaff_r14);
      }
      else if (unaff_r14[3] == '\0') {
        iVar1 = (*unaff_r12)();
        ref_outputSpark1((float)iVar1 / in_fr15,(int)*unaff_r14);
        unaff_r14[3] = unaff_r10;
      }
    }
    unaff_r14 = unaff_r14 + 0x10;
  } while (unaff_r14 < (char *)(unaff_r11 + 0x2c));
  *(char *)(unaff_r11 + 1) = unaff_r10;
  *(undefined1 *)(unaff_r11 + 2) = unaff_r13;
  return;
}



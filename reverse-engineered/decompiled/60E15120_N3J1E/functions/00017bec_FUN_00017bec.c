/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00017bec; body bytes: 242; decompiled */

uint FUN_00017bec(void)

{
  byte snapshot_DAT_ffffa8f4;
  byte bVar3;
  uint uVar2;
  byte bVar4;
  char cVar5;
  
  snapshot_DAT_ffffa8f4 = DAT_ffffa8f4;
  bVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8052,0x37);
  cVar5 = '\0';
  bVar4 = 0;
  if (DAT_ffffa8e9 == '\x01') {
    if (DAT_ffffa8f5 == '\0') {
      bVar3 = rx8_add_u8_saturate();
      if (bVar3 < snapshot_DAT_ffffa8f4) {
        cVar5 = '\x01';
      }
    }
    else {
      if (bVar3 < 2) {
        bVar3 = 0;
      }
      else {
        bVar3 = bVar3 - 1;
      }
      if (snapshot_DAT_ffffa8f4 < bVar3) {
        bVar4 = 1;
      }
    }
  }
  if ((cVar5 == '\x01') && (0x3d < DAT_ffffa910)) {
    DAT_ffffa90c = 1;
  }
  if ((bVar4 == 1) && (0x7c < DAT_ffffa911)) {
    DAT_ffffa90d = 1;
  }
  DAT_ffffa90e = cVar5;
  DAT_ffffa90f = bVar4;
  if (cVar5 == '\x01') {
    DAT_ffffa910 = rx8_add_u8_saturate((int)(char)DAT_ffffa910,1);
  }
  else {
    DAT_ffffa910 = 0;
  }
  uVar2 = (uint)DAT_ffffa90f;
  if (uVar2 == 1) {
    uVar2 = rx8_add_u8_saturate((int)(char)DAT_ffffa911,1);
    DAT_ffffa911 = (byte)uVar2;
  }
  else {
    DAT_ffffa911 = 0;
  }
  return uVar2;
}



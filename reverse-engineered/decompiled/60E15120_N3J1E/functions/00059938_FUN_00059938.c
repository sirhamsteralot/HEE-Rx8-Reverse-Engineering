/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00059938; body bytes: 250; decompiled */

uint FUN_00059938(void)

{
  byte snapshot_DAT_ffffd251;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  snapshot_DAT_ffffd251 = DAT_ffffd251;
  uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((((DAT_ffffd25e == '\0') || (DAT_ffffd25c == '\0')) || (DAT_ffffd257 == '\x01')) ||
     (DAT_ffffd251 == 0x30)) {
    DAT_ffffd251 = 0;
  }
  else if ((DAT_ffffd251 == 0) && (DAT_ffffd254 == '\x01')) {
    DAT_ffffd251 = 0x10;
  }
  else if ((DAT_ffffd251 == 0x10) && (0x5d < DAT_ffffd248)) {
    DAT_ffffd251 = 0x20;
  }
  else if ((DAT_ffffd251 == 0x20) && (0x5d < DAT_ffffd248)) {
    DAT_ffffd251 = 0x30;
  }
  if (DAT_ffffd251 == 0) {
    DAT_ffffd261 = 0;
  }
  DAT_ffffd254 = 0;
  DAT_ffffd257 = 0;
  uVar3 = ref_setSR(uVar2);
  uVar4 = (uint)DAT_ffffd251;
  if (((uVar4 == 0) || ((snapshot_DAT_ffffd251 == 0 && (uVar3 = uVar4, uVar4 == 0x10)))) ||
     ((uVar3 = (uint)snapshot_DAT_ffffd251, snapshot_DAT_ffffd251 == 0x10 && (uVar3 = uVar4, uVar4 == 0x20)))) {
    DAT_ffffd248 = 0;
  }
  else if (DAT_ffffd248 != 0xffff) {
    DAT_ffffd248 = DAT_ffffd248 + 1;
  }
  return uVar3;
}



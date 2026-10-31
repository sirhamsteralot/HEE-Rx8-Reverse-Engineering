/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00059af4; body bytes: 554; decompiled */

uint FUN_00059af4(void)

{
  byte snapshot_DAT_ffffd252;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  snapshot_DAT_ffffd252 = DAT_ffffd252;
  uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((((DAT_ffffd25f == '\0') || (DAT_ffffd25c == '\0')) || (DAT_ffffd258 == '\x01')) ||
     ((DAT_ffffd252 == 0x80 || (0xafc < DAT_ffffd24a)))) {
    DAT_ffffd252 = 0;
  }
  else if ((DAT_ffffd252 == 0) && (DAT_ffffd255 == '\x01')) {
    DAT_ffffd252 = 0x10;
  }
  else if ((DAT_ffffd252 != 0x10) || (engine_speed_rpm_ffffb548 <= 900.0)) {
    if ((DAT_ffffd252 == 0x20) && ((DAT_ffffd265 == '\0' || (DAT_ffffcf87 == '\x01')))) {
      DAT_ffffd252 = 0x30;
    }
    else if ((DAT_ffffd252 == 0x30) && (1 < DAT_ffffd24c)) {
      DAT_ffffd252 = 0x40;
    }
    else if ((DAT_ffffd252 == 0x40) && (0x1d5 < DAT_ffffd24c)) {
      DAT_ffffd252 = 0x50;
    }
    else if ((DAT_ffffd252 == 0x50) && (1 < DAT_ffffd24c)) {
      DAT_ffffd252 = 0x60;
    }
    else if ((DAT_ffffd252 == 0x60) && (0xdb < DAT_ffffd24c)) {
      DAT_ffffd252 = 0x70;
    }
    else if (((DAT_ffffd252 == 0x70) && (1 < DAT_ffffd24c)) ||
            ((DAT_ffffd252 == 0x10 && (0x5d < DAT_ffffd24c)))) {
      DAT_ffffd252 = 0x80;
    }
  }
  else {
    DAT_ffffd252 = 0x20;
  }
  if (DAT_ffffd252 == 0) {
    DAT_ffffd266 = 0;
  }
  DAT_ffffd255 = 0;
  DAT_ffffd258 = 0;
  uVar3 = ref_setSR(uVar2);
  uVar4 = (uint)DAT_ffffd252;
  if ((((((uVar4 == 0) || ((uVar3 = uVar4, snapshot_DAT_ffffd252 == 0 && (uVar4 == 0x10)))) ||
        ((snapshot_DAT_ffffd252 == 0x10 && (uVar4 == 0x20)))) ||
       (((snapshot_DAT_ffffd252 == 0x20 && (uVar4 == 0x30)) || ((snapshot_DAT_ffffd252 == 0x30 && (uVar4 == 0x40)))))) ||
      (((snapshot_DAT_ffffd252 == 0x40 && (uVar4 == 0x50)) || ((snapshot_DAT_ffffd252 == 0x50 && (uVar4 == 0x60)))))) ||
     ((uVar3 = (uint)snapshot_DAT_ffffd252, snapshot_DAT_ffffd252 == 0x60 && (uVar3 = uVar4, uVar4 == 0x70)))) {
    DAT_ffffd24c = 0;
  }
  else if (DAT_ffffd24c != 0xffff) {
    DAT_ffffd24c = DAT_ffffd24c + 1;
  }
  if (DAT_ffffd252 == 0) {
    DAT_ffffd24a = 0;
  }
  else if (DAT_ffffd24a != 0xffff) {
    DAT_ffffd24a = DAT_ffffd24a + 1;
  }
  return uVar3;
}



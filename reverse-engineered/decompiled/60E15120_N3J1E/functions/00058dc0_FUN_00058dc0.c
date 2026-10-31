/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00058dc0; body bytes: 150; decompiled */

uint FUN_00058dc0(void)

{
  char cVar1;
  char cVar2;
  byte snapshot_DAT_ffffd23e;
  byte snapshot_DAT_ffffd23f;
  uint uVar5;
  
  snapshot_DAT_ffffd23f = DAT_ffffd23f;
  snapshot_DAT_ffffd23e = DAT_ffffd23e;
  cVar2 = DAT_ffffd23d;
  cVar1 = DAT_ffffd23c;
  FUN_00058d9e();
  if (DAT_ffffd1c5 == '\x01') {
    FUN_00058e9c();
    uVar5 = FUN_00058f30();
    return uVar5;
  }
  if (((cVar1 == '\0') && (DAT_ffffd23c == '\x01')) || ((cVar2 == '\0' && (DAT_ffffd23d == '\x01')))
     ) {
    FUN_00058ea2();
  }
  uVar5 = (uint)(char)snapshot_DAT_ffffd23e;
  if (((uVar5 != 0) || (uVar5 = (uint)DAT_ffffd23e, uVar5 != 1)) &&
     ((snapshot_DAT_ffffd23f != 0 || (uVar5 = (uint)DAT_ffffd23f, uVar5 != 1)))) {
    return uVar5;
  }
  uVar5 = FUN_00058f70();
  return uVar5;
}



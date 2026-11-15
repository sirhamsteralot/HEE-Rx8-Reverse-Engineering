/* [ADDITIONAL SOURCE REVIEW]
 * diag22_subpid_supported_mask [high]: scans 36 x 6-byte records at 0x5f5b2 for current PID+subfunc with mask&DAT_ffffd3b4, ORs byte1 (bit) into result; returns param & mask
 * RAM 0xffffd3b4 diag_permission_mask_ffffd3b4 (uint16): session/security mask ANDed with every record availability_mask in 0x5774c and 0x579a8
 */
/* ROM address: 0x000579a8; body bytes: 100; decompiled */

uint diag22_subpid_supported_mask(uint param_1,char param_2)

{
  short *psVar1;
  short *psVar2;
  uint uVar3;
  byte bVar4;
  short *psVar5;
  
  psVar1 = &tbl_diag22_subpid_supported_bits_0005f5b2;
  bVar4 = 0;
  uVar3 = 0;
  psVar2 = psVar1;
  psVar5 = psVar1;
  do {
    if (((*psVar1 == diag22_current_identifier_ffffd1ea) && (*(char *)((int)psVar1 + 3) == param_2)) &&
       ((psVar5[2] & diag_permission_mask_ffffd3b4_ffffd3b4) != 0)) {
      uVar3 = uVar3 + (int)*(char *)(psVar2 + 1);
    }
    bVar4 = bVar4 + 1;
    psVar2 = psVar2 + 3;
    psVar5 = psVar5 + 3;
    psVar1 = psVar1 + 3;
  } while (bVar4 < 0x24);
  return param_1 & uVar3;
}



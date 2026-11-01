/* ROM address: 0x0005730e; body bytes: 60; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f478. Table purpose inferred from
   neighboring code. */

void candidate_diag22_pid1631_tol_status_b570_b584(char param_1)

{
  char cVar2;
  undefined4 uVar1;
  byte bVar3;
  
  cVar2 = rx8_is_outside_tolerance_band(inferred_ram_b570_ffffb570_ffffb570,0,0x3727c5ac);
  bVar3 = cVar2 != '\0';
  if (inferred_ram_b584_ffffb584_ffffb584 != 0) {
    bVar3 = bVar3 | 2;
  }
  uVar1 = diag22_subpid_supported_mask(bVar3,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



/* ROM address: 0x00011004; body bytes: 38; decompiled */

void FUN_00011004(void)

{
  e2ram_tail_bulk_read();
  FUN_00038a04();
  e2ram_tire_revs_read();
  candidate_e2ram_config_bit_9f_read();
  e2ram_ecu_id_read();
  FUN_00019624();
  return;
}



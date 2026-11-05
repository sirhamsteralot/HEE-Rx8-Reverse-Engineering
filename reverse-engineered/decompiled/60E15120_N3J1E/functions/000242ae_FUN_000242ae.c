/* ROM address: 0x000242ae; body bytes: 476; decompiled */

undefined1 * e2ram_fault_status_collect(void)

{
  char cVar2;
  undefined1 *puVar1;
  
  cVar2 = ref_getFaultStatus__(0x14);
  if ((cVar2 == '\0') && (cVar2 = ref_getFaultStatus__(0x13), cVar2 == '\0')) {
    DAT_ffffb4dc = 0;
  }
  else {
    DAT_ffffb4dc = 1;
  }
  cVar2 = ref_getFaultStatus__(0x6a);
  DAT_ffffb4dd = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x22);
  if ((cVar2 == '\0') && (cVar2 = ref_getFaultStatus__(0x21), cVar2 == '\0')) {
    DAT_ffffb4de = 0;
  }
  else {
    DAT_ffffb4de = 1;
  }
  cVar2 = ref_getFaultStatus__(0x47);
  DAT_ffffb4df = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(100);
  DAT_ffffb4e0 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x5d);
  DAT_ffffb4e1 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x5b);
  if ((cVar2 == '\0') && (cVar2 = ref_getFaultStatus__(0x5c), cVar2 == '\0')) {
    DAT_ffffb4e2 = 0;
  }
  else {
    DAT_ffffb4e2 = 1;
  }
  cVar2 = ref_getFaultStatus__(0x83);
  DAT_ffffb4e3 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x65);
  DAT_ffffb4e4 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x4f);
  DAT_ffffb4e5 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x61);
  DAT_ffffb4e6 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x5f);
  DAT_ffffb4e7 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x60);
  DAT_ffffb4e8 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x6b);
  DAT_ffffb4e9 = cVar2 != '\0';
  cVar2 = ref_getFaultStatus__(0x42);
  if ((cVar2 != '\0') ||
     (((DAT_ffffb422 != '\0' && (7500.0 <= engine_speed_rpm_ffffb548)) && (inferred_ram_b410_ffffb410_ffffb410 < 13.48)))) {
    DAT_ffffb4ea = 1;
  }
  else {
    DAT_ffffb4ea = 0;
  }
  puVar1 = (undefined1 *)0x1;
  if ((DAT_ffffb43d == '\x01') ||
     (puVar1 = (undefined1 *)(uint)DAT_ffffd1c5, puVar1 == (undefined1 *)0x1)) {
    DAT_ffffb4eb = 1;
  }
  else {
    DAT_ffffb4eb = 0;
  }
  if (DAT_ffffbd48 == '\0') {
    puVar1 = &DAT_ffffb51c;
    DAT_ffffb51c = 1;
  }
  return puVar1;
}



/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002090a; body bytes: 360; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002099a) */
/* WARNING: Removing unreachable block (ram,0x000209a6) */
/* WARNING: Removing unreachable block (ram,0x000209ae) */
/* WARNING: Removing unreachable block (ram,0x000209ce) */
/* WARNING: Removing unreachable block (ram,0x000209be) */
/* WARNING: Removing unreachable block (ram,0x000209da) */

uint FUN_0002090a(void)

{
  undefined1 snapshot_DAT_ffffaa62;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  
  cVar2 = DAT_ffffaa63;
  snapshot_DAT_ffffaa62 = cranking_active_ffffaa62_ffffaa62;
  if (((((DAT_ffffb0cc == '\0') && (DAT_ffffb268 == '\0')) && (DAT_ffffb269 == '\0')) &&
      ((0x270 < engine_running_timer_ffffa424 && ((0x2c < DAT_ffffb25a || (DAT_ffffb267 == 0)))))) &&
     ((DAT_ffffb266 == '\x01' && (DAT_ffffaa63 == '\0')))) {
    DAT_ffffb267 = 1;
    DAT_ffffb25e = 0;
    DAT_ffffb25a = 0;
    if (DAT_ffffb53a == '\x01') {
      uVar4 = inferred_coolant_temperature_ffffa98c;
      DAT_ffffb24c = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_00069f6c);
      DAT_ffffb250 = FUN_00020abc(uVar4);
    }
    else {
      uVar4 = inferred_coolant_temperature_ffffa98c;
      DAT_ffffb24c = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_00069f80);
      DAT_ffffb250 = FUN_00020b50(uVar4);
    }
  }
  uVar3 = (uint)DAT_ffffb267;
  if (uVar3 == 1) {
    if (DAT_ffffb25e < DAT_ffffb250) {
      ref_osTaskScheduler(0,1,&DAT_ffffb24c);
      DAT_ffffb25e = rx8_add_u8_saturate((int)(char)DAT_ffffb25e,1);
    }
    uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffb25a,1);
    DAT_ffffb25a = (ushort)uVar3;
  }
  DAT_ffffb265 = snapshot_DAT_ffffaa62;
  DAT_ffffb266 = cVar2;
  return uVar3;
}



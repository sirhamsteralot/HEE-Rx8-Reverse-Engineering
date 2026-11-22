/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_request_calc [medium]: Computes DAT_ffffbdd8 (drives PE2) = DAT_ffffaa68(key-on flag) && (DAT_ffffbdda < 0x1f || (DAT_ffffa42c(injectors_off)==1 && DAT_ffffbde0==1) || DAT_ffffbddc <= 0x3e). Raw-bin verified pools: 0x2fcd0=0xaa68, 0x2fcd2=0xa42c, 0x2fce0=0xffffbdda, 0x2fce4=0xffffbdde, 0x2fce8=0xffffbde0, 0x2fcd8=0xffffbddc, 0x2fcce=0xbdd8; thresholds ROM 0x7bc58=0x1f (cmp/hs, keep while < 0x1f) and 0x7bc5c=0x3e (cmp/hi, keep while <= 0x3e); increment helper pool 0x2fcdc=0x2460, saturation word 0x2474=0xffff. bdda counts up while key-on, bdde while injectors-off, bddc every call; bde0 is only cleared here (0x2fc50) and produced by 0x2fcac. Caller 0x2f95c (fueling task worker 0x117ac).
 * RAM 0xffffbdda fuel_pump_key_on_grace_counter (uint16): Key-on grace counter in 0x2fc00: sat16 increment while key_on 0xffffaa68==1 via helper 0x2460, reset to 0 otherwise; the request survives while it is < ROM[0x7bc58]=0x1f (cmp/hs at 0x2fc64). Pool 0x2fce0=0xffffbdda.
 * RAM 0xffffbddc fuel_pump_run_on_grace_counter (uint16): Free-running run-on grace counter: sat16 increment on every 0x2fc00 call, kept <= ROM[0x7bc5c]=0x3e (cmp/hi at 0x2fc84); reset to 0 by 0x2fcac and loaded with 0xffff by 0x2fbf8, which disables the term. Pool 0x2fcd8=0xffffbddc.
 * RAM 0xffffbdde fuel_pump_injectors_off_counter (uint16): Injectors-off (fuel-cut) counter: sat16 increment while injectors_off 0xffffa42c==1, reset to 0 otherwise. Read by 0x2fcac, which compares it against ROM[0x7bc5a]=0x0000. Pool 0x2fce4=0xffffbdde.
 * RAM 0xffffbde0 fuel_pump_injectors_off_seen (uint8): Injectors-off seen flag: cleared by 0x2fc00 when injection is enabled (0x2fc50) and set by 0x2fcac as (DAT_ffffbdde > ROM[0x7bc5a] = 0); it makes the second grace term hold while fuel is cut. Pool 0x2fce8=0xffffbde0.
 */
/* ROM address: 0x0002fc00; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000300b8 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0002fc00(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = engine_running_flag_ffffaa68;
  cVar1 = engine_injectors_off_ffffa42c;
  if (engine_running_flag_ffffaa68 == '\x01') {
    DAT_ffffbdda = rx8_add_u16_saturate((int)(short)DAT_ffffbdda,1);
  }
  else {
    DAT_ffffbdda = 0;
  }
  if (cVar1 == '\x01') {
    DAT_ffffbdde = rx8_add_u16_saturate((int)DAT_ffffbdde,1);
  }
  else {
    DAT_ffffbdde = 0;
    DAT_ffffbde0 = '\0';
  }
  DAT_ffffbddc = rx8_add_u16_saturate((int)(short)DAT_ffffbddc,1);
  if (((DAT_ffffbdda < 0x1f) ||
      (((cVar1 == '\x01' && (cVar1 = DAT_ffffbde0, DAT_ffffbde0 == '\x01')) || (DAT_ffffbddc < 0x3f)
       ))) && (cVar1 = cVar2, cVar2 == '\x01')) {
    DAT_ffffbdd8 = 1;
  }
  else {
    cVar2 = cVar1;
    DAT_ffffbdd8 = 0;
  }
  return cVar2;
}



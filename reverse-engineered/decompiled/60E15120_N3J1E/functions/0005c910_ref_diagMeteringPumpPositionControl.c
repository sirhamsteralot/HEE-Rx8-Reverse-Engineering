/* ROM address: 0x0005c910; body bytes: 156; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005b100 (156 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Harness context: metering oil pump uses four control wires PCM 2W/2V/2AB/2Y (p14). Its separate
   switch at PCM 2N (pp16-17) indicates fully-open stepping-motor position during learning; it is
   distinct from oil pressure and oil level switches. Exact firmware phase-to-pin mapping remains
   unverified. */

int ref_diagMeteringPumpPositionControl(int param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x172d) {
      if ((DAT_ffffd36c & 0x40) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd325 = '\0';
      }
      else {
        DAT_ffffd325 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd349 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0x40) == 0) {
        DAT_ffffd325 = '\0';
      }
    }
  }
  if (DAT_ffffd325 == '\0') {
    DAT_ffffd349 = (char)param_1;
  }
  else if ((DAT_ffffd325 == '\x05') || (DAT_ffffd325 == '\a')) {
    param_1 = (int)DAT_ffffd349;
  }
  return param_1;
}



# Rev-limiter RE findings + behavior patcher

RE pass for the limiter patcher spec. Topology (all verified against the ROM):

```
0xe910 limiter decision (limit = 0xffffa44c + 0xffffa448; coolant margins via 3D
       tables 0x68fe0/0x68ffc — warm-up protection upstream, untouched)
  -> requests 0xffffa464 / 0xffffa465
0xedc4 fuel_cut_arbitration: sets SHARED flags 0xffffa444 / 0xffffa445, tail-jmp 0xe2d4
0xe2d4: 0xffffa430 = bit0(a444|a4a4) | bit1(a445|a4a5)
consumers of the shared flags:
  fuel:  0xff04 returns a430 -> injection scheduler (per-channel masks 0x4e27c)
  spark: 0x12938 (ignition task 0x142a4) reads a444/a445 -> a68a -> 0x128ac -> a689
         -> 0x129c0 zeroes per-rotor timing
=> Option A: one flag pair gates fuel AND ignition together (spec I1/I2 by construction).
```

Call site: 0x20df0 (phase scheduler, param ∈ {0,6,12,18}) calls 0xedc4 via pool
word (0x20ffc in N3J1E). The patcher repoints that one word to a code cave.

Patcher: `Mazda_RX8_PCM_ReverseEngineering/Utilities/patch_limiter_behavior.py`
(+ PATCHER_limiter_behavior.md). Modes stock/hard/soft; cal table "Rev Limiter
Behavior" (4 float cells) in a verified-free cal run; RomRaider def added to
RX8Defs_Copy for 60E15120. Locates uniquely in 8/10 stock ROMs (60E32000 pair
SKIP — different limiter body). Static validation only.

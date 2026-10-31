Local SH-2E analysis configuration for Ghidra 12.1.3

The supplied SH-2 definition disables FPU decoding. The supplied SH-2A definition
supports the FPU but also accepts SH-2A-only instructions. The related reference
project uses SH-2A. Inspection found 46 four-byte decodes in the initial target
analysis, including ROM pointer-table data decoded as `movi20`.

This configuration uses Ghidra's existing `superh.sinc` with SH_VERSION=2 and
FPU=1. It excludes the SH-2A-specific decoder branches while retaining floating
point registers and operations. The existing `superh2a.cspec` is reused for the
floating-point calling convention (FR4–FR7 arguments; FR0 result).

To open RX8_SH2E.gpr, copy sh-2e.ldefs, sh-2e.slaspec and sh-2e.sla into your
Ghidra 12.1.3 `Ghidra/Processors/SuperH/data/languages` directory before launching
Ghidra. Recompile with `support/sleigh <path>/sh-2e.slaspec` if needed. Only the
small configuration and its compiled form are supplied; superh.sinc, pspec and
cspec are part of the Ghidra installation.

This is an analysis configuration, not an independently validated processor
emulator. It inherits Ghidra's instruction semantics and ABI limitations. Exact
SH7055 FPU exceptions, rounding modes and peripheral behavior are not verified.
The C files can be read without installing this configuration.

Hardware reference: https://www.renesas.com/en/document/mah/sh-2e-sh7055s-hardware-manual

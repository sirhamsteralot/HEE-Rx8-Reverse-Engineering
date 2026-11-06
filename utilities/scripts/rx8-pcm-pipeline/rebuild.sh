#!/usr/bin/env bash
# Reproduce the export against THIS repo's promoted layout (no input/Tuning-merged
# needed). Use a NEW project name. Paths are resolved via paths.py conventions:
#   decompiled -> reverse-engineered/decompiled/60E15120_N3J1E
#   disassembly -> reverse-engineered/disassembly/60E15120_N3J1E
#   metadata -> data/labels/60E15120_N3J1E
#   Ghidra projects -> ${GHIDRA_WORK:-input/ghidra-work} (not committed)
#   ROMs/upstream repos -> submodules/ (read-only)
set -euo pipefail
: "${GHIDRA_HOME:?Set GHIDRA_HOME to your Ghidra 12.1.3 directory}"
base=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)          # this pipeline dir
root=$(cd -- "$base/../../.." && pwd)                              # repo root
workspace="$root"
project=${1:?Pass a new project name, for example RX8_REPRO}
gwork=${GHIDRA_WORK:-$root/input/ghidra-work}
dec="$root/reverse-engineered/decompiled/60E15120_N3J1E"
disasm="$root/reverse-engineered/disassembly/60E15120_N3J1E"
meta="$root/data/labels/60E15120_N3J1E"
roms="$root/submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs"
gscripts="$root/utilities/tools/ghidra/scripts"
gproc="$root/utilities/tools/ghidra/processor"
headless="$GHIDRA_HOME/support/analyzeHeadless"
languages="$GHIDRA_HOME/Ghidra/Processors/SuperH/data/languages"
cp "$gproc/sh-2e.slaspec" "$gproc/sh-2e.ldefs" "$languages/"
"$GHIDRA_HOME/support/sleigh" "$languages/sh-2e.slaspec"
"$headless" "$gwork/reference_project" RX8_6 -process 60E0FC00.bin -readOnly -noanalysis -scriptPath "$gscripts" -postScript ExportReference.java "$meta"
(cd "$root" && python3 "$base/prepare_metadata.py")
"$headless" "$gwork/ghidra_project" "$project" -import "$roms/60E15120_N3J1E.bin" -processor SuperH:BE:32:SH-2E -cspec default -scriptPath "$gscripts" -preScript SetupTarget.java "$root" -analysisTimeoutPerFile 600
"$headless" "$gwork/ghidra_project" "$project" -process 60E15120_N3J1E.bin -scriptPath "$gscripts" -preScript RefineTarget.java "$meta" -analysisTimeoutPerFile 600
"$headless" "$gwork/ghidra_project" "$project" -process 60E15120_N3J1E.bin -scriptPath "$gscripts" -preScript RecoverDispatch.java "$meta" -postScript AnnotateHardware.java "$root/docs/architecture/hardware" -postScript ExportTarget.java "$dec" "$disasm" -analysisTimeoutPerFile 600
(cd "$root" && python3 "$base/scripts/annotate_cross_ecu.py")
(cd "$root" && python3 "$base/scripts/review_knock_loop_labels.py")
(cd "$root" && python3 "$base/scripts/review_fueling_labels.py")
(cd "$root" && python3 "$base/scripts/review_intake_labels.py")
(cd "$root" && python3 "$base/scripts/review_idle_control_labels.py")
(cd "$root" && python3 "$base/scripts/review_dsc_can_labels.py")
(cd "$root" && python3 "$base/scripts/annotate_source_review.py")
(cd "$root" && python3 "$base/scripts/name_lookup_variables.py")
(cd "$root" && python3 "$base/scripts/merge_reviewed_lookup_aliases.py")
(cd "$root" && python3 "$base/scripts/integrate_reviewed_names.py")
(cd "$root" && python3 "$base/scripts/annotate_math_units.py")
(cd "$root" && python3 "$base/scripts/verify_math_units.py")
(cd "$root" && python3 "$base/scripts/refine_readability.py")
(cd "$root" && python3 "$base/scripts/refine_sort_record.py")
(cd "$root" && python3 "$base/scripts/refine_lookup_family.py")
(cd "$root" && python3 "$base/scripts/refine_export_cleanup.py")
(cd "$root" && python3 "$base/scripts/review_knock_loop_labels_apply.py")
(cd "$root" && python3 "$base/scripts/verify_readability.py")
(cd "$root" && python3 "$base/scripts/validate_export.py")
(cd "$root" && python3 "$base/scripts/validate_reports.py")
(cd "$root" && python3 "$base/scripts/write_report.py")

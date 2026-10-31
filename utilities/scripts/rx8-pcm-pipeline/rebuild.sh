#!/usr/bin/env bash
# Reproduce the export in the original workspace layout. Use a NEW project name.
set -euo pipefail
: "${GHIDRA_HOME:?Set GHIDRA_HOME to your Ghidra 12.1.3 directory}"
base=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
workspace=$(cd -- "$base/../.." && pwd)
project=${1:?Pass a new project name, for example RX8_REPRO}
headless="$GHIDRA_HOME/support/analyzeHeadless"
languages="$GHIDRA_HOME/Ghidra/Processors/SuperH/data/languages"
cp "$base/processor/sh-2e.slaspec" "$base/processor/sh-2e.ldefs" "$languages/"
"$GHIDRA_HOME/support/sleigh" "$languages/sh-2e.slaspec"
"$headless" "$base/reference_project" RX8_6 -process 60E0FC00.bin -readOnly -noanalysis -scriptPath "$base/scripts" -postScript ExportReference.java "$base/metadata"
python3 "$base/scripts/prepare_metadata.py"
"$headless" "$base/ghidra_project" "$project" -import "$workspace/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin" -processor SuperH:BE:32:SH-2E -cspec default -scriptPath "$base/scripts" -preScript SetupTarget.java "$base" -analysisTimeoutPerFile 600
"$headless" "$base/ghidra_project" "$project" -process 60E15120_N3J1E.bin -scriptPath "$base/scripts" -preScript RefineTarget.java "$base/metadata" -analysisTimeoutPerFile 600
"$headless" "$base/ghidra_project" "$project" -process 60E15120_N3J1E.bin -scriptPath "$base/scripts" -preScript RecoverDispatch.java "$base/metadata" -postScript AnnotateHardware.java "$base/hardware" -postScript ExportTarget.java "$base/decompiled" -analysisTimeoutPerFile 600
python3 "$base/scripts/annotate_cross_ecu.py"
python3 "$base/scripts/review_knock_loop_labels.py"
python3 "$base/scripts/review_fueling_labels.py"
python3 "$base/scripts/review_intake_labels.py"
python3 "$base/scripts/annotate_source_review.py"
python3 "$base/scripts/name_lookup_variables.py"
python3 "$base/scripts/merge_reviewed_lookup_aliases.py"
python3 "$base/scripts/integrate_reviewed_names.py"
python3 "$base/scripts/annotate_math_units.py"
python3 "$base/scripts/verify_math_units.py"
python3 "$base/scripts/refine_readability.py"
python3 "$base/scripts/refine_sort_record.py"
python3 "$base/scripts/refine_lookup_family.py"
python3 "$base/scripts/refine_export_cleanup.py"
python3 "$base/scripts/review_knock_loop_labels_apply.py"
python3 "$base/scripts/verify_readability.py"
python3 "$base/scripts/validate_export.py"
python3 "$base/scripts/validate_reports.py"
python3 "$base/scripts/write_report.py"

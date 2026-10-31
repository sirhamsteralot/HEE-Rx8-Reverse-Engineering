# OCR extracts of RX8Club thread screenshots

- **Source:** the `capture_*`/`image_*`/`img_*` screenshots inside
  `input/Open Source S1 RX-8 … - Page N - RX8Club.com_files/` (pages 1–9 of thread
  276137). Raw images stay in `input/` (uncommitted).
- **Method:** RapidOCR (rapidocr-onnxruntime, ONNX models) on 2026-10-31, CPU.
  Each `.txt` here is one image: lines are `[confidence] text`, reading order top-to-bottom.
  Filenames: `input__<image-name>.txt` (the page field in the name collapsed to `input`;
  map an image to its page by grepping the image hash in `input/*.htm` — the
  content-rich screenshots are all on pages 2–3).
- **Caveats:** OCR of small UI text is noisy (see the `0.9x` confidences and mangled
  identifiers like `Igntion`, `60E0FCo0`). Verify anything load-bearing against our
  own disassembly before using. Files with ≤5 lines are mostly UI chrome (icons,
  dialogs) and kept for completeness.

# Subject PDF

The `subject.pdf` file should be placed in this directory. It is the **single source of truth** for all project requirements.

## Why subject.pdf is Important

The subject PDF contains:
- Exact exercise requirements
- Allowed/forbidden functions
- Expected output formats
- Specific constraints
- Evaluation criteria

## How to Add subject.pdf

1. Download the subject from your 42 intranet
2. Place it in the root directory of this repository:
   ```bash
   cp /path/to/downloaded/subject.pdf ./subject.pdf
   ```

3. Commit it to the repository:
   ```bash
   git add subject.pdf
   git commit -m "Add project subject PDF"
   git push
   ```

## Alternative

If you cannot include the PDF in the repository for copyright reasons:
1. Keep it locally in the root directory
2. Add `subject.pdf` to `.gitignore` to exclude it
3. Reference it in documentation as needed

---

**Important**: Always refer to the official subject.pdf when implementing exercises. This documentation is supplementary and should not replace the official subject.

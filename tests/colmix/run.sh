#!/bin/bash
set -euo pipefail
HERE=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
PROJECT=$(cd "$HERE/../.." && pwd)
TASK_TMP=$(mktemp -d "${TMPDIR:-/tmp}/deco156-colmix.XXXXXX")
trap 'rm -rf "$TASK_TMP"' EXIT
iverilog -g2012 -s test -o "$TASK_TMP/test" "$HERE/test.v"   "$PROJECT/rtl/osman/jtosman_colmix.v"   "$PROJECT/rtl/jtframe/video/jtframe_blank.v"
vvp "$TASK_TMP/test"

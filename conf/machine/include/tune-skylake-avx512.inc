DEFAULTTUNE ?= "skylake-avx512-64"

require conf/machine/include/tune-skylake.inc

TUNEVALID[skylake-avx512] = "Enable Skylake specific processor optimizations with AVX512 instructions supported"

TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "skylake-avx512", " -march=skylake-avx512 -mtune=skylake-avx512 -mfpmath=sse", "", d)}"

AVAILTUNES += "skylake-avx512-32 skylake-avx512-64"

TUNE_FEATURES_tune-skylake-avx512-32 = "${TUNE_FEATURES_tune-x86} skylake-avx512 mpx"
TUNE_FEATURES_tune-skylake-avx512-64 = "${TUNE_FEATURES_tune-x86-64} skylake-avx512 mpx"

BASE_LIB_tune-skylake-avx512-32 = "lib"
BASE_LIB_tune-skylake-avx512-64 = "lib64"

TUNE_PKGARCH_tune-skylake-avx512-32 = "skylake-avx512-32"
TUNE_PKGARCH_tune-skylake-avx512-64 = "skylake-avx512-64"

PACKAGE_EXTRA_ARCHS_tune-skylake-avx512-32 = "${PACKAGE_EXTRA_ARCHS_tune-skylake-32} skylake-avx512-32"
PACKAGE_EXTRA_ARCHS_tune-skylake-avx512-64 = "${PACKAGE_EXTRA_ARCHS_tune-skylake-64} skylake-avx512-64"

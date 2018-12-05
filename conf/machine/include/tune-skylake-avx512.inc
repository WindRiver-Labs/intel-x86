DEFAULTTUNE ?= "skylake-avx512-64"

require conf/machine/include/tune-skylake.inc

TUNEVALID[skylake-avx512] = "Enable Skylake specific processor optimizations with AVX512 instructions supported"

TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "skylake-avx512", " -msse4.2 -mfpmath=sse -march=skylake-avx512 -mtune=skylake-avx512", "", d)}"
EXTRA_OECONF_append_pn-gcc-runtime = " ${@bb.utils.contains("TUNE_FEATURES", "skylake-avx512", " --with-cpu=skylake-avx512 --with-arch=skylake-avx512", "", d)}"

AVAILTUNES += "skylake-avx512-32 skylake-avx512-64"

TUNE_FEATURES_tune-skylake-avx512-32 = "${TUNE_FEATURES_tune-x86} skylake-avx512 mpx"
TUNE_FEATURES_tune-skylake-avx512-64 = "${TUNE_FEATURES_tune-x86-64} skylake-avx512 mpx"

BASE_LIB_tune-skylake-avx512-32 = "lib"
BASE_LIB_tune-skylake-avx512-64 = "lib64"

TUNE_PKGARCH_tune-skylake-avx512-32 = "skylake-avx512-32"
TUNE_PKGARCH_tune-skylake-avx512-64 = "skylake-avx512-64"

PACKAGE_EXTRA_ARCHS_tune-skylake-avx512-32 = "${PACKAGE_EXTRA_ARCHS_tune-skylake-32} skylake-avx512-32"
PACKAGE_EXTRA_ARCHS_tune-skylake-avx512-64 = "${PACKAGE_EXTRA_ARCHS_tune-skylake-64} skylake-avx512-64"

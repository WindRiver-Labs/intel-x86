DEFAULTTUNE ?= "skylake-64"

require conf/machine/include/tune-broadwell.inc

# Extra tune features
TUNEVALID[skylake] = "Enable Skylake specific processor optimizations"
TUNEVALID[avx512] = "Enable support for AVX512 instructions"
# MPX support is not enabled by tunes, because it's a larger-scale
# change than enabling/disabling instructions. Putting this here so
# things could in theory check TUNE_FEATURES for it.
TUNEVALID[mpx] = "Enable support for MPX instructions"
# Handled by SDK.
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "avx512", " -mavx512bw -mavx512cd -mavx512dq -mavx512f -mavx512vl", "", d)}"

# Extra tune selections
AVAILTUNES += "skylake-32 skylake-64 skylake-avx512-32 skylake-avx512-64"
TUNE_FEATURES_tune-skylake-32 = "${TUNE_FEATURES_tune-haswell-ep-32} skylake mpx"
TUNE_FEATURES_tune-skylake-avx512-32 = "${TUNE_FEATURES_tune-haswell-ep-32} skylake mpx avx512"
TUNE_FEATURES_tune-skylake-64 = "${TUNE_FEATURES_tune-haswell-ep-64} skylake mpx"
TUNE_FEATURES_tune-skylake-avx512-64 = "${TUNE_FEATURES_tune-haswell-ep-64} skylake mpx avx512"

BASE_LIB_tune-skylake-32 = "lib"
BASE_LIB_tune-skylake-64 = "lib64"
BASE_LIB_tune-skylake-avx512-32 = "lib"
BASE_LIB_tune-skylake-avx512-64 = "lib64"
TUNE_PKGARCH_tune-skylake-32 = "skylake-32"
TUNE_PKGARCH_tune-skylake-64 = "skylake-64"
TUNE_PKGARCH_tune-skylake-avx512-32 = "skylake-avx512-32"
TUNE_PKGARCH_tune-skylake-avx512-64 = "skylake-avx512-64"
PACKAGE_EXTRA_ARCHS_tune-skylake-32 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-ep-32} skylake-32"
PACKAGE_EXTRA_ARCHS_tune-skylake-64 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-ep-64} skylake-64"
PACKAGE_EXTRA_ARCHS_tune-skylake-avx512-32 = "${PACKAGE_EXTRA_ARCHS_tune-skylake-32} skylake-avx512-32"
PACKAGE_EXTRA_ARCHS_tune-skylake-avx512-64 = "${PACKAGE_EXTRA_ARCHS_tune-skylake-64} skylake-avx512-64"

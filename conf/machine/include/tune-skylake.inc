DEFAULTTUNE ?= "skylake-64"

require conf/machine/include/tune-haswell.inc

# Extra tune features
TUNEVALID[skylake] = "Enable Skylake specific processor optimizations"
# MPX support is not enabled by tunes, because it's a larger-scale
# change than enabling/disabling instructions. Putting this here so
# things could in theory check TUNE_FEATURES for it.
TUNEVALID[mpx] = "Enable support for MPX instructions"
# Handled by SDK.
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "skylake", " -march=skylake -mtune=skylake -mfpmath=sse", "", d)}"

# Extra tune selections
AVAILTUNES += "skylake-32 skylake-64"
TUNE_FEATURES_tune-skylake-32 = "${TUNE_FEATURES_tune-x86} skylake mpx"
TUNE_FEATURES_tune-skylake-64 = "${TUNE_FEATURES_tune-x86-64} skylake mpx"

BASE_LIB_tune-skylake-32 = "lib"
BASE_LIB_tune-skylake-64 = "lib64"

TUNE_PKGARCH_tune-skylake-32 = "skylake-32"
TUNE_PKGARCH_tune-skylake-64 = "skylake-64"

PACKAGE_EXTRA_ARCHS_tune-skylake-32 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-ep-32} skylake-32"
PACKAGE_EXTRA_ARCHS_tune-skylake-64 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-ep-64} skylake-64"

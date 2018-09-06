DEFAULTTUNE ?= "broadwell-64"

require conf/machine/include/tune-haswell.inc

# Extra tune features
TUNEVALID[broadwell] = "Enable Broadwell specific processor optimizations"
# Handled by SDK.
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "broadwell", " -march=broadwell -mtune=broadwell -mfpmath=sse -msse4.2 -mavx2", "", d)}"

# Extra tune selections
AVAILTUNES += "broadwell-32 broadwell-64"
TUNE_FEATURES_tune-broadwell-32 = "${TUNE_FEATURES_tune-haswell-ep-32} broadwell"
TUNE_FEATURES_tune-broadwell-64 = "${TUNE_FEATURES_tune-haswell-ep-64} broadwell"
BASE_LIB_tune-broadwell-32 = "lib"
BASE_LIB_tune-broadwell-64 = "lib64"
TUNE_PKGARCH_tune-broadwell-32 = "broadwell-32"
TUNE_PKGARCH_tune-broadwell-64 = "broadwell-64"
PACKAGE_EXTRA_ARCHS_tune-broadwell-32 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-ep-32} broadwell-32"
PACKAGE_EXTRA_ARCHS_tune-broadwell-64 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-ep-64} broadwell-64"

DEFAULTTUNE ?= "haswell-64"

require conf/machine/include/tune-corei7.inc

# Extra tune features
TUNEVALID[haswell] = "Enable Haswell specific processor optimizations"
TUNEVALID[haswell-ep] = "Enable Haswell specific processor optimizations (with working TSX instructions)"
# Handled by SDK.
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "haswell", " -msse4.2 -mfpmath=sse -march=haswell -mtune=haswell", "", d)}"
EXTRA_OECONF_append_pn-gcc-runtime = " ${@bb.utils.contains("TUNE_FEATURES", "haswell", " --with-cpu=haswell --with-arch=haswell", "", d)}"

# Extra tune selections
AVAILTUNES += "haswell-32 haswell-64"
TUNE_FEATURES_tune-haswell-32 = "${TUNE_FEATURES_tune-x86} haswell"
TUNE_FEATURES_tune-haswell-64 = "${TUNE_FEATURES_tune-x86-64} haswell"
BASE_LIB_tune-haswell-32 = "lib"
BASE_LIB_tune-haswell-64 = "lib64"
TUNE_PKGARCH_tune-haswell-32 = "haswell-32"
TUNE_PKGARCH_tune-haswell-64 = "haswell-64"
PACKAGE_EXTRA_ARCHS_tune-haswell-32 = "${PACKAGE_EXTRA_ARCHS_tune-x86} haswell-32"
PACKAGE_EXTRA_ARCHS_tune-haswell-64 = "${PACKAGE_EXTRA_ARCHS_tune-x86-64}} haswell-64"

AVAILTUNES += "haswell-ep-32 haswell-ep-64"
TUNE_FEATURES_tune-haswell-ep-32 = "${TUNE_FEATURES_tune-haswell-32} haswell-ep"
TUNE_FEATURES_tune-haswell-ep-64 = "${TUNE_FEATURES_tune-haswell-64} haswell-ep"
BASE_LIB_tune-haswell-ep-32 = "lib"
BASE_LIB_tune-haswell-ep-64 = "lib64"
TUNE_PKGARCH_tune-haswell-ep-32 = "haswell-ep-32"
TUNE_PKGARCH_tune-haswell-ep-64 = "haswell-ep-64"
PACKAGE_EXTRA_ARCHS_tune-haswell-ep-32 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-32} haswell-ep-32"
PACKAGE_EXTRA_ARCHS_tune-haswell-ep-64 = "${PACKAGE_EXTRA_ARCHS_tune-haswell-64} haswell-ep-64"

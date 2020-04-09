QB_MEM ?= "-m 1024"
IMAGE_CLASSES += "qemuboot"

QB_SYSTEM_NAME_intel-x86-64 = "qemu-system-x86_64"
QB_CPU_intel-x86-64 = "-cpu Nehalem"
QB_CPU_KVM_intel-x86-64 = "-cpu kvm64"

QB_AUDIO_DRV = "alsa"
QB_AUDIO_OPT = "-soundhw ac97,es1370"
QB_KERNEL_CMDLINE_APPEND = "oprofile.timer=1"
QB_OPT_APPEND = "-vga std -show-cursor -usb -device usb-tablet"
QB_OPT_APPEND += "-object rng-random,filename=/dev/urandom,id=rng0 -device virtio-rng-pci,rng=rng0"

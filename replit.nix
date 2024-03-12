{ pkgs }: {
	deps = [
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
        pkgs.qemu
		pkgs.gcc-arm-embedded-9
		pkgs.nodejs_21
	];
}
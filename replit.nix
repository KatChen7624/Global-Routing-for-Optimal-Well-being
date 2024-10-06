{ pkgs }: {
	deps = [
		pkgs.python39Packages.pip
  pkgs.qtile
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}
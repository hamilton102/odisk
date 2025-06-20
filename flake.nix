{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };


  outputs = { self, nixpkgs }:
    let

    pkgs = import nixpkgs {system="x86_64-linux";};

    in {

      devShells.x86_64-linux.default = pkgs.mkShell {

        packages = [
          pkgs.llvmPackages_19.clang-tools
          pkgs.glibc
          pkgs.libgcc
          pkgs.valgrind
        ];
      };
    };
}

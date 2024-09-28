fukaccia
========

This is a library that wraps useful FUKA C++ functions and builds as a shared objects,
so it they can be called from other languages, such as C, Python, Go.
The library and binary are constucted in a way to allow parallell interpolation,
which is not available in FUKA exporter functions at the moment.

Installation
----
Install Task first (https://taskfile.dev).

Activate target Mamba/Conda environment.

Then, install the run dependencies into the environment:
```shell
task install-run-deps
```

Finally, install binary distribution of `fukaccia`:
```shell
task install-binary
```

Building from source
----

Install Task first (https://taskfile.dev).

Build FUKA, so that it produces a static C++ library called `libkadath.a`
in `$HOME_KADATH/lib`.

Export variable that points to the FUKA build:
```shell
export HOME_KADATH=$HOME/fuka
```

Install build dependecies via
```shell
task install-build-deps
```

Run the build:

```shell
task build
```

This will produce `libfukaccia.so`, `libfuka_exporter.so`, and `fukaccia` binary.
You should then place the libraries to the locations locatable by ldd, or
append `LD_LIBRARY_PATH`. The `fukaccia` binary should be put into the paths
specified in `$PATH` environment variable.

After that, your can link with `libfukaccia`.

Troubleshooting
---------------

On older Linux distributions, the GNU ld linker has a bug that prevents successful linking
with Go libary. It throws errors about debug sections in such a case. To resolve this,
use a fresher linker:

```shell
mamba install binutils
```

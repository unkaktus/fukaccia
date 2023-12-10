fukaccia
========

This is a library that wraps useful FUKA C++ functions and builds as a shared objects,
so it they can be called from other languages, such as C, Python, Go.
The library and binary are constucted in a way to allow parallell interpolation,
which is not available in FUKA exporter functions at the moment.

Installation
----
```shell
mamba install -c https://mamba.unkaktus.art fukaccia
```

Building from source
----

Install Task first (https://taskfile.dev):
```shell
mamba install go-task
```

Build FUKA, so that it produces a static C++ library called `libkadath.a`
in `$HOME_KADATH/lib`.

Export variable that points to the FUKA build:
```shell
export HOME_KADATH=$HOME/fuka
```

Install dependecies via
```shell
task install-deps
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
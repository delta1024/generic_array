# A Generic Array for c.

## Build Dependencies
TODO: add instalation instructions for non zig build systems.
## Instalation
add the folowing to your build.zig.zon file: 
```zig
.{
    // Rest of your bulid.zig.zon file.
    .dependencies = .{
        .generic_array = .{
            .url = "https://github.com/delta1024/generic_array/archive/refs/tags/0.1.0.tar.gz",
            .hash = "1220af84f762b04f5443edf90fcdf273a87930bfa44b1485cb8a61c913cb185046f2",
        },
    },
}
```

your build.zig might look something like this.
```zig
const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});
    const array_dep = b.dependency("generic_array", .{});
    var array_lib = array_dep.artifact("generic_array");

    const exe = b.addExecutable(.{
        .name = "run",
        .root_source_file = .{ .path = "main.c" },
        .optimize = optimize,
        .target = target,
        .link_libc = true,
    });
    exe.installLibraryHeaders(array_lib);
    exe.linkLibrary(array_lib);
    b.installArtifact(exe);
}

```


## Example Usage

```c
#include <generic_array.h>
#include <stdint.h>
#include <stdio.h>

int main() {
	uint8_t *barray = array_initialize();
	barray = *array_adjust_for_push(barray, sizeof(uint8_t));
	barray[array_push(barray)] = 22;
	printf("%d\n", barray[array_pop(barray)]);
	array_free(barray);
}
```

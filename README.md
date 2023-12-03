# A Generic Array for c.

## Instalation
add the folowing to your build.zig.zon file: 
```ziglang
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
```ziglang
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




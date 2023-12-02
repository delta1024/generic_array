const std = @import("std");
pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});
    const lib = b.addStaticLibrary(.{
        .name = "generic_array",
        .root_source_file = .{ .path = "array.c" },
        .target = target,
        .optimize = optimize,
        .link_libc = true,
    });

    b.installArtifact(lib);
    const header = b.addInstallHeaderFile("generic_array.h", "generic_array.h");
    lib.step.dependOn(&header.step);
    const clean_step = b.step("clean", "clean build dir");
    for ([_][]const u8{
        "zig-out",
        "zig-cache",
    }) |path| {
        const clean_cmd = b.addRemoveDirTree(path);
        clean_step.dependOn(&clean_cmd.step);
    }
}

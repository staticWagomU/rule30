const std = @import("std");
const print = std.debug.print;
const math = @import("math");

pub fn main() void {
    const n: i8 = 121;
    const s: i8 = 50;
    var cells = [_]u8{0} ** (n + 2);
    var previous_cells = [_]u8{0} ** (n + 2);
    const state = [8]u8{ 0, 1, 1, 1, 1, 0, 0, 0 };
    cells[n / 2] = 1;

    for (cells) |c| print("{}", .{c});
    print("\n", .{});

    var j: u8 = 0;
    while (j < s) : (j += 1) {
        var i: u8 = 1;
        while (i <= n) : (i += 1) {
            const a: u8 = (cells[i - 1] << 2) + (cells[i] << 1) + (cells[i + 1]);
            previous_cells[i] = state[a];
        }
        for (previous_cells) |c, k| cells[k] = c;
        for (cells) |c| print("{}", .{c});
        print("\n", .{});
    }
}

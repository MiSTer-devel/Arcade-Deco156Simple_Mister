
Deco156 simple boards

This is a draft, i started this because i wanted to play osman and look at caveman ninja 2 on the mister.
I got osman to work properly but then i got distracted from other work, i ll come back to this one after my vacationing.

If meantime a nicer open source implementation is released even better.

Osman plays with some glitches on the HUD and i have still to look into it.

## Amber CPU fixes

The exported CPU now includes adapted Night Slashers bus-completion fixes and
warm-reset corrections. Three Amber files differ from the captured build;
their original versions are retained in `provenance/amber-before/`, with the
patch in `provenance/amber-fixes.patch`. The adaptation also holds completed
read data and prevents repeated writes to IO registers. FPGA/CPU-enable
clocks remain 56 MHz / 7 MHz.

Run `tests/amber/run.sh` with Icarus Verilog for the CPU regression. It checks
word/byte transfers, LDM/STM, carry/overflow, unique writes, variable bus waits
and re-execution after warm reset. The instruction test completes in 787
system clocks versus 1,827 before the patch; this is not a gameplay speed
measurement. Quartus 17.0.2 analysis/elaboration passes with the CPU changes.
Night Slashers' savestate wiring, optional CPU speeds and different coprocessor
are not included in this patch.

Full cold-boot simulations with this CPU patch completed 1,800 game frames for
Osman and 1,200 for Heavy Smash Europe, reaching animated titles and attract /
tutorial scenes. Their 128-byte EEPROM uploads match the Osman defaults and
fresh MAME Heavy Smash factory state respectively. Physical MiSTer speed and
full fitting/timing still require checking after rebuilding the RBF.

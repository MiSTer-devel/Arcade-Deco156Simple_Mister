
# Deco156 simple compatible mister core

This is a mame derived core compatibile with:

- Joe and Mac Returns
- Osman / Cannon Dancer
- Chain reaction / Magical Drop / Magical Drop Plus
- Heavy Smash
- Charlie Ninja
- Party Time Gonta the diver 2

## Known issues

- Some scene replays differ from MAME at the first video column.

## Video fixes

- Chain Reaction sprite ROM interleave is fixed in the MRA. Replace its MRA
  and reload the game; this fix needs no RBF rebuild.
- Heavy Smash priority is fixed in the RTL. Rebuild the RBF to use that fix.

All 15 captured scenes per game replay successfully. Mixer regression tests
(`tests/colmix/run.sh`) and Quartus analysis/elaboration pass; hardware testing
of the updated source remains.

## Thanks

This core was made possible by

Jotego via JTFRAME and its included modules
Sorg via the mister platform
Amber23 Arm cpu core by 
Some patches to the Amber23 core found in @rmonic79 Night Slasher core
Claude Code / Codex / Metr AI

/*
<module> Axle Counter Planning Rule Book

This module processes rules to determine axle counter position and
generates the position in horizontal, lateral, and its
orientation.

Source of the code is based on:
Ril 819.1100 (Main)
Ril 819.0509
Ril 819.0505

*/

lateralPosition(I_infrastructureLateralSide, right).
lateralPosition(I_infrastructureLateralSide, left).

axleCounterLocation(true, _, I_mainSignalLocation, O_axleCounterLocation):-
  O_axleCounterLocation is I_mainSignalLocation.

axleCounterLocation(true, _, I_shuntingSignalLocation, O_axleCounterLocation):-
  O_axleCounterLocation is I_shuntingSignalLocation.

axleCounterLocation(true, _, I_switchTipLocation, O_axleCounterLocation):-
  O_axleCounterLocation is I_switchTipLocation - 3/1000.

axleCounterLocation(true, false, I_switchBoundaryMarkLocation, O_axleCounterLocation):-
  O_axleCounterLocation is I_switchBoundaryMarkLocation + 6/1000.

axleCounterLocation(true, true, I_switchBoundaryMarkLocation, O_axleCounterLocation):-
  O_axleCounterLocation is I_switchBoundaryMarkLocation + 16/1000.

axleCounterLocation(true, I_flankProtectionSignalLocation, O_axleCounterLocation):-
  O_axleCounterLocation is I_flankProtectionSignalLocation.

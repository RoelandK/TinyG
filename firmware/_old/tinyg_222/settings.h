/*
 * settings.h - system configuration values
 * Part of TinyG project
 *
 * Copyright (c) 2010 Alden S. Hart, Jr.
 *
 * TinyG is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 *
 * TinyG is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with TinyG  If not, see <http://www.gnu.org/licenses/>.
 */
/* Note: The values in this file are the default settings that are loaded
 * 		 into a virgin EEPROM, and can be changed using the config commands.
 *		 After initial load the EEPROM values (or changed values) are used.
 *
 *		 System and hardware settings that you shouldn't need to change 
 *		 are in system.h  Application settings that also shouldn't need 
 *		 to be changed are in tinyg.h
 */

#ifndef settings_h
#define settings_h

/*
 * SYSTEM CONFIGURATION VALUES - for initial load of EEPROM values
 */

/* general machine settings */

#define MM_PER_ARC_SEGMENT 0.05
#define MIN_SEGMENT_TIME 20000		// microseconds
//#define MAX_LINEAR_JERK 100000000	// mm/(min^3)
#define MAX_LINEAR_JERK 1000000	// mm/(min^3)
#define MAX_ANGULAR_JERK 100000000	// mm/(min^3)

/* Gcode power-on defaults */

#define GCODE_PLANE	CANON_PLANE_XY
#define GCODE_UNITS 1				// mm
#define GCODE_PATH_CONTROL PATH_CONTROL_MODE_EXACT_STOP
#define GCODE_TOOL 1
#define GCODE_FEED_RATE 400			// mm/min
#define GCODE_SPINDLE_SPEED 1500	// rpm

/* axis mapping and modes */

#define X_MAP_AXIS 0				// standard axis mappings (off by one)
#define Y_MAP_AXIS 1
#define Z_MAP_AXIS 2
#define A_MAP_AXIS 3

#define X_AXIS_MODE 0				// 0=normal mode
#define Y_AXIS_MODE 0
#define Z_AXIS_MODE 0				// 1= Z disable (for dry runs)
#define A_AXIS_MODE 0				// 1= A extruder mode (2= coordinated spindle)

/* motor settings */

#define STEP_ANGLE 1.8				// or 0.9 in some cases
#define MICROSTEP_MODE 8			// Choose one of: 8, 4, 2, 1

/* robot dimensions */

#define X_TRAVEL 400				// total travel in X in mm
#define Y_TRAVEL 400
#define Z_TRAVEL 50
#define A_RADIUS RADIAN				// makes mm/min = degrees/min on conversion

/* homing cycle settings */

//#define HOMING_MODE TRUE			// set TRUE for power-on-homing
#define HOMING_MODE FALSE			// set TRUE for power-on-homing
#define HOMING_RATE 500				// mm/min
#define HOMING_BACKOFF 10			// mm

#define X_HOMING_ENABLE 1			// 1=enabled for that axis
#define Y_HOMING_ENABLE 1
#define Z_HOMING_ENABLE 0
#define A_HOMING_ENABLE 0

/* machine profiles - chose one: */

//#define __LEADSCREW_20			// 1/4" 20 leadscrew table
#define __LEADSCREW_10				// 10 TPI leadscrew table
//#define __MAKERBOT				// Makerbot settings

// Profile for 1/4-20 hardware leadscrew machines
#ifdef __LEADSCREW_20
#define SEEK_STEPS 1000
#define FEED_STEPS 1000
#define TRAVEL_PER_REV 1.27
#endif

// Profile for 10 TPI  leadscrew machines
#ifdef __LEADSCREW_10
#define SEEK_STEPS 1000
#define FEED_STEPS 1000
#define TRAVEL_PER_REV 2.54
#endif

// Makerbot profile					// Note: POLARITY is [0,0,1,1]
#ifdef __MAKERBOT
#define SEEK_STEPS 500
#define FEED_STEPS 500
#define TRAVEL_PER_REV 33			// must set Z to 1.27 (or something)
#define HOMING_OFFSET -50
#endif

/*
 * DERIVED VALUES (from above) - shouldn't need changing but can be overtyped
 */

#define X_SEEK_WHOLE_STEPS_PER_SEC SEEK_STEPS // max whole steps per second for G0 motion
#define Y_SEEK_WHOLE_STEPS_PER_SEC SEEK_STEPS // (motor parameter)
#define Z_SEEK_WHOLE_STEPS_PER_SEC SEEK_STEPS
#define A_SEEK_WHOLE_STEPS_PER_SEC SEEK_STEPS

#define X_FEED_WHOLE_STEPS_PER_SEC FEED_STEPS // max whole steps per sec for feed motion
#define Y_FEED_WHOLE_STEPS_PER_SEC FEED_STEPS // (motor parameter)
#define Z_FEED_WHOLE_STEPS_PER_SEC FEED_STEPS
#define A_FEED_WHOLE_STEPS_PER_SEC FEED_STEPS

#define X_STEP_ANGLE STEP_ANGLE			// degrees per whole step
#define Y_STEP_ANGLE STEP_ANGLE 		// (motor parameter)
#define Z_STEP_ANGLE STEP_ANGLE
#define A_STEP_ANGLE STEP_ANGLE

#define X_MICROSTEP_MODE MICROSTEP_MODE	// microstep mode 
#define Y_MICROSTEP_MODE MICROSTEP_MODE	// (stepper driver configuration parameter)
#define Z_MICROSTEP_MODE MICROSTEP_MODE
#define A_MICROSTEP_MODE MICROSTEP_MODE

#define X_POLARITY 0					// motor direction polarity
#define Y_POLARITY 0
#define Z_POLARITY 0
#define A_POLARITY 1

#define X_POWER_MODE TRUE				// 1=low power idle enabled 
#define Y_POWER_MODE TRUE				// (robot parameter)
#define Z_POWER_MODE TRUE
#define A_POWER_MODE TRUE

#define X_LIMIT_MODE TRUE				// 1=limit switches present and enabled
#define Y_LIMIT_MODE TRUE				// (robot parameter)
#define Z_LIMIT_MODE TRUE
#define A_LIMIT_MODE FALSE

#define X_TRAVEL_PER_REV TRAVEL_PER_REV	// typ. set by leadscrews or cogwheels
#define Y_TRAVEL_PER_REV TRAVEL_PER_REV	// (robot parameter)
#define Z_TRAVEL_PER_REV TRAVEL_PER_REV
#define A_TRAVEL_PER_REV TRAVEL_PER_REV	// degrees moved per motor revolution

//#define X_TRAVEL_PER_REV 22.86		// typ. set by leadscrews or cogwheels
//#define Y_TRAVEL_PER_REV 48.768		// (robot parameter)
//#define Z_TRAVEL_PER_REV 2.54
//#define A_TRAVEL_PER_REV 2.54			// degrees moved per motor revolution

#define X_TRAVEL_MAX X_TRAVEL			// full excursion from min to max 
#define Y_TRAVEL_MAX Y_TRAVEL			// (robot parameter)
#define Z_TRAVEL_MAX Z_TRAVEL
#define A_TRAVEL_MAX -1					// -1 is no limit (typ for rotary axis)

#define X_TRAVEL_WARN X_TRAVEL			// full excursion from min to max 
#define Y_TRAVEL_WARN Y_TRAVEL
#define Z_TRAVEL_WARN Z_TRAVEL
#define A_TRAVEL_WARN -1				// -1 is no limit (typ for rotary axis)

#define X_HOMING_OFFSET -(X_TRAVEL/2) 	// offset to zero from axis minimum
#define Y_HOMING_OFFSET -(Y_TRAVEL/2)
#define Z_HOMING_OFFSET -(Z_TRAVEL/2)
#define A_HOMING_OFFSET 0

#define X_HOMING_RATE HOMING_RATE
#define Y_HOMING_RATE HOMING_RATE
#define Z_HOMING_RATE HOMING_RATE
#define A_HOMING_RATE HOMING_RATE

#define X_HOMING_BACKOFF HOMING_BACKOFF
#define Y_HOMING_BACKOFF HOMING_BACKOFF
#define Z_HOMING_BACKOFF HOMING_BACKOFF
#define A_HOMING_BACKOFF HOMING_BACKOFF

#endif

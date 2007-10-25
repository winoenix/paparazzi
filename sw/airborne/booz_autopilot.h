#ifndef BOOZ_AUTOPILOT_H
#define BOOZ_AUTOPILOT_H

#include "std.h"

#define BOOZ_AP_MODE_FAILSAFE 0
#define BOOZ_AP_MODE_RATE     1
#define BOOZ_AP_MODE_ATTITUDE 2
#define BOOZ_AP_MODE_NAV      3

extern uint8_t booz_autopilot_mode;

extern void booz_autopilot_init(void);
extern void booz_autopilot_periodic_task(void);
extern void booz_autopilot_event_task(void);

#define TRESHOLD_RATE_PPRZ (MIN_PPRZ / 2)
#define TRESHOLD_ATTITUDE_PPRZ  (MAX_PPRZ/2)
#define BOOZ_AP_MODE_OF_PPRZ(mode)				\
  ((mode) < TRESHOLD_RATE_PPRZ ? BOOZ_AP_MODE_RATE :		\
   (mode) < TRESHOLD_ATTITUDE_PPRZ ? BOOZ_AP_MODE_ATTITUDE :	\
   BOOZ_AP_MODE_ATTITUDE )

#endif /* BOOZ_AUTOPILOT_H */

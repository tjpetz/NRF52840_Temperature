// Read the internal temp of the NRF52840 SoC.

#define TEMP_BASE           (0x4000C000U)
#define TEMP_TASKS_START    (TEMP_BASE + 0x000U)
#define TEMP_TASKS_STOP     (TEMP_BASE + 0x004U)
#define TEMP_EVENTS_DATARDY (TEMP_BASE + 0x100U)
#define TEMP_INTENSET       (TEMP_BASE + 0x304U)
#define TEMP_INTENCLR       (TEMP_BASE + 0x308U)
#define TEMP_TEMP           (TEMP_BASE + 0x508U)

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  delay(3000);

  Serial.println("Beginning...");
}

void loop() {

  *(uint32_t *)TEMP_TASKS_START = 1;

  while (*(uint32_t *)TEMP_EVENTS_DATARDY == 0) {
    __WFE();    // need to wait for the event, an empty loop won't work
  }

  // Temperature is in units of 0.25c so divide by 4.
  Serial.print("Die Temp = "); Serial.println(*(int32_t *)TEMP_TEMP / 4.0);

  delay(3000);
}

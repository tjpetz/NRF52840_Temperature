A very simple example of reading the internal temperature sensor of the NRF52840 SoC.

Note, when waiting for the temperature event to be ready we need to free up the 
processor to execute the event.  We use __WFE() to wait for the event.  If we tried
to use an empty loop or do some dummy operation in the loop it doesn't seem to
free up the processor to be able to measure the temperature.  Alternately we can
delay() with in the loop but this takes more time, also __WFE() is more meaningful
because we're doing exactly what it says... Waiting For an Event.

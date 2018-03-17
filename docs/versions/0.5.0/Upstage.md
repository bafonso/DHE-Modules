<img style="padding-left: 10px" align="right" src="images/v0.6/upstage.png">

**Upstage** offers controls to enhance a chain of Stage modules.

See:
- [Upstage User Interface](#upstage-user-interface)
- How to build [[Single-Stage Envelopes]]
- How to build [[Multi-Stage Envelopes]]

## Upstage User Interface

### Level

Use these controls to supply a desired starting voltage
to a chain of Stage modules.

- **LEVEL (voltage):**
Upstage's unmodulated *OUT* voltage.
The range is 0 to 10 volts.

- **CV (level):**
A CV signal added to the *LEVEL* voltage
to produce the *OUT* voltage.

- **Range switch (UNI/BI):**
Selects whether the *LEVEL* knob's range is unipolar (0 to 10 volts)
or bipolar (-5 to 5 volts).

- **OUT (voltage):**
The sum of the *LEVEL* voltage
and the *CV* signal,
limited to the range 0–10 volts.

### Triggers

Use these controls to insert a manual trigger
into a stream of triggers from some other source.

Note that these controls have no effect
when Upstage is in [Waiting Mode](#waiting-mode).

- **TRIG (trigger in):**
An incoming trigger signal.
Upstage forwards this signal to the *TRIG*
(trigger out) port.

- **TRIG (button):**
While the *TRIG* button is pressed,
Upstage sends 10 volts
to the *TRIG* (trigger out) port.

- **TRIG (trigger out):**
Emits either the signal at the *TRIG* (trigger in) port
or the trigger signal produced by the *TRIG* button,
whichever is greater,
to a maximum of 10 volts.

### Waiting Mode

Use these controls to suppress triggers temporarily.

- **WAIT (gate):**
While the *WAIT* gate is high,
Upstage is in *Waiting* mode.

- **WAIT (button):**
While the *WAIT* button is pressed,
Upstage is in *Waiting* mode.

When Upstage is in *Waiting Mode*,
it sends 0 volts to *TRIG* (trigger out)
regardless of the state of
the *TRIG* (trigger in) port
and the *TRIG* button.
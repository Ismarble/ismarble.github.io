#region VEXcode Generated Robot Configuration
from vex import *
import urandom

# Brain should be defined by default
brain=Brain()

# Robot configuration code
motor_11 = Motor(Ports.PORT11, GearSetting.RATIO_18_1, False)
motor_20 = Motor(Ports.PORT20, GearSetting.RATIO_18_1, True)
light_a = Light(brain.three_wire_port.a)
light_b = Light(brain.three_wire_port.b)
light_c = Light(brain.three_wire_port.c)


# wait for rotation sensor to fully initialize
wait(30, MSEC)


def play_vexcode_sound(sound_name):
    # Helper to make playing sounds from the V5 in VEXcode easier and
    # keeps the code cleaner by making it clear what is happening.
    print("VEXPlaySound:" + sound_name)
    wait(5, MSEC)

# add a small delay to make sure we don't print in the middle of the REPL header
wait(200, MSEC)
# clear the console to make sure we don't have the REPL in the console
print("\033[2J")

#endregion VEXcode Generated Robot Configuration

vexcode_brain_precision = 0
vexcode_console_precision = 0
myVariable = 0
IntVar = 0
message1 = Event()
BattMonitorStart = Event()e 

def Init_seconds(Init_seconds__seconds):
    global myVariable, IntVar, message1, BattMonitorStart, vexcode_brain_precision, vexcode_console_precision
    for repeat_count in range(int(Init_seconds__seconds)):
        brain.screen.print("Initializing.")
        print("Initializing.", end="")
        brain.screen.clear_screen()
        print("\033[2J")
        wait(0.333333, SECONDS)
        brain.screen.print("Initializing..")
        print("Initializing..", end="")
        brain.screen.clear_screen()
        print("\033[2J")
        wait(0.333333, SECONDS)
        brain.screen.print("Initializing...")
        print("Initializing...", end="")
        brain.screen.clear_screen()
        print("\033[2J")
        wait(0.333333, SECONDS)
        wait(5, MSEC)

def when_started1():
    global myVariable, IntVar, message1, BattMonitorStart, vexcode_brain_precision, vexcode_console_precision
    brain.screen.set_font(FontType.PROP40)
    vexcode_brain_precision = 1
    vexcode_console_precision = 1
    IntVar = int(round(urandom.uniform(2.5, 3.5), 2))
    Init_seconds(IntVar)
    brain.screen.clear_screen()
    IntVar = 0
    brain.timer.clear()
    # After Int
    # a is green, c is red, b is yellow
    
    play_vexcode_sound("game over")
    brain.screen.set_font(FontType.MONO15)
    vexcode_brain_precision = 3
    vexcode_console_precision = 3
    brain.screen.print("Initialized")
    print("Initialized", end="")
    wait(2, SECONDS)
    BattMonitorStart.broadcast()
    motor_11.set_stopping(COAST)
    motor_11.set_velocity(10, PERCENT)
    motor_11.set_velocity(10, PERCENT)   
     motor_20.set_stopping(COAST)
    motor_11.spin(FORWARD)
    motor_20.spin(FORWARD)
    motor_11.set_velocity(50, PERCENT)
    motor_11.set_velocity(50, PERCENT)

# Used to find the format string for printing numbers with the
# desired number of decimal places
def print_to_console_number_format():
        precision = 0
        # Equivalent to setting precision to 'All Digits'
        if vexcode_console_precision is None:
                precision = 6
        else:
                precision = vexcode_console_precision

        return "{{:.{0}f}}".format(precision)
def onevent_BattMonitorStart_0():
    global myVariable, IntVar, message1, BattMonitorStart, vexcode_brain_precision, vexcode_console_precision
    while True:
        brain.screen.set_cursor(1, 1)
        brain.screen.set_cursor(1, 1)
        print(print_to_console_number_format().format(motor_11.velocity(RPM) * 2.5), end="")
        brain.screen.print(motor_11.velocity(RPM) * 2.5, precision=6 if vexcode_brain_precision is None else vexcode_brain_precision)
        brain.screen.set_cursor(1, 2)
        brain.screen.set_cursor(1, 2)
        print(print_to_console_number_format().format(motor_20.velocity(RPM) * 2.5), end="")
        brain.screen.print(motor_20.velocity(RPM) * 2.5, precision=6 if vexcode_brain_precision is None else vexcode_brain_precision)
        wait(5, MSEC)

# system event handlers
BattMonitorStart(onevent_BattMonitorStart_0)
# add 15ms delay to make sure events are registered correctly.
wait(15, MSEC)

when_started1()

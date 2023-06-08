// Define motor pins
#define MOTOR_LEFT_F 2   //Input1 Control pin for left motor, forward direction
#define MOTOR_LEFT_B 3   //Input2 Control pin for left motor, backward direction
#define MOTOR_RIGHT_F 4  //Input4 Control pin for right motor, forward direction
#define MOTOR_RIGHT_B 5  //Input3 Control pin for right motor, backward direction

// Define sensor pins
#define TRACKER_LEFT 7         // Input pin for left line tracker sensor
#define TRACKER_RIGHT 6        // Input pin for right line tracker sensor
#define MOTOR_STATE 8          // Input pin for reading motor state (on/off)
#define THROTTLE_IN A0         // Analog input pin for reading the throttle (speed control)
#define THROTTLE_OUT_LEFT 9    // PWM output pin for setting speed (speed control)
#define THROTTLE_OUT_RIGHT 10  // PWM output pin for setting speed (speed control)

// Define states
#define STOP 0     // Motors stopped
#define FORWARD 1  // Moving forward
#define REVERSE 2  // Moving backwards
#define LEFT 3     // Turning left
#define RIGHT 4    // Turning right

int state = STOP;  // Initialize the state of the robot as stopped

int speed;
int motorOn;
int lineLeft;
int lineRight;

void setup() {
  Serial.begin(115200);

  // Set motor pins as OUTPUTs
  pinMode(MOTOR_LEFT_F, OUTPUT);
  pinMode(MOTOR_LEFT_B, OUTPUT);
  pinMode(MOTOR_RIGHT_F, OUTPUT);
  pinMode(MOTOR_RIGHT_B, OUTPUT);
  pinMode(THROTTLE_OUT_LEFT, OUTPUT);
  pinMode(THROTTLE_OUT_RIGHT, OUTPUT);

  // Set sensor pins as INPUTs
  pinMode(TRACKER_RIGHT, INPUT);
  pinMode(TRACKER_LEFT, INPUT);
  pinMode(MOTOR_STATE, INPUT);
  pinMode(THROTTLE_IN, INPUT);
  Serial.println("Alive");
}

/*
 * goForward checks if line is detected by either sensor.
 * If line is detected by left sensor, it returns RIGHT. 
 * If line is detected by right sensor, it returns LEFT.
 * If the line is detected by both sensors, it returns STOP.
 * Otherwise, it powers both motors to move forward and returns FORWARD.
 */
int goForward(int lineLeft, int lineRight) {
  if (lineLeft && lineRight) return STOP;
  if (lineLeft) return RIGHT;
  if (lineRight) return LEFT;

  digitalWrite(MOTOR_LEFT_F, HIGH);
  digitalWrite(MOTOR_LEFT_B, LOW);
  digitalWrite(MOTOR_RIGHT_F, HIGH);
  digitalWrite(MOTOR_RIGHT_B, LOW);
  return FORWARD;
}

/*
 * goBackward powers the motors in opposite direction.
 * If the line is not detected by either sensor, it returns FORWARD.
 * If the line is detected by either sensor, it returns appropriate turn.
 */
int goBackward(int lineLeft, int lineRight) {
  if (!lineLeft && !lineRight) return FORWARD;
  if (lineLeft) return RIGHT;
  if (lineRight) return LEFT;

  digitalWrite(MOTOR_LEFT_B, HIGH);
  digitalWrite(MOTOR_LEFT_F, LOW);
  digitalWrite(MOTOR_RIGHT_B, HIGH);
  digitalWrite(MOTOR_RIGHT_F, LOW);
  return REVERSE;
}

/*
 * turnLeft turns the robot to the left until it finds the line.
 * If the line is not detected by either sensor, it returns FORWARD.
 * If the line is detected by both sensors, it returns STOP.
 * If the line is detected by left sensor, it returns RIGHT.
 */
int turnLeft(int lineLeft, int lineRight) {
  if (!lineLeft && !lineRight) return FORWARD;
  if (lineLeft && lineRight) return STOP;
  if (lineLeft) return RIGHT;

  digitalWrite(MOTOR_LEFT_B, HIGH);
  digitalWrite(MOTOR_LEFT_F, LOW);
  digitalWrite(MOTOR_RIGHT_F, HIGH);
  digitalWrite(MOTOR_RIGHT_B, LOW);
  return LEFT;
}

/*
 * turnRight turns the robot to the right.
 * If the line is not detected by either sensor, it returns FORWARD.
 * If the line is detected by both sensors, it returns STOP.
 * If the line is detected by right sensor, it returns LEFT.
 */
int turnRight(int lineLeft, int lineRight) {
  if (!lineLeft && !lineRight) return FORWARD;
  if (lineLeft && lineRight) return STOP;
  if (lineRight) return LEFT;

  digitalWrite(MOTOR_LEFT_F, HIGH);
  digitalWrite(MOTOR_LEFT_B, LOW);
  digitalWrite(MOTOR_RIGHT_B, HIGH);
  digitalWrite(MOTOR_RIGHT_F, LOW);
  return RIGHT;
}

/*
 * stop function stops the movement of the robot by turning off both motors
 * If the line is not detected by either sensor, it returns FORWARD.
 * If the line is detected by either sensor, it returns appropriate turn.
 * If the line is detected by both sensors, it returns STOP.
 */
int stop(int lineLeft, int lineRight) {
  if (!lineLeft && !lineRight) return FORWARD;
  if (lineRight) return LEFT;
  if (lineLeft) return RIGHT;
  digitalWrite(MOTOR_LEFT_F, LOW);
  digitalWrite(MOTOR_LEFT_B, LOW);
  digitalWrite(MOTOR_RIGHT_F, LOW);
  digitalWrite(MOTOR_RIGHT_B, LOW);
  return STOP;
}

// setSpeed sets both motors to the same speed
void setSpeed(int speed) {
  analogWrite(THROTTLE_OUT_LEFT, speed);
  analogWrite(THROTTLE_OUT_RIGHT, speed);
}

/*
 * loop function runs continuously after the setup function has completed.
 * It controls the movement of the robot.
 * It reads the state of the motors, the line tracker sensors, and the throttle, 
 * and updates the state of the robot accordingly.
 */
void loop() {
  /*motorOn = digitalRead(MOTOR_STATE);
  digitalWrite(LED_BUILTIN, motorOn);
  if (!motorOn){
    state = stop(lineLeft, lineRight);
    setSpeed(0);
    Serial.println(-1);
    return;
  }*/

  lineLeft = digitalRead(TRACKER_LEFT);
  lineRight = digitalRead(TRACKER_RIGHT);
  Serial.println(lineLeft +  " :  " + lineRight);
  /*
  // THROTTLE is an analog input, so use analogRead() instead of digitalRead()
  //speed = analogRead(THROTTLE_IN);
  //speed = map(speed, 0, 1024, 0, 255);
  speed = 200;
  setSpeed(speed);
  Serial.println(state);
  switch(state){
    case FORWARD:
    state = goForward(lineLeft, lineRight);
    break;
    case LEFT:
    state = turnLeft(lineLeft, lineRight);
    break;
    case RIGHT:
    state = turnRight(lineLeft, lineRight);
    break;
    case REVERSE:
    state = goBackward(lineLeft, lineRight);
    break;
    default:
    state = stop(lineLeft, lineRight);
    break;
  }
  // If the robot is stopped, it doesn't move.
  // (You don't seem to have a 'stop' function, so this will cause an error.)*/
}
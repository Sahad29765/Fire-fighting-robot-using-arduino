Fire-Fighting Robot using Arduino 🚒
This project is a line-following fire-fighting robot built with Arduino UNO, designed to detect fire and automatically extinguish it using a water pump and servo-based spraying system. It utilizes IR sensors for navigation and detects flames based on sensor input patterns.

🧠 Key Features
🔍 Line Following: Follows a black line using 3 IR sensors (left, middle, right).

🔥 Fire Detection: Identifies direction of fire (left, center, right) using sensor logic.

🚗 Autonomous Navigation: Adjusts movement based on fire direction using 4 DC motors.

💦 Water Spraying System: Sprays water in the direction of fire using a servo-controlled nozzle and water pump.

🛑 Automatic Stopping: Stops and resets when no fire is detected.

⚙️ Components Used
Component	Quantity
Arduino UNO	1
IR Sensors	3
Servo Motor	1
Water Pump (DC)	1
Motor Driver (L298N or similar)	1
DC Motors	4
Chassis & Wheels	1 set
Wires, Breadboard	As needed

🔌 Pin Configuration
Component	Arduino Pin
Left Sensor	D8
Middle Sensor	D9
Right Sensor	D10
Motor 1	D4
Motor 2	D5
Motor 3	D6
Motor 4	D7
Servo Motor	D11
Water Pump	D12

🧾 How It Works
Sensors Read Fire Position:

If the middle sensor detects fire → move forward and spray center.

If the left sensor detects fire → turn left, move, and spray left.

If the right sensor detects fire → turn right, move, and spray right.

If no sensor detects anything → stop and center the servo.

Water Spraying Mechanism:

Activates the water pump.

Moves the servo left and right around the target angle (±30°) to cover area.

Resets to center position.

Navigation:

Uses combinations of motor directions to move, turn, and stop the robot.
